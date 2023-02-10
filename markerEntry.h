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

#pragma once

#include "csv.h"
#include "data.h"

#include <string>
#include <unordered_map>

namespace NASR
{

// ----------------------------------------------------------------------------

namespace ILS
{

// ----------------------------------------------------------------------------

enum class MarkerType
{
    INNER_MARKER,
    MIDDLE_MARKER,
    OUTER_MARKER,
    UNKNOWN
};

const std::unordered_map<std::string, MarkerType> MarkerTypeLookup
{
    { "IM", MarkerType::INNER_MARKER },
    { "MM", MarkerType::MIDDLE_MARKER },
    { "OM", MarkerType::OUTER_MARKER }
};

typedef CSV::ParsableEnum<MarkerType, MarkerTypeLookup, MarkerType::UNKNOWN> ParsableMarkerType;

// ----------------------------------------------------------------------------

class MarkerEntry : public Data::ILSData
{
public:
    MarkerEntry(const CSV::Row& row) : Data::ILSData(row) {}

    MarkerType getIlsCompTypeCode() const;
    const std::string& getComponentStatus() const;
    Data::Date getComponentStatusDate() const;
    int getLatDeg() const;
    int getLatMin() const;
    double getLatSec() const;
    bool getLatHemis() const;
    double getLatDecimal() const;
    int getLongDeg() const;
    int getLongMin() const;
    double getLongSec() const;
    char getLongHemis() const;
    double getLongDecimal() const;
    SourceCode getLatLongSourceCode() const;
    tl::optional<int> getDistFrmAer() const;
    tl::optional<int> getDistFrmCntrLine() const;
    tl::optional<char> getDirFrmCntrLine() const;
    tl::optional<SourceCode> getDistDirSourceCode() const;
    tl::optional<double> getSiteElevation() const;
    const std::string& getMkrFacTypeCode() const; // enum, but doesn't match documentation
    const std::string& getMarkerIdBeacon() const;
    const std::string& getCompassLocatorName() const;
    tl::optional<int> getFreq() const;
    const std::string& getNavId() const;
    const std::string& getNavType() const;
    const std::string& getLowPoweredNdbStatus() const;
    const std::string& getService() const;
};

// ----------------------------------------------------------------------------

} // namespace ILS

// ----------------------------------------------------------------------------

} // namespace NASR