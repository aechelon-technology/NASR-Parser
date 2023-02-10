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

#include "runwayEndEntry.h"

namespace NASR
{

// ----------------------------------------------------------------------------

namespace APT
{

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyId() const
{
    return _data["RWY_ID"];
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyEndId() const
{
    return _data["RWY_END_ID"];
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getTrueAlignment() const
{
    return _data.getOptional<int>("TRUE_ALIGNMENT");
}

// ----------------------------------------------------------------------------

ILSType RunwayEndEntry::getILSType() const
{
    return _data.get<ParsableILSType>("ILS_TYPE").value();
}

// ----------------------------------------------------------------------------

tl::optional<bool> RunwayEndEntry::isRightTraffic() const
{
    return _data.getOptional<bool>("RIGHT_HAND_TRAFFIC_PAT_FLAG");
}

// ----------------------------------------------------------------------------

RunwayMarkingType RunwayEndEntry::getRwyMarkingTypeCode() const
{
    return _data.get<ParsableRunwayMarkingType>("RWY_MARKING_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

RunwayMarkingsCondition RunwayEndEntry::getRwyMarkingCond() const
{
    return _data.get<ParsableRunwayMarkingsCondition>("RWY_MARKING_COND").value();
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getRwyEndLatDeg() const
{
    return _data.getOptional<double>("RWY_END_LAT_DEG");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getRwyEndLatMin() const
{
    return _data.getOptional<double>("RWY_END_LAT_MIN");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getRwyEndLatSec() const
{
    return _data.getOptional<double>("RWY_END_LAT_SEC");
}

// ----------------------------------------------------------------------------

tl::optional<char> RunwayEndEntry::getRwyEndLatHemis() const
{
    return _data.getOptional<char>("RWY_END_LAT_HEMIS");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getLatDecimal() const
{
    return _data.getOptional<double>("LAT_DECIMAL");
}

// ----------------------------------------------------------------------------

tl::optional<Data::CoordinateDMS> RunwayEndEntry::getRwyEndLatitude() const
{
    return Data::CoordinateDMS::MakeOptional(getRwyEndLatDeg(), getRwyEndLatMin(), getRwyEndLatSec(), getRwyEndLatHemis());
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getRwyEndLongDeg() const
{
    return _data.get<double>("RWY_END_LONG_DEG");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getRwyEndLongMin() const
{
    return _data.get<double>("RWY_END_LONG_MIN");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getRwyEndLongSec() const
{
    return _data.get<double>("RWY_END_LONG_SEC");
}

// ----------------------------------------------------------------------------

tl::optional<char> RunwayEndEntry::getRwyEndLongHemis() const
{
    return _data.get<char>("RWY_END_LONG_HEMIS");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getLongDecimal() const
{
    return _data.getOptional<double>("LONG_DECIMAL");
}

// ----------------------------------------------------------------------------

tl::optional<Data::CoordinateDMS> RunwayEndEntry::getRwyEndLongitude() const
{
    return Data::CoordinateDMS::MakeOptional(getRwyEndLongDeg(), getRwyEndLongMin(), getRwyEndLongSec(), getRwyEndLongHemis());
}

// ----------------------------------------------------------------------------

tl::optional<Data::LatitudeLongitude> RunwayEndEntry::getRwyEndLatitudeLongitude() const
{
    return Data::LatitudeLongitude::MakeOptional(getRwyEndLatitude(), getRwyEndLongitude());
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getRwyEndElev() const
{
    return _data.getOptional<double>("RWY_END_ELEV");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getThrCrossingHgt() const
{
    return _data.getOptional<int>("THR_CROSSING_HGT");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getVisualGlidePathAngle() const
{
    return _data.getOptional<double>("VISUAL_GLIDE_PATH_ANGLE");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getDisplacedThrLatDeg() const
{
    return _data.getOptional<double>("DISPLACED_THR_LAT_DEG");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getDisplacedThrLatMin() const
{
    return _data.getOptional<double>("DISPLACED_THR_LAT_MIN");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getDisplacedThrLatSec() const
{
    return _data.getOptional<double>("DISPLACED_THR_LAT_SEC");
}

// ----------------------------------------------------------------------------

tl::optional<char> RunwayEndEntry::getDisplacedThrLatHemis() const
{
    return _data.getOptional<char>("DISPLACED_THR_LAT_HEMIS");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getLatDisplacedThrDecimal() const
{
    return _data.getOptional<double>("LAT_DISPLACED_THR_DECIMAL");
}

// ----------------------------------------------------------------------------

tl::optional<Data::CoordinateDMS> RunwayEndEntry::getDisplacedThresholdLatitude() const
{
    return Data::CoordinateDMS::MakeOptional(getDisplacedThrLatDeg(), getDisplacedThrLatMin(), getDisplacedThrLatSec(), getDisplacedThrLatHemis());
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getDisplacedThrLongDeg() const
{
    return _data.getOptional<double>("DISPLACED_THR_LONG_DEG");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getDisplacedThrLongMin() const
{
    return _data.getOptional<double>("DISPLACED_THR_LONG_MIN");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getDisplacedThrLongSec() const
{
    return _data.getOptional<double>("DISPLACED_THR_LONG_SEC");
}

// ----------------------------------------------------------------------------

tl::optional<char> RunwayEndEntry::getDisplacedThrLongHemis() const
{
    return _data.getOptional<char>("DISPLACED_THR_LONG_HEMIS");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getLongDisplacedThrDecimal() const
{
    return _data.getOptional<double>("LONG_DISPLACED_THR_DECIMAL");
}

// ----------------------------------------------------------------------------

tl::optional<Data::CoordinateDMS> RunwayEndEntry::getDisplacedThresholdLongitude() const
{
    return Data::CoordinateDMS::MakeOptional(getDisplacedThrLongDeg(), getDisplacedThrLongMin(), getDisplacedThrLongSec(), getDisplacedThrLongHemis());
}

// ----------------------------------------------------------------------------

tl::optional<Data::LatitudeLongitude> RunwayEndEntry::getDisplacedThresholdLatitudeLongitude() const
{
    return Data::LatitudeLongitude::MakeOptional(getDisplacedThresholdLatitude(), getDisplacedThresholdLongitude());
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getDisplacedThrElev() const
{
    return _data.getOptional<double>("DISPLACED_THR_ELEV");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getDisplacedThrLen() const
{
    return _data.getOptional<int>("DISPLACED_THR_LEN");
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getTdzElev() const
{
    return _data.getOptional<double>("TDZ_ELEV");
}

// ----------------------------------------------------------------------------

VisualGlideSlopeIndicator RunwayEndEntry::getVgsiCode() const
{
    return _data.get<ParsableVisualGlideSlopeIndicator>("VGSI_CODE").value();
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyVisualRangeEquipCode() const
{
    return _data["RWY_VISUAL_RANGE_EQUIP_CODE"];
}

// ----------------------------------------------------------------------------

tl::optional<bool> RunwayEndEntry::getRwyVsbyValueEquipFlag() const
{
    return _data.getOptional<bool>("RWY_VSBY_VALUE_EQUIP_FLAG");
}

// ----------------------------------------------------------------------------

ApproachLightSystem RunwayEndEntry::getApchLgtSystemCode() const
{
    return _data.get<ParsableApproachLightSystem>("APCH_LGT_SYSTEM_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<bool> RunwayEndEntry::getRwyEndLgtsFlag() const
{
    return _data.getOptional<bool>("RWY_END_LGTS_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> RunwayEndEntry::getCntrlnLgtsAvblFlag() const
{
    return _data.getOptional<bool>("CNTRLN_LGTS_AVBL_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> RunwayEndEntry::getTdzLgtAvblFlag() const
{
    return _data.getOptional<bool>("TDZ_LGT_AVBL_FLAG");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getObstnType() const
{
    return _data["OBSTN_TYPE"];
}

// ----------------------------------------------------------------------------

ObstructionMarking RunwayEndEntry::getObstnMrkdCode() const
{
    return _data.get<ParsableObstructionMarking>("OBSTN_MRKD_CODE").value();
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getFarPart77Code() const
{
    return _data["FAR_PART_77_CODE"];
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getObstnClncSlope() const
{
    return _data.getOptional<int>("OBSTN_CLNC_SLOPE");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getObstnHgt() const
{
    return _data.getOptional<int>("OBSTN_HGT");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getDistFromThr() const
{
    return _data.getOptional<int>("DIST_FROM_THR");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getCntrlnOffset() const
{
    return _data.getOptional<int>("CNTRLN_OFFSET");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getCntrlnDirCode() const
{
    return _data["CNTRLN_DIR_CODE"];
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyGrad() const
{
    return _data["RWY_GRAD"];
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyGradDirection() const
{
    return _data["RWY_GRAD_DIRECTION"];
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyEndPsnSource() const
{
    return _data["RWY_END_PSN_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> RunwayEndEntry::getRwyEndPsnDate() const
{
    return _data.getOptional<Data::Date>("RWY_END_PSN_DATE");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyEndElevSource() const
{
    return _data["RWY_END_ELEV_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> RunwayEndEntry::getRwyEndElevDate() const
{
    return _data.getOptional<Data::Date>("RWY_END_ELEV_DATE");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getDsplThrPsnSource() const
{
    return _data["DSPL_THR_PSN_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> RunwayEndEntry::getRwyEndDsplThrPsnDate() const
{
    return _data.getOptional<Data::Date>("RWY_END_DSPL_THR_PSN_DATE");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getDsplThrElevSource() const
{
    return _data["DSPL_THR_ELEV_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> RunwayEndEntry::getRwyEndDsplThrElevDate() const
{
    return _data.getOptional<Data::Date>("RWY_END_DSPL_THR_ELEV_DATE");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getTdzElevSource() const
{
    return _data["TDZ_ELEV_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> RunwayEndEntry::getRwyEndTdzElevDate() const
{
    return _data.getOptional<Data::Date>("RWY_END_TDZ_ELEV_DATE");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getTkofRunAvbl() const
{
    return _data.getOptional<int>("TKOF_RUN_AVBL");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getTkofDistAvbl() const
{
    return _data.getOptional<int>("TKOF_DIST_AVBL");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getAcltStopDistAvbl() const
{
    return _data.getOptional<int>("ACLT_STOP_DIST_AVBL");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getLndgDistAvbl() const
{
    return _data.getOptional<int>("LNDG_DIST_AVBL");
}

// ----------------------------------------------------------------------------

tl::optional<int> RunwayEndEntry::getLahsoAld() const
{
    return _data.getOptional<int>("LAHSO_ALD");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getRwyEndIntersectLahso() const
{
    return _data["RWY_END_INTERSECT_LAHSO"];
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getLahsoDesc() const
{
    return _data["LAHSO_DESC"];
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getLahsoLat() const
{
    return _data["LAHSO_LAT"];
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getLatLahsoDecimal() const
{
    return _data.getOptional<double>("LAT_LAHSO_DECIMAL");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getLahsoLong() const
{
    return _data["LAHSO_LONG"];
}

// ----------------------------------------------------------------------------

tl::optional<double> RunwayEndEntry::getLongLahsoDecimal() const
{
    return _data.getOptional<double>("LONG_LAHSO_DECIMAL");
}

// ----------------------------------------------------------------------------

const std::string &RunwayEndEntry::getLahsoPsnSource() const
{
    return _data["LAHSO_PSN_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> RunwayEndEntry::getRwyEndLahsoPsnDate() const
{
    return _data.getOptional<Data::Date>("RWY_END_LAHSO_PSN_DATE");
}

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR