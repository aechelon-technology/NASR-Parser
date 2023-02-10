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

enum class GlideslopeType
{
    GLIDESLOPE,
    GLIDESLOPE_WITH_DME,
    UNKNOWN
};

const std::unordered_map<std::string, GlideslopeType> GlideslopeTypeLookup
{
    { "GS", GlideslopeType::GLIDESLOPE },
    { "GD", GlideslopeType::GLIDESLOPE_WITH_DME }
};

typedef CSV::ParsableEnum<GlideslopeType, GlideslopeTypeLookup, GlideslopeType::UNKNOWN> ParsableGlideslopeType;

// ----------------------------------------------------------------------------

class GlideslopeEntry : public Data::ILSData
{
public:
    GlideslopeEntry(const CSV::Row& row) : Data::ILSData(row) {}

    const std::string& getComponentStatus() const;
    Data::Date getComponentStatusDate() const;
    int getLatDeg() const;
    int getLatMin() const;
    double getLatSec() const;
    char getLatHemis() const;
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
    SourceCode getDistDirSourceCode() const;
    tl::optional<double> getSiteElevation() const;
    GlideslopeType getGSTypeCode() const;
    double getGSAngle() const;
    double getGSFreq() const;
    tl::optional<double> getRwyElevAdjGS() const;
};

// ----------------------------------------------------------------------------

} // namespace ILS

// ----------------------------------------------------------------------------

} // namespace NASR