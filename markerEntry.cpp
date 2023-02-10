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

#include "markerEntry.h"

namespace NASR
{

// ----------------------------------------------------------------------------

namespace ILS
{

// ----------------------------------------------------------------------------


MarkerType MarkerEntry::getIlsCompTypeCode() const
{
    return _data.get<ParsableMarkerType>("ILS_COMP_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getComponentStatus() const
{
    return _data["COMPONENT_STATUS"];
}

// ----------------------------------------------------------------------------

Data::Date MarkerEntry::getComponentStatusDate() const
{
    return _data["COMPONENT_STATUS_DATE"];
}

// ----------------------------------------------------------------------------

int MarkerEntry::getLatDeg() const
{
    return _data.get<int>("LAT_DEG");
}

// ----------------------------------------------------------------------------

int MarkerEntry::getLatMin() const
{
    return _data.get<int>("LAT_MIN");
}

// ----------------------------------------------------------------------------

double MarkerEntry::getLatSec() const
{
    return _data.get<double>("LAT_SEC");
}

// ----------------------------------------------------------------------------

bool MarkerEntry::getLatHemis() const
{
    return _data.get<bool>("LAT_HEMIS");
}

// ----------------------------------------------------------------------------

double MarkerEntry::getLatDecimal() const
{
    return _data.get<double>("LAT_DECIMAL");
}

// ----------------------------------------------------------------------------

int MarkerEntry::getLongDeg() const
{
    return _data.get<int>("LONG_DEG");
}

// ----------------------------------------------------------------------------

int MarkerEntry::getLongMin() const
{
    return _data.get<int>("LONG_MIN");
}

// ----------------------------------------------------------------------------

double MarkerEntry::getLongSec() const
{
    return _data.get<double>("LONG_SEC");
}

// ----------------------------------------------------------------------------

char MarkerEntry::getLongHemis() const
{
    return _data.get<char>("LONG_HEMIS");
}

// ----------------------------------------------------------------------------

double MarkerEntry::getLongDecimal() const
{
    return _data.get<double>("LONG_DECIMAL");
}

// ----------------------------------------------------------------------------

SourceCode MarkerEntry::getLatLongSourceCode() const
{
    return _data.get<ParsableSourceCode>("LAT_LONG_SOURCE_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<int> MarkerEntry::getDistFrmAer() const
{
    return _data.getOptional<int>("DIST_FRM_AER");
}

// ----------------------------------------------------------------------------

tl::optional<int> MarkerEntry::getDistFrmCntrLine() const
{
    return _data.getOptional<int>("DIST_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

tl::optional<char> MarkerEntry::getDirFrmCntrLine() const
{
    return _data.getOptional<char>("DIR_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

tl::optional<SourceCode> MarkerEntry::getDistDirSourceCode() const
{
    return _data.get<ParsableSourceCode>("DIST_DIR_SOURCE_CODE").asOptional();
}

// ----------------------------------------------------------------------------

tl::optional<double> MarkerEntry::getSiteElevation() const
{
    return _data.getOptional<double>("SITE_ELEVATION");
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getMkrFacTypeCode() const
{
    return _data["MKR_FAC_TYPE_CODE"];
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getMarkerIdBeacon() const
{
    return _data["MARKER_ID_BEACON"];
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getCompassLocatorName() const
{
    return _data["COMPASS_LOCATOR_NAME"];
}

// ----------------------------------------------------------------------------

tl::optional<int> MarkerEntry::getFreq() const
{
    return _data.getOptional<int>("FREQ");
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getNavId() const
{
    return _data["NAV_ID"];
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getNavType() const
{
    return _data["NAV_TYPE"];
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getLowPoweredNdbStatus() const
{
    return _data["LOW_POWERED_NDB_STATUS"];
}

// ----------------------------------------------------------------------------

const std::string &MarkerEntry::getService() const
{
    return _data["SERVICE"];
}

// ----------------------------------------------------------------------------

} // namespace ILS

// ----------------------------------------------------------------------------

} // namespace NASR