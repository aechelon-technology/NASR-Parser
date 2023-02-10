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

#include "runwayEntry.h"

#include <regex>

namespace NASR
{

// ----------------------------------------------------------------------------

namespace APT
{

// ----------------------------------------------------------------------------

const std::string &RunwayEntry::getRwyId() const
{
    return _data["RWY_ID"];
}

// ----------------------------------------------------------------------------

int RunwayEntry::getRwyLen() const
{
    return _data.get<int>("RWY_LEN");
}

// ----------------------------------------------------------------------------

int RunwayEntry::getRwyWidth() const
{
    return _data.get<int>("RWY_WIDTH");
}

// ----------------------------------------------------------------------------

std::pair<tl::optional<SurfaceType>, tl::optional<SurfaceType>> RunwayEntry::getSurfaceTypeCode() const
{
    const std::regex re(R"(([^-\/\s]+)(?:[-\/]([^-\/\s]+))?)");
    std::smatch m;
    std::regex_match(_data["SURFACE_TYPE_CODE"], m, re);

    if (m[0] == "ROOF-TOP")
    {
        // handle the case separately since there's a single value encoded with a delimiter in the middle sometimes...
        return std::make_pair(SurfaceType::MATERIAL_NOT_SPECIFIED, tl::nullopt);
    }
    else if (m[2].matched)
    {
        // not going to match the second group without having the first group present
        return std::make_pair(ParsableSurfaceType(m[1]).value(), ParsableSurfaceType(m[2]).value());
    }
    else if (m[1].matched)
    {
        // if the first group matches (sometimes it might be entirely blank)
        return std::make_pair(ParsableSurfaceType(m[1]).value(), tl::nullopt);
    }

    return std::make_pair(tl::nullopt, tl::nullopt);
}

// ----------------------------------------------------------------------------

SurfaceCondition RunwayEntry::getCondition() const
{
    return _data.get<ParsableSurfaceCondition>("COND").value();
}

// ----------------------------------------------------------------------------

SurfaceTreatment RunwayEntry::getTreatmentCode() const
{
    return _data.get<ParsableSurfaceTreatment>("TREATMENT_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEntry::getPCN() const
{
    return _data.getOptional<int>("PCN");
}

// ----------------------------------------------------------------------------

PavementType RunwayEntry::getPavementTypeCode() const
{
    return _data.get<ParsablePavementType>("PAVEMENT_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<char> RunwayEntry::getSubgradeStrengthCode() const
{
    return _data.getOptional<char>("SUBGRADE_STRENGTH_CODE");
}

// ----------------------------------------------------------------------------

tl::optional<char> RunwayEntry::getTirePresCode() const
{
    return _data.getOptional<char>("TIRE_PRES_CODE");
}

// ----------------------------------------------------------------------------

RunwayDeterminationMethod RunwayEntry::getDtrmMethodCode() const
{
    return _data.get<ParsableRunwayDeterminationMethod>("DTRM_METHOD_CODE").value();
}

// ----------------------------------------------------------------------------

RunwayLightsEdgeIntensity RunwayEntry::getRwyLgtCode() const
{
    return _data.get<ParsableRunwayLightsEdgeIntensity>("RWY_LGT_CODE").value();
}

// ----------------------------------------------------------------------------

const std::string &RunwayEntry::getRwyLenSource() const
{
    return _data["RWY_LEN_SOURCE"];
}

// ----------------------------------------------------------------------------

Data::Date RunwayEntry::getLengthSourceDate() const
{
    return _data["LENGTH_SOURCE_DATE"];
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEntry::getGrossWtSw() const
{
    return _data.getOptional<double>("GROSS_WT_SW");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEntry::getGrossWtDw() const
{
    return _data.getOptional<double>("GROSS_WT_DW");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEntry::getGrossWtDtw() const
{
    return _data.getOptional<double>("GROSS_WT_DTW");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEntry::getGrossWtDdtw() const
{
    return _data.getOptional<double>("GROSS_WT_DDTW");
}

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR