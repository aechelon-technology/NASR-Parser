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

#include "airportBaseEntry.h"

namespace NASR
{

// ----------------------------------------------------------------------------

namespace APT
{

// ----------------------------------------------------------------------------

Data::FAARegion BaseEntry::getRegionCode() const
{
    return _data.get<Data::ParsableFAARegionCode>("REGION_CODE").value();
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getAdoCode() const
{
    return _data["ADO_CODE"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getStateName() const
{
    return _data["STATE_NAME"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getCountyName() const
{
    return _data["COUNTY_NAME"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getCountyAssocState() const
{
    return _data["COUNTY_ASSOC_STATE"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getAirportName() const
{
    return _data["ARPT_NAME"];
}

// ----------------------------------------------------------------------------

OwnershipType BaseEntry::getOwnershipTypeCode() const
{
    return _data.get<ParsableOwnershipType>("OWNERSHIP_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

FacilityUse BaseEntry::getFacilityUseCode() const
{
    return _data.get<ParsableFacilityUse>("FACILITY_USE_CODE").value();
}

// ----------------------------------------------------------------------------

double BaseEntry::getLatDeg() const
{
    return _data.get<double>("LAT_DEG");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLatMin() const
{
    return _data.get<double>("LAT_MIN");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLatSec() const
{
    return _data.get<double>("LAT_SEC");
}

// ----------------------------------------------------------------------------

char BaseEntry::getLatHemis() const
{
    return _data["LAT_HEMIS"][0];
}

// ----------------------------------------------------------------------------

double BaseEntry::getLatDecimal() const
{
    return _data.get<double>("LAT_DECIMAL");
}

// ----------------------------------------------------------------------------

Data::CoordinateDMS BaseEntry::getLatitude() const
{
    return Data::CoordinateDMS(getLatDeg(), getLatMin(), getLatSec(), getLatHemis());
}

// ----------------------------------------------------------------------------

double BaseEntry::getLongDeg() const
{
    return _data.get<double>("LONG_DEG");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLongMin() const
{
    return _data.get<double>("LONG_MIN");
}

// ----------------------------------------------------------------------------

double BaseEntry::getLongSec() const
{
    return _data.get<double>("LONG_SEC");
}

// ----------------------------------------------------------------------------

char BaseEntry::getLongHemis() const
{
    return _data["LONG_HEMIS"][0];
}

// ----------------------------------------------------------------------------

double BaseEntry::getLongDecimal() const
{
    return _data.get<double>("LONG_DECIMAL");
}

// ----------------------------------------------------------------------------

Data::CoordinateDMS BaseEntry::getLongitude() const
{
    return Data::CoordinateDMS(getLongDeg(), getLongMin(), getLongSec(), getLongHemis());
}

// ----------------------------------------------------------------------------

Data::LatitudeLongitude BaseEntry::getLatitudeLongitude() const
{
    return Data::LatitudeLongitude(getLatitude(), getLongitude());
}

// ----------------------------------------------------------------------------

DeterminationMethod BaseEntry::getSurveyMethodCode() const
{
    return _data.get<ParsableDeterminationMethod>("SURVEY_METHOD_CODE").value();
}

// ----------------------------------------------------------------------------

double BaseEntry::getElevation() const
{
    return _data.get<double>("ELEV");
}

// ----------------------------------------------------------------------------

DeterminationMethod BaseEntry::getElevMethodCode() const
{
    return _data.get<ParsableDeterminationMethod>("ELEV_METHOD_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getMagVarn() const
{
    return _data.getOptional<int>("MAG_VARN");
}

// ----------------------------------------------------------------------------

tl::optional<char> BaseEntry::getMagHemis() const
{
    return _data.getOptional<char>("MAG_HEMIS");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getMagVarnYear() const
{
    return _data.getOptional<int>("MAG_VARN_YEAR");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getTrafficPatternAltitude() const
{
    return _data.getOptional<int>("TPA");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getChartName() const
{
    return _data["CHART_NAME"];
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getDistCityToAirport() const
{
    return _data.getOptional<int>("DIST_CITY_TO_AIRPORT");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getDirectionCode() const
{
    return _data["DIRECTION_CODE"];
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getAcreage() const
{
    return _data.getOptional<int>("ACREAGE");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getRespArtccId() const
{
    return _data["RESP_ARTCC_ID"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getComputerId() const
{
    return _data["COMPUTER_ID"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getArtccName() const
{
    return _data["ARTCC_NAME"];
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getFssOnArptFlag() const
{
    return _data.getOptional<bool>("FSS_ON_ARPT_FLAG");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getFssId() const
{
    return _data["FSS_ID"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getFssName() const
{
    return _data["FSS_NAME"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getPhoneNo() const
{
    return _data["PHONE_NO"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getTollFreeNo() const
{
    return _data["TOLL_FREE_NO"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getAltFssId() const
{
    return _data["ALT_FSS_ID"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getAltFssName() const
{
    return _data["ALT_FSS_NAME"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getAltTollFreeNo() const
{
    return _data["ALT_TOLL_FREE_NO"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getNotamId() const
{
    return _data["NOTAM_ID"];
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getNotamFlag() const
{
    return _data.getOptional<bool>("NOTAM_FLAG");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getActivationDate() const
{
    return _data["ACTIVATION_DATE"];
}

// ----------------------------------------------------------------------------

AirportStatusCode BaseEntry::getArptStatus() const
{
    return _data.get<ParsableAirportStatusCode>("ARPT_STATUS").value();
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getFar139TypeCode() const
{
    return _data["FAR_139_TYPE_CODE"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getFar139CarrierSerCode() const
{
    return _data["FAR_139_CARRIER_SER_CODE"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getArffCertTypeDate() const
{
    return _data["ARFF_CERT_TYPE_DATE"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getNaspCode() const
{
    return _data["NASP_CODE"];
}

// ----------------------------------------------------------------------------

AirspaceAnalysisDetermination BaseEntry::getAspAnlysDtrmCode() const
{
    return _data.get<ParsableAirspaceAnalysisDetermination>("ASP_ANLYS_DTRM_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getCustomsFlag() const
{
    return _data.getOptional<bool>("CUST_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getLndgRightsFlag() const
{
    return _data.getOptional<bool>("LNDG_RIGHTS_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getJointUseFlag() const
{
    return _data.getOptional<bool>("JOINT_USE_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getMilLndgFlag() const
{
    return _data.getOptional<bool>("MIL_LNDG_FLAG");
}

// ----------------------------------------------------------------------------

AirportInspectionMethod BaseEntry::getInspectMethodCode() const
{
    return _data.get<ParsableAirportInspectionMethod>("INSPECT_METHOD_CODE").value();
}

// ----------------------------------------------------------------------------

InspectorCode BaseEntry::getInspectorCode() const
{
    return _data.get<ParsableInspectorCode>("INSPECTOR_CODE").value();
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> BaseEntry::getLastInspection() const
{
    return _data.getOptional<Data::Date>("LAST_INSPECTION");
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> BaseEntry::getLastInfoResponse() const
{
    return _data.getOptional<Data::Date>("LAST_INFO_RESPONSE");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getFuelTypes() const
{
    return _data["FUEL_TYPES"];
}

// ----------------------------------------------------------------------------

RepairAvailabilityType BaseEntry::getAirframeRepairSerCode() const
{
    return _data.get<ParsableRepairAvailabilityType>("AIRFRAME_REPAIR_SER_CODE").value();
}

// ----------------------------------------------------------------------------

RepairAvailabilityType BaseEntry::getPwrPlantRepairSer() const
{
    return _data.get<ParsableRepairAvailabilityType>("PWR_PLANT_REPAIR_SER").value();
}

// ----------------------------------------------------------------------------

OxygenPressureAvailable BaseEntry::getBottledOxyType() const
{
    return _data.get<ParsableOxygenPressureAvailable>("BOTTLED_OXY_TYPE").value();
}

// ----------------------------------------------------------------------------

OxygenPressureAvailable BaseEntry::getBulkOxyType() const
{
    return _data.get<ParsableOxygenPressureAvailable>("BULK_OXY_TYPE").value();
}

// ----------------------------------------------------------------------------

LightingSchedule BaseEntry::getLgtSked() const
{
    return _data.get<ParsableLightingSchedule>("LGT_SKED").value();
}

// ----------------------------------------------------------------------------

LightingSchedule BaseEntry::getBcnLgtSked() const
{
    return _data.get<ParsableLightingSchedule>("BCN_LGT_SKED").value();
}

// ----------------------------------------------------------------------------

ATCFacilityType BaseEntry::getTwrTypeCode() const
{
    return _data.get<ParsableATCFacilityType>("TWR_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

SegmentedCircle BaseEntry::getSegCircleMkrFlag() const
{
    return _data.get<ParsableSegmentedCircle>("SEG_CIRCLE_MKR_FLAG").value();
}

// ----------------------------------------------------------------------------

AirportBeacon BaseEntry::getBeaconLensColor() const
{
    return _data.get<ParsableAirportBeacon>("BCN_LENS_COLOR").value();
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getLndgFeeFlag() const
{
    return _data.getOptional<bool>("LNDG_FEE_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getMedicalUseFlag() const
{
    return _data.getOptional<bool>("MEDICAL_USE_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getBasedSingleEng() const
{
    return _data.getOptional<int>("BASED_SINGLE_ENG");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getBasedMultiEng() const
{
    return _data.getOptional<int>("BASED_MULTI_ENG");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getBasedJetEng() const
{
    return _data.getOptional<int>("BASED_JET_ENG");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getBasedHel() const
{
    return _data.getOptional<int>("BASED_HEL");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getBasedGliders() const
{
    return _data.getOptional<int>("BASED_GLIDERS");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getBasedMilAcft() const
{
    return _data.getOptional<int>("BASED_MIL_ACFT");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getBasedUltralgtAcft() const
{
    return _data.getOptional<int>("BASED_ULTRALGT_ACFT");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getCommercialOps() const
{
    return _data.getOptional<int>("COMMERCIAL_OPS");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getCommuterOps() const
{
    return _data.getOptional<int>("COMMUTER_OPS");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getAirTaxiOps() const
{
    return _data.getOptional<int>("AIR_TAXI_OPS");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getLocalOps() const
{
    return _data.getOptional<int>("LOCAL_OPS");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getItnrntOps() const
{
    return _data.getOptional<int>("ITNRNT_OPS");
}

// ----------------------------------------------------------------------------

tl::optional<int> BaseEntry::getMilAcftOps() const
{
    return _data.getOptional<int>("MIL_ACFT_OPS");
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> BaseEntry::getAnnualOpsDate() const
{
    return _data.getOptional<Data::Date>("ANNUAL_OPS_DATE");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getArptPsnSource() const
{
    return _data["ARPT_PSN_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> BaseEntry::getPositionSrcDate() const
{
    return _data.getOptional<Data::Date>("POSITION_SRC_DATE");
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getArptElevSource() const
{
    return _data["ARPT_ELEV_SOURCE"];
}

// ----------------------------------------------------------------------------

tl::optional<Data::Date> BaseEntry::getElevationSrcDate() const
{
    return _data.getOptional<Data::Date>("ELEVATION_SRC_DATE");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getContrFuelAvbl() const
{
    return _data.getOptional<bool>("CONTR_FUEL_AVBL");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getTrnsStrgBuoyFlag() const
{
    return _data.getOptional<bool>("TRNS_STRG_BUOY_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getTrnsStrgHgrFlag() const
{
    return _data.getOptional<bool>("TRNS_STRG_HGR_FLAG");
}

// ----------------------------------------------------------------------------

tl::optional<bool> BaseEntry::getTrnsStrgTieFlag() const
{
    return _data.getOptional<bool>("TRNS_STRG_TIE_FLAG");
}

// ----------------------------------------------------------------------------

std::vector<AirportServices> BaseEntry::getOtherServices() const
{
    return _data.getValues<AirportServices, ParsableAirportServices>("OTHER_SERVICES");
}

// ----------------------------------------------------------------------------

WindIndicator BaseEntry::getWindIndcrFlag() const
{
    return _data.get<ParsableWindIndicator>("WIND_INDCR_FLAG").value();
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getIcaoId() const
{
    return _data["ICAO_ID"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getMinOpNetwork() const
{
    return _data["MIN_OP_NETWORK"];
}

// ----------------------------------------------------------------------------

const std::string &BaseEntry::getUserFeeFlag() const
{
    return _data["USER_FEE_FLAG"];
}

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR