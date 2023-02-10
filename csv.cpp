/*

Copyright 2022 Aechelon Technology, Inc.

Redistribution and use in source and binary forms, with or without modification
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "csv.h"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace NASR
{

namespace CSV
{

//-----------------------------------------------------------------------------

// adapted from https://stackoverflow.com/a/217605
void Clean(std::string &s, bool makeUppercase = false)
{
    // remove leading whitespace and quotes
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char c)
    {
        return !std::isspace(c) && c != '"';
    }));

    // remove trailing whitespace and quotes
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char c)
    {
        return !std::isspace(c) && c != '"';
    }).base(), s.end());

    // make uppercase if requested
    if (makeUppercase)
    {
        std::transform(s.begin(), s.end(), s.begin(), std::toupper);
    }
}

// ----------------------------------------------------------------------------

bool Utils::ParseBool(const std::string &data)
{
    static const std::unordered_map<std::string, bool> Lookup
    {
        { "TRUE", true },
        { "T", true },
        { "YES", true },
        { "Y", true },
        { "FALSE", false },
        { "F", false },
        { "NO", false },
        { "N", false }
    };

    std::string cleaned(data);
    Clean(cleaned, true);

    return Lookup.at(cleaned);
}

// ----------------------------------------------------------------------------

Header::Header(const std::vector<std::string> &data) : _data(data)
{
    for (size_t i = 0; i < _data.size(); i++)
    {
        std::string &item = _data[i];
        Clean(item);
        _lookup.insert({ item, i });
    }
}

// ----------------------------------------------------------------------------

size_t Header::length() const
{
    return _data.size();
}

// ----------------------------------------------------------------------------

size_t Header::getIndex(const std::string &name) const
{
    return _lookup.at(name);
}

// ----------------------------------------------------------------------------

Column::Column(const std::vector<std::string> &data) : _data(data)
{
    for (std::string &item : _data)
    {
        Clean(item);
    }
}

// ----------------------------------------------------------------------------

std::vector<size_t> Column::where(const std::string &value) const
{
    std::vector<size_t> out;
    std::vector<std::string>::const_iterator it = std::find(_data.begin(), _data.end(), value);
    while (it != _data.end())
    {
        out.push_back(std::distance(_data.begin(), it));
        it = std::find(it + 1, _data.end(), value);
    }
    return out;
}

// ----------------------------------------------------------------------------

const std::vector<std::string> &Column::get() const
{
    return _data;
}

// ----------------------------------------------------------------------------

Row::Row(const std::vector<std::string> &data, Header::Ptr header) : _data(data), _header(header)
{
    for (std::string &item : _data)
    {
        Clean(item);
    }
}

// ----------------------------------------------------------------------------

std::vector<std::string> Row::split(const std::string &text) const
{
    std::vector<std::string> out;
    std::istringstream input(text);
    std::string element;
    while (std::getline(input, element, ','))
    {
        out.push_back(element);
    }
    return out;
}

// ----------------------------------------------------------------------------

const std::string &Row::get(size_t index) const
{
    return _data[index];
}

// ----------------------------------------------------------------------------

const std::string &Row::get(const std::string &columnName) const
{
    return _data[_header->getIndex(columnName)];
}

// ----------------------------------------------------------------------------

File::File() : _valid(false)
{
}

// ----------------------------------------------------------------------------

File::File(const std::string &filename)
{
    parseFile(filename);
}

// ----------------------------------------------------------------------------

bool File::isValid() const
{
    return _valid;
}

// ----------------------------------------------------------------------------

const std::string &File::getFilename() const
{
    return _filename;
}

// ----------------------------------------------------------------------------

bool File::parseFile(const std::string &filename)
{
    _filename = filename;
    _rows.clear();
    _valid = false;

    std::ifstream istrm(filename);

    if (!istrm.is_open())
    {
        return _valid;
    }

    size_t lineNumber = 0;
    std::string line;
    size_t headerSize = 0;
    while (std::getline(istrm, line))
    {
        lineNumber++;
        if (lineNumber == 1)
        {
            // use this as header
            _header = std::make_shared<Header>(parseLine(line));
            headerSize = _header->length();
            _valid = true;
        }
        else
        {
            std::vector<std::string> items = parseLine(line, headerSize);
            if (items.size() != headerSize)
            {
                // skip lines where the size doesn't match
                continue;
            }
            _rows.emplace_back(std::move(items));
        }
    }

    return _valid;
}

// ----------------------------------------------------------------------------

Column File::getColumn(const std::string &name) const
{
    std::vector<std::string> out;
    out.reserve(_rows.size());

    size_t index = _header->getIndex(name);
    for (const std::vector<std::string> &row : _rows)
    {
        out.push_back(row[index]);
    }

    return out;
}

// ----------------------------------------------------------------------------

Row File::getRow(size_t index) const
{
    return Row(_rows[index], _header);
}

// ----------------------------------------------------------------------------

std::vector<Row> File::getRows(const std::vector<size_t> &indices) const
{
    std::vector<Row> out;
    out.reserve(indices.size());
    for (size_t index : indices)
    {
        out.push_back(getRow(index));
    }
    return out;
}

// ----------------------------------------------------------------------------

std::vector<std::string> File::parseLine(const std::string &line, size_t sizeHint) const
{
    std::vector<std::string> items;
    if (sizeHint != 0)
    {
        items.reserve(sizeHint);
    }

    std::string::const_iterator start = line.begin();
    char previous = '\0';
    bool inQuotedSection = false;
    for (std::string::const_iterator it = line.begin(); it != line.end(); ++it)
    {
        const char c = *it;
        const bool escaped = previous == '\\';
        if (c == '"' && !escaped)
        {
            inQuotedSection = !inQuotedSection;
        }
        if (c == ',' && !escaped && !inQuotedSection)
        {
            items.emplace_back(std::string(start, it));
            start = it + 1;
        }
        previous = c;
    }

    return items;
}

// ----------------------------------------------------------------------------

} // namespace CSV

} // namespace NASR