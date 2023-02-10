/*

Copyright 2022-2023, Aechelon Technology, Inc.

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

#pragma once

#include <optional.hpp>

#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace NASR
{

namespace CSV
{

// ----------------------------------------------------------------------------

class IParsable
{
public:
    virtual void parse(const std::string& text) = 0;
};

// ----------------------------------------------------------------------------

namespace Utils
{

bool ParseBool(const std::string& data);

template <typename T, std::enable_if_t<std::is_same<int, T>::value, bool> = true>
T ParseNumber(const std::string& data)
{
    return std::stoi(data);
}

template <typename T, std::enable_if_t<std::is_same<long, T>::value, bool> = true>
T ParseNumber(const std::string& data)
{
    return std::stol(data);
}

template <typename T, std::enable_if_t<std::is_same<long long, T>::value, bool> = true>
T ParseNumber(const std::string& data)
{
    return std::stoll(data);
}

template <typename T, std::enable_if_t<std::is_same<double, T>::value, bool> = true>
T ParseNumber(const std::string& data)
{
    return std::stod(data);
}

template <typename T, std::enable_if_t<std::is_same<float, T>::value, bool> = true>
T ParseNumber(const std::string& data)
{
    return std::stof(data);
}

template <typename T, std::enable_if_t<std::is_same<long double, T>::value, bool> = true>
T ParseNumber(const std::string& data)
{
    return std::stold(data);
}

template <typename T, std::enable_if_t<std::is_same<bool, T>::value, bool> = true>
T Parse(const std::string& data)
{
    return ParseBool(data);
}

template <typename T, std::enable_if_t<std::is_same<char, T>::value, bool> = true>
T Parse(const std::string& data)
{
    return data.at(0);
}

template <typename T, std::enable_if_t<std::is_arithmetic<T>::value && !std::is_same<bool, T>::value && !std::is_same<char, T>::value, bool> = true>
T Parse(const std::string& data)
{
    return ParseNumber<T>(data);
}

template <typename T, std::enable_if_t<std::is_base_of<IParsable, T>::value, bool> = true>
T Parse(const std::string& data)
{
    T instance;
    instance.parse(data);
    return instance;
}

} // namespace Utils

// ----------------------------------------------------------------------------

enum class ParsableEnumOutcome
{
    VALID,
    UNKNOWN,
    MISSING
};

// ----------------------------------------------------------------------------

template <typename TEnum, const std::unordered_map<std::string, TEnum>& Lookup, TEnum DefaultValue = 0>
class ParsableEnum : public NASR::CSV::IParsable
{
public:
    ParsableEnum() : _data(DefaultValue), _outcome(ParsableEnumOutcome::MISSING) {}

    ParsableEnum(const std::string& value)
    {
        parse(value);
    }

    virtual void parse(const std::string& value) override
    {
        std::_List_const_iterator<std::_List_val<std::_List_simple_types<std::pair<std::string const, TEnum>>>> search = Lookup.find(value);
        if (search != Lookup.end())
        {
            _data = search->second;
            _outcome = ParsableEnumOutcome::VALID;
        }
        else
        {
            _data = static_cast<TEnum>(DefaultValue);
            _outcome = value.empty() ? ParsableEnumOutcome::MISSING : ParsableEnumOutcome::UNKNOWN;
        }
    }

    tl::optional<TEnum> asOptional() const
    {
        switch (_outcome)
        {
        case ParsableEnumOutcome::VALID:
        case ParsableEnumOutcome::UNKNOWN:
            return _data;
        case ParsableEnumOutcome::MISSING:
        default:
            return tl::nullopt;
        }
    }

    TEnum value() const
    {
        return _data;
    }
private:
    ParsableEnumOutcome _outcome;
    TEnum _data;
};

// ----------------------------------------------------------------------------

class Header
{
public:
    typedef std::shared_ptr<Header> Ptr;

    Header(const std::vector<std::string>& data);

    size_t getIndex(const std::string& name) const;
    size_t length() const;

private:
    std::vector<std::string> _data;
    std::unordered_map<std::string, size_t> _lookup;
};

// ----------------------------------------------------------------------------

class Column
{
public:
    Column(const std::vector<std::string>& data);

    std::vector<size_t> where(const std::string& value) const;
    const std::vector<std::string>& get() const;

private:
    std::vector<std::string> _data;
};

// ----------------------------------------------------------------------------

class Row
{
public:
    Row(const std::vector<std::string>& data, Header::Ptr header);

    // returns raw string data
    const std::string& get(size_t index) const;
    const std::string& get(const std::string& columnName) const;
    const std::string& operator[](size_t index) const { return get(index); }
    const std::string& operator[](const std::string& columnName) const { return get(columnName); }

    template <typename T>
    T get(size_t index) const
    {
        return Utils::Parse<T>(_data[index]);
    }

    template <typename T>
    T get(const std::string& columnName) const
    {
        return get<T>(_header->getIndex(columnName));
    }

    template <typename T>
    tl::optional<T> getOptional(size_t index) const
    {
        try
        {
            return Utils::Parse<T>(_data[index]);
        }
        catch (const std::invalid_argument&)
        {
            return tl::nullopt;
        }
        catch (const std::out_of_range&)
        {
            return tl::nullopt;
        }
        return tl::nullopt;
    }

    template <typename T>
    tl::optional<T> getOptional(const std::string& columnName) const
    {
        return getOptional<T>(_header->getIndex(columnName));
    }

    template <typename T>
    std::vector<T> getValues(size_t index) const
    {
        std::vector<T> out;
        for (std::string& item : split(_data[index]))
        {
            out.push_back(Utils::Parse<T>(item));
        }
        return out;
    }

    template <typename T>
    std::vector<T> getValues(const std::string& columnName) const
    {
        return getValues<T>(_header->getIndex(columnName));
    }

    template <typename TEnum, typename TParsableEnum>
    std::vector<TEnum> getValues(size_t index) const
    {
        std::vector<TEnum> out;
        for (std::string& item : split(_data[index]))
        {
            out.push_back(Utils::Parse<TParsableEnum>(item).value());
        }
        return out;
    }

    template <typename TEnum, typename TParsableEnum>
    std::vector<TEnum> getValues(const std::string& columnName) const
    {
        return getValues<TEnum, TParsableEnum>(_header->getIndex(columnName));
    }

private:
    std::vector<std::string> split(const std::string& text) const;

private:
    std::vector<std::string> _data;
    Header::Ptr _header;
};

// ----------------------------------------------------------------------------

class File
{
public:
    File();
    File(const std::string& filename);

    bool isValid() const;
    const std::string& getFilename() const;

    Column getColumn(const std::string& name) const;
    Row getRow(size_t index) const;
    std::vector<Row> getRows(const std::vector<size_t>& indices) const;

    Column operator[](const std::string& columnName) const { return getColumn(columnName); }
    Row operator[](size_t index) const { return getRow(index); }

private:
    bool parseFile(const std::string& name);
    std::vector<std::string> parseLine(const std::string& line, size_t sizeHint = 0) const;

private:
    bool _valid;
    Header::Ptr _header;
    std::vector<std::vector<std::string>> _rows;
    std::string _filename;
};

// ----------------------------------------------------------------------------

} // namespace CSV

} // namespace NASR

