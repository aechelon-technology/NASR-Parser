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

#include "glideslopeEntry.h"

namespace NASR
{

// ----------------------------------------------------------------------------

namespace ILS
{

// ----------------------------------------------------------------------------

const std::string &GlideslopeEntry::getComponentStatus() const
{
    return _data["COMPONENT_STATUS"];
}

// ----------------------------------------------------------------------------

Data::Date GlideslopeEntry::getComponentStatusDate() const
{
    return _data["COMPONENT_STATUS_DATE"];
}

// ----------------------------------------------------------------------------

int GlideslopeEntry::getLatDeg() const
{
    return _data.get<int>("LAT_DEG");
}

// ----------------------------------------------------------------------------

int GlideslopeEntry::getLatMin() const
{
    return _data.get<int>("LAT_MIN");
}

// ----------------------------------------------------------------------------

double GlideslopeEntry::getLatSec() const
{
    return _data.get<double>("LAT_SEC");
}

// ----------------------------------------------------------------------------

char GlideslopeEntry::getLatHemis() const
{
    return _data.get<char>("LAT_HEMIS");
}

// ----------------------------------------------------------------------------

double GlideslopeEntry::getLatDecimal() const
{
    return _data.get<double>("LAT_DECIMAL");
}

// ----------------------------------------------------------------------------

int GlideslopeEntry::getLongDeg() const
{
    return _data.get<int>("LONG_DEG");
}

// ----------------------------------------------------------------------------

int GlideslopeEntry::getLongMin() const
{
    return _data.get<int>("LONG_MIN");
}

// ----------------------------------------------------------------------------

double GlideslopeEntry::getLongSec() const
{
    return _data.get<double>("LONG_SEC");
}

// ----------------------------------------------------------------------------

char GlideslopeEntry::getLongHemis() const
{
    return _data.get<char>("LONG_HEMIS");
}

// ----------------------------------------------------------------------------

double GlideslopeEntry::getLongDecimal() const
{
    return _data.get<double>("LONG_DECIMAL");
}

// ----------------------------------------------------------------------------

SourceCode GlideslopeEntry::getLatLongSourceCode() const
{
    return _data.get<ParsableSourceCode>("LAT_LONG_SOURCE_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<int> GlideslopeEntry::getDistFrmAer() const
{
    return _data.getOptional<int>("DIST_FRM_AER");
}

// ----------------------------------------------------------------------------

tl::optional<int> GlideslopeEntry::getDistFrmCntrLine() const
{
    return _data.getOptional<int>("DIST_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

tl::optional<char> GlideslopeEntry::getDirFrmCntrLine() const
{
    return _data.getOptional<char>("DIR_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

SourceCode GlideslopeEntry::getDistDirSourceCode() const
{
    return _data.get<ParsableSourceCode>("DIST_DIR_SOURCE_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<double> GlideslopeEntry::getSiteElevation() const
{
    return _data.getOptional<double>("SITE_ELEVATION");
}

// ----------------------------------------------------------------------------

GlideslopeType GlideslopeEntry::getGSTypeCode() const
{
    return _data.get<ParsableGlideslopeType>("G_S_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

double GlideslopeEntry::getGSAngle() const
{
    return _data.get<double>("G_S_ANGLE");
}

// ----------------------------------------------------------------------------

double GlideslopeEntry::getGSFreq() const
{
    return _data.get<double>("G_S_FREQ");
}

// ----------------------------------------------------------------------------

tl::optional<double> GlideslopeEntry::getRwyElevAdjGS() const
{
    return _data.getOptional<double>("RWY_ELEV_ADJ_G_S");
}

// ----------------------------------------------------------------------------

} // namespace ILS

// ----------------------------------------------------------------------------

} // namespace NASR