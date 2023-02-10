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

#include "dmeEntry.h"

namespace NASR
{

// ----------------------------------------------------------------------------

namespace ILS
{

// ----------------------------------------------------------------------------

const std::string &DMEEntry::getComponentStatus() const
{
    return _data["COMPONENT_STATUS"];
}

// ----------------------------------------------------------------------------

Data::Date DMEEntry::getComponentStatusDate() const
{
    return _data["COMPONENT_STATUS_DATE"];
}

// ----------------------------------------------------------------------------

int DMEEntry::getLatDeg() const
{
    return _data.get<int>("LAT_DEG");
}

// ----------------------------------------------------------------------------

int DMEEntry::getLatMin() const
{
    return _data.get<int>("LAT_MIN");
}

// ----------------------------------------------------------------------------

double DMEEntry::getLatSec() const
{
    return _data.get<double>("LAT_SEC");
}

// ----------------------------------------------------------------------------

char DMEEntry::getLatHemis() const
{
    return _data.get<char>("LAT_HEMIS");
}

// ----------------------------------------------------------------------------

double DMEEntry::getLatDecimal() const
{
    return _data.get<double>("LAT_DECIMAL");
}

// ----------------------------------------------------------------------------

int DMEEntry::getLongDeg() const
{
    return _data.get<int>("LONG_DEG");
}

// ----------------------------------------------------------------------------

int DMEEntry::getLongMin() const
{
    return _data.get<int>("LONG_MIN");
}

// ----------------------------------------------------------------------------

double DMEEntry::getLongSec() const
{
    return _data.get<double>("LONG_SEC");
}

// ----------------------------------------------------------------------------

char DMEEntry::getLongHemis() const
{
    return _data.get<char>("LONG_HEMIS");
}

// ----------------------------------------------------------------------------

double DMEEntry::getLongDecimal() const
{
    return _data.get<double>("LONG_DECIMAL");
}

// ----------------------------------------------------------------------------

SourceCode DMEEntry::getLatLongSourceCode() const
{
    return _data.get<ParsableSourceCode>("LAT_LONG_SOURCE_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<int> DMEEntry::getDistFrmAer() const
{
    return _data.getOptional<int>("DIST_FRM_AER");
}

// ----------------------------------------------------------------------------

tl::optional<int> DMEEntry::getDistFrmCntrLine() const
{
    return _data.getOptional<int>("DIST_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

tl::optional<char> DMEEntry::getDirFrmCntrLine() const
{
    return _data.getOptional<char>("DIR_FRM_CNTR_LINE");
}

// ----------------------------------------------------------------------------

SourceCode DMEEntry::getDistDirSourceCode() const
{
    return _data.get<ParsableSourceCode>("DIST_DIR_SOURCE_CODE").value();
}

// ----------------------------------------------------------------------------

double DMEEntry::getSiteElevation() const
{
    return _data.get<double>("SITE_ELEVATION");
}

// ----------------------------------------------------------------------------

const std::string &DMEEntry::getChannel() const
{
    return _data["CHANNEL"];
}

// ----------------------------------------------------------------------------

tl::optional<int> DMEEntry::getDistFrmRwyStop() const
{
    return _data.getOptional<int>("DIST_FRM_RWY_STOP");
}

// ----------------------------------------------------------------------------

} // namespace ILS

// ----------------------------------------------------------------------------

} // namespace NASR