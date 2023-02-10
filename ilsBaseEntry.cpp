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

#include "ilsBaseEntry.h"

namespace NASR
{

// ----------------------------------------------------------------------------

namespace ILS
{

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getStateName() const
{
    return _data["STATE_NAME"];
}

// ----------------------------------------------------------------------------

Data::FAARegion BaseEntry::getRegionCode() const
{
    return _data.get<Data::ParsableFAARegionCode>("REGION_CODE").value();
}

// ----------------------------------------------------------------------------

int BaseEntry::getRwyLen() const
{
    return _data.get<int>("RWY_LEN");
}

// ----------------------------------------------------------------------------

int BaseEntry::getRwyWidth() const
{
    return _data.get<int>("RWY_WIDTH");
}

// ----------------------------------------------------------------------------

Category BaseEntry::getCategory() const
{
    return _data.get<ParsableCategory>("CATEGORY").value();
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getOwnerName() const
{
    return _data["OWNER_NAME"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getOprName() const
{
    return _data["OPR_NAME"];
}

// ----------------------------------------------------------------------------

double BaseEntry::getApchBear() const
{
    return _data.get<double>("APCH_BEAR");
}

// ----------------------------------------------------------------------------

int BaseEntry::getMagVar() const
{
    return _data.get<int>("MAG_VAR");
}

// ----------------------------------------------------------------------------

char BaseEntry::getMagVarHemis() const
{
    return _data.get<char>("MAG_VAR_HEMIS");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getComponentStatus() const
{
    return _data["COMPONENT_STATUS"];
}

// ----------------------------------------------------------------------------

Data::Date BaseEntry::getComponentStatusDate() const
{
    return _data["COMPONENT_STATUS_DATE"];
}

// ----------------------------------------------------------------------------

int BaseEntry::getLatDeg() const
{
    return _data.get<int>("LAT_DEG");
}

// ----------------------------------------------------------------------------

int BaseEntry::getLatMin() const
{
    return _data.get<int>("LAT_MIN");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLatSec() const
{
    return _data.get<double>("LAT_SEC");
}

// ----------------------------------------------------------------------------

char BaseEntry::getLatHemis() const
{
    return _data.get<char>("LAT_HEMIS");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLatDecimal() const
{
    return _data.get<double>("LAT_DECIMAL");
}

// ----------------------------------------------------------------------------

int BaseEntry::getLongDeg() const
{
    return _data.get<int>("LONG_DEG");
}

// ----------------------------------------------------------------------------

int BaseEntry::getLongMin() const
{
    return _data.get<int>("LONG_MIN");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLongSec() const
{
    return _data.get<double>("LONG_SEC");
}

// ----------------------------------------------------------------------------

char BaseEntry::getLongHemis() const
{
    return _data.get<char>("LONG_HEMIS");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLongDecimal() const
{
    return _data.get<double>("LONG_DECIMAL");
}

// ----------------------------------------------------------------------------

SourceCode BaseEntry::getLatLongSourceCode() const
{
    return _data.get<ParsableSourceCode>("LAT_LONG_SOURCE_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getDistFrmAer() const
{
    return _data.getOptional<int>("DIST_FRM_AER");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getDistFrmCntrLine() const
{
    return _data.getOptional<int>("DIST_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

tl::optional<char> BaseEntry::getDirFrmCntrLine() const
{
    return _data.getOptional<char>("DIR_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

SourceCode BaseEntry::getDistDirSourceCode() const
{
    return _data.get<ParsableSourceCode>("DIST_DIR_SOURCE_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<double> BaseEntry::getSiteElevation() const
{
    return _data.getOptional<double>("SITE_ELEVATION");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLocalizerFrequency() const
{
    return _data.get<double>("LOC_FREQ");
}

// ----------------------------------------------------------------------------

tl::optional<char> BaseEntry::getBackCourseStatusCode() const
{
    return _data.getOptional<char>("BK_COURSE_STATUS_CODE");
}

// ----------------------------------------------------------------------------

tl::optional<double> BaseEntry::getCrsWidth() const
{
    return _data.getOptional<double>("CRS_WIDTH");
}

// ----------------------------------------------------------------------------

tl::optional<double> BaseEntry::getCrsWidthAtThresh() const
{
    return _data.getOptional<double>("CRS_WIDTH_AT_THRESH");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getDistFrmRwyStop() const
{
    return _data.getOptional<int>("DIST_FRM_RWY_STOP");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getDirFrmRwyStop() const
{
    return _data["DIR_FRM_RWY_STOP"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getLocalizerServicesCode() const
{
    return _data["LOC_SERVICES_CODE"];
}

// ----------------------------------------------------------------------------

} // namespace ILS

// ----------------------------------------------------------------------------

} // namespace NASR