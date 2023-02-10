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

namespace APT
{

// ----------------------------------------------------------------------------

enum class OwnershipType
{
    PUBLIC,
    PRIVATE,
    AIR_FORCE,
    NAVY,
    ARMY,
    COAST_GUARD,
    UNKNOWN
};

const std::unordered_map<std::string, OwnershipType> OwnershipTypeLookup
{
    { "PU", OwnershipType::PUBLIC },
    { "PR", OwnershipType::PRIVATE },
    { "MA", OwnershipType::AIR_FORCE },
    { "MN", OwnershipType::NAVY },
    { "MR", OwnershipType::ARMY },
    { "CG", OwnershipType::COAST_GUARD }
};

typedef CSV::ParsableEnum<OwnershipType, OwnershipTypeLookup, OwnershipType::UNKNOWN> ParsableOwnershipType;

// ----------------------------------------------------------------------------

enum class FacilityUse
{
    OPEN_TO_THE_PUBLIC,
    PRIVATE,
    UNKNOWN
};

const std::unordered_map<std::string, FacilityUse> FacilityUseLookup
{
    { "PU", FacilityUse::OPEN_TO_THE_PUBLIC },
    { "PR", FacilityUse::PRIVATE }
};

typedef CSV::ParsableEnum<FacilityUse, FacilityUseLookup, FacilityUse::UNKNOWN> ParsableFacilityUse;

// ----------------------------------------------------------------------------

enum class DeterminationMethod
{
    ESTIMATED,
    SURVEYED,
    UNKNOWN
};

const std::unordered_map<std::string, DeterminationMethod> DeterminationMethodLookup
{
    { "E", DeterminationMethod::ESTIMATED },
    { "S", DeterminationMethod::SURVEYED }
};

typedef CSV::ParsableEnum<DeterminationMethod, DeterminationMethodLookup, DeterminationMethod::UNKNOWN> ParsableDeterminationMethod;

// ----------------------------------------------------------------------------

enum class AirportStatusCode
{
    CLOSED_INDEFINITELY,
    CLOSED_PERMANENTLY,
    OPERATIONAL,
    UNKNOWN
};

const std::unordered_map<std::string, AirportStatusCode> AirportStatusCodeLookup
{
    { "CI", AirportStatusCode::CLOSED_INDEFINITELY },
    { "CP", AirportStatusCode::CLOSED_PERMANENTLY },
    { "O", AirportStatusCode::OPERATIONAL }
};

typedef CSV::ParsableEnum<AirportStatusCode, AirportStatusCodeLookup, AirportStatusCode::UNKNOWN> ParsableAirportStatusCode;

// ----------------------------------------------------------------------------

enum class AirspaceAnalysisDetermination
{
    CONDITIONAL,
    NOT_ANALYZED,
    NO_OBJECTION,
    OBJECTIONABLE,
    UNKNOWN
};

const std::unordered_map<std::string, AirspaceAnalysisDetermination> AirspaceAnalysisDeterminationLookup
{
    { "CONDL", AirspaceAnalysisDetermination::CONDITIONAL },
    { "NOT ANALYZED", AirspaceAnalysisDetermination::NOT_ANALYZED },
    { "NO OBJECTION", AirspaceAnalysisDetermination::NO_OBJECTION },
    { "OBJECTIONABLE", AirspaceAnalysisDetermination::OBJECTIONABLE }
};

typedef CSV::ParsableEnum<AirspaceAnalysisDetermination, AirspaceAnalysisDeterminationLookup, AirspaceAnalysisDetermination::UNKNOWN> ParsableAirspaceAnalysisDetermination;

// ----------------------------------------------------------------------------

enum class AirportInspectionMethod
{
    FEDERAL,
    STATE,
    CONTRACTOR,
    FORM_5010_1_PUBLIC_USE_MAILOUT_PROGRAM,
    FORM_5010_2_PRIVATE_USE_MAILOUT_PROGRAM,
    UNKNOWN
};

const std::unordered_map<std::string, AirportInspectionMethod> AirportInspectionMethodLookup
{
    { "F", AirportInspectionMethod::FEDERAL },
    { "S", AirportInspectionMethod::STATE },
    { "C", AirportInspectionMethod::CONTRACTOR },
    { "1", AirportInspectionMethod::FORM_5010_1_PUBLIC_USE_MAILOUT_PROGRAM },
    { "2", AirportInspectionMethod::FORM_5010_2_PRIVATE_USE_MAILOUT_PROGRAM }
};

typedef CSV::ParsableEnum<AirportInspectionMethod, AirportInspectionMethodLookup, AirportInspectionMethod::UNKNOWN> ParsableAirportInspectionMethod;

// ----------------------------------------------------------------------------

enum class InspectorCode
{
    FAA_AIRPORTS_FIELD_PERSONNEL,
    STATE_AERONAUTICAL_PERSONNEL,
    PRIVATE_CONTRACT_PERSONNEL,
    OWNER,
    UNKNOWN
};

const std::unordered_map<std::string, InspectorCode> InspectorCodeLookup
{
    { "F", InspectorCode::FAA_AIRPORTS_FIELD_PERSONNEL },
    { "S", InspectorCode::STATE_AERONAUTICAL_PERSONNEL },
    { "C", InspectorCode::PRIVATE_CONTRACT_PERSONNEL },
    { "N", InspectorCode::OWNER }
};

typedef CSV::ParsableEnum<InspectorCode, InspectorCodeLookup, InspectorCode::UNKNOWN> ParsableInspectorCode;

// ----------------------------------------------------------------------------

enum class RepairAvailabilityType
{
    MAJOR,
    MINOR,
    NONE,
    UNKNOWN
};

const std::unordered_map<std::string, RepairAvailabilityType> RepairAvailabilityTypeLookup
{
    { "MAJOR", RepairAvailabilityType::MAJOR },
    { "MINOR", RepairAvailabilityType::MINOR },
    { "NONE", RepairAvailabilityType::NONE }
};

typedef CSV::ParsableEnum<RepairAvailabilityType, RepairAvailabilityTypeLookup, RepairAvailabilityType::UNKNOWN> ParsableRepairAvailabilityType;

// ----------------------------------------------------------------------------

enum class OxygenPressureAvailable
{
    HIGH,
    LOW,
    HIGH_OR_LOW,
    NONE,
    UNKNOWN
};

const std::unordered_map<std::string, OxygenPressureAvailable> OxygenPressureAvailableLookup
{
    { "HIGH", OxygenPressureAvailable::HIGH },
    { "LOW", OxygenPressureAvailable::LOW },
    { "HIGH/LOW", OxygenPressureAvailable::HIGH_OR_LOW },
    { "NONE", OxygenPressureAvailable::NONE }
};

typedef CSV::ParsableEnum<OxygenPressureAvailable, OxygenPressureAvailableLookup, OxygenPressureAvailable::UNKNOWN> ParsableOxygenPressureAvailable;

// ----------------------------------------------------------------------------

enum class LightingSchedule
{
    SUNSET_SUNRISE,
    SEE_REMARKS,
    UNKNOWN
};

const std::unordered_map<std::string, LightingSchedule> LightingScheduleLookup
{
    { "SS-SR", LightingSchedule::SUNSET_SUNRISE },
    { "SEE RMK", LightingSchedule::SEE_REMARKS }
};

typedef CSV::ParsableEnum<LightingSchedule, LightingScheduleLookup, LightingSchedule::UNKNOWN> ParsableLightingSchedule;

// ----------------------------------------------------------------------------

enum class ATCFacilityType
{
    TOWER,
    NON_TOWERED,
    TOWER_APP,
    TOWER_RAPCON,
    TOWER_RATCF,
    TOWER_TRACON,
    UNKNOWN
};

const std::unordered_map<std::string, ATCFacilityType> ATCFacilityTypeLookup
{
    { "ATCT", ATCFacilityType::TOWER },
    { "NON-ATCT", ATCFacilityType::NON_TOWERED },
    { "ATCT-A/C", ATCFacilityType::TOWER_APP },
    { "ATCT-RAPCON", ATCFacilityType::TOWER_RAPCON },
    { "ATCT-RATCF", ATCFacilityType::TOWER_RATCF },
    { "ATCT-TRACON", ATCFacilityType::TOWER_TRACON }
};

typedef CSV::ParsableEnum<ATCFacilityType, ATCFacilityTypeLookup, ATCFacilityType::UNKNOWN> ParsableATCFacilityType;

// ----------------------------------------------------------------------------

enum class SegmentedCircle
{
    YES,
    NO,
    NONE,
    YES_LIGHTED,
    UNKNOWN
};

const std::unordered_map<std::string, SegmentedCircle> SegmentedCircleLookup
{
    { "Y", SegmentedCircle::YES },
    { "N", SegmentedCircle::NO },
    { "NONE", SegmentedCircle::NONE },
    { "Y-L", SegmentedCircle::YES_LIGHTED }
};

typedef CSV::ParsableEnum<SegmentedCircle, SegmentedCircleLookup, SegmentedCircle::UNKNOWN> ParsableSegmentedCircle;

// ----------------------------------------------------------------------------

enum class AirportBeacon
{
    CLEAR_GREEN,
    CLEAR_YELLOW,
    CLEAR_GREEN_YELLOW,
    SPLIT_CLEAR_GREEN,
    CLEAR,
    YELLOW,
    GREEN,
    NONE,
    UNKNOWN
};

const std::unordered_map<std::string, AirportBeacon> AirportBeaconLookup
{
    { "CG", AirportBeacon::CLEAR_GREEN },
    { "CY", AirportBeacon::CLEAR_YELLOW },
    { "CGY", AirportBeacon::CLEAR_GREEN_YELLOW },
    { "SCG", AirportBeacon::SPLIT_CLEAR_GREEN },
    { "C", AirportBeacon::CLEAR },
    { "Y", AirportBeacon::YELLOW },
    { "G", AirportBeacon::GREEN },
    { "N", AirportBeacon::NONE }
};

typedef CSV::ParsableEnum<AirportBeacon, AirportBeaconLookup, AirportBeacon::UNKNOWN> ParsableAirportBeacon;

// ----------------------------------------------------------------------------

enum class AirportServices
{
    AIR_FREIGHT_SERVICES,
    CROP_DUSTING_SERVICES,
    AIR_AMBULANCE_SERVICES,
    AVIONICS,
    BEACHING_GEAR,
    CARGO_HANDLING_SERVICES,
    CHARTER_SERVICE,
    GLIDER_SERVICE,
    PILOT_INSTRUCTION,
    PARACHUTE_JUMP_ACTIVITY,
    AIRCRAFT_RENTAL,
    AIRCRAFT_SALES,
    ANNUAL_SURVEYING,
    GLIDER_TOWING_SERVICES,
    UNKNOWN
};

const std::unordered_map<std::string, AirportServices> AirportServicesLookup
{
    { "AFRT", AirportServices::AIR_FREIGHT_SERVICES },
    { "AGRI", AirportServices::CROP_DUSTING_SERVICES },
    { "AMB", AirportServices::AIR_AMBULANCE_SERVICES },
    { "AVNCS", AirportServices::AVIONICS },
    { "BCHGR", AirportServices::BEACHING_GEAR },
    { "CARGO", AirportServices::CARGO_HANDLING_SERVICES },
    { "CHTR", AirportServices::CHARTER_SERVICE },
    { "GLD", AirportServices::GLIDER_SERVICE },
    { "INSTR", AirportServices::PILOT_INSTRUCTION },
    { "PAJA", AirportServices::PARACHUTE_JUMP_ACTIVITY },
    { "RNTL", AirportServices::AIRCRAFT_RENTAL },
    { "SALES", AirportServices::AIRCRAFT_SALES },
    { "SURV", AirportServices::ANNUAL_SURVEYING },
    { "TOW", AirportServices::GLIDER_TOWING_SERVICES }
};

typedef CSV::ParsableEnum<AirportServices, AirportServicesLookup, AirportServices::UNKNOWN> ParsableAirportServices;

// ----------------------------------------------------------------------------

enum class WindIndicator
{
    NO_WIND_INDICATOR,
    UNLIGHTED_WIND_INDICATOR,
    LIGHTED_WIND_INDICATOR,
    UNKNOWN
};

const std::unordered_map<std::string, WindIndicator> WindIndicatorLookup
{
    { "N", WindIndicator::NO_WIND_INDICATOR },
    { "Y", WindIndicator::UNLIGHTED_WIND_INDICATOR },
    { "Y-L", WindIndicator::LIGHTED_WIND_INDICATOR }
};

typedef CSV::ParsableEnum<WindIndicator, WindIndicatorLookup, WindIndicator::UNKNOWN> ParsableWindIndicator;


// ----------------------------------------------------------------------------

class BaseEntry : public Data::AirportData
{
public:
    BaseEntry(const CSV::Row& row) : Data::AirportData(row) {}
    Data::FAARegion getRegionCode() const;
    const std::string& getAdoCode() const;
    const std::string& getStateName() const;
    const std::string& getCountyName() const;
    const std::string& getCountyAssocState() const;
    const std::string& getAirportName() const;
    OwnershipType getOwnershipTypeCode() const;
    FacilityUse getFacilityUseCode() const;
    double getLatDeg() const;
    double getLatMin() const;
    double getLatSec() const;
    char getLatHemis() const;
    double getLatDecimal() const;
    Data::CoordinateDMS getLatitude() const;
    double getLongDeg() const;
    double getLongMin() const;
    double getLongSec() const;
    char getLongHemis() const;
    double getLongDecimal() const;
    Data::CoordinateDMS getLongitude() const;
    Data::LatitudeLongitude getLatitudeLongitude() const;
    DeterminationMethod getSurveyMethodCode() const;
    double getElevation() const;
    DeterminationMethod getElevMethodCode() const;
    tl::optional<int> getMagVarn() const;
    tl::optional<char> getMagHemis() const;
    tl::optional<int> getMagVarnYear() const;
    tl::optional<int> getTrafficPatternAltitude() const;
    const std::string& getChartName() const;
    tl::optional<int> getDistCityToAirport() const;
    const std::string& getDirectionCode() const;
    tl::optional<int> getAcreage() const;
    const std::string& getRespArtccId() const;
    const std::string& getComputerId() const;
    const std::string& getArtccName() const;
    tl::optional<bool> getFssOnArptFlag() const;
    const std::string& getFssId() const;
    const std::string& getFssName() const;
    const std::string& getPhoneNo() const;
    const std::string& getTollFreeNo() const;
    const std::string& getAltFssId() const;
    const std::string& getAltFssName() const;
    const std::string& getAltTollFreeNo() const;
    const std::string& getNotamId() const;
    tl::optional<bool> getNotamFlag() const;
    const std::string& getActivationDate() const;
    AirportStatusCode getArptStatus() const;
    const std::string& getFar139TypeCode() const;
    const std::string& getFar139CarrierSerCode() const;
    const std::string& getArffCertTypeDate() const;
    const std::string& getNaspCode() const;
    AirspaceAnalysisDetermination getAspAnlysDtrmCode() const;
    tl::optional<bool> getCustomsFlag() const;
    tl::optional<bool> getLndgRightsFlag() const;
    tl::optional<bool> getJointUseFlag() const;
    tl::optional<bool> getMilLndgFlag() const;
    AirportInspectionMethod getInspectMethodCode() const;
    InspectorCode getInspectorCode() const;
    tl::optional<Data::Date> getLastInspection() const;
    tl::optional<Data::Date> getLastInfoResponse() const;
    const std::string& getFuelTypes() const;
    RepairAvailabilityType getAirframeRepairSerCode() const;
    RepairAvailabilityType getPwrPlantRepairSer() const;
    OxygenPressureAvailable getBottledOxyType() const;
    OxygenPressureAvailable getBulkOxyType() const;
    LightingSchedule getLgtSked() const;
    LightingSchedule getBcnLgtSked() const;
    ATCFacilityType getTwrTypeCode() const;
    SegmentedCircle getSegCircleMkrFlag() const;
    AirportBeacon getBeaconLensColor() const;
    tl::optional<bool> getLndgFeeFlag() const;
    tl::optional<bool> getMedicalUseFlag() const;
    tl::optional<int> getBasedSingleEng() const;
    tl::optional<int> getBasedMultiEng() const;
    tl::optional<int> getBasedJetEng() const;
    tl::optional<int> getBasedHel() const;
    tl::optional<int> getBasedGliders() const;
    tl::optional<int> getBasedMilAcft() const;
    tl::optional<int> getBasedUltralgtAcft() const;
    tl::optional<int> getCommercialOps() const;
    tl::optional<int> getCommuterOps() const;
    tl::optional<int> getAirTaxiOps() const;
    tl::optional<int> getLocalOps() const;
    tl::optional<int> getItnrntOps() const;
    tl::optional<int> getMilAcftOps() const;
    tl::optional<Data::Date> getAnnualOpsDate() const;
    const std::string& getArptPsnSource() const;
    tl::optional<Data::Date> getPositionSrcDate() const;
    const std::string& getArptElevSource() const;
    tl::optional<Data::Date> getElevationSrcDate() const;
    tl::optional<bool> getContrFuelAvbl() const;
    tl::optional<bool> getTrnsStrgBuoyFlag() const;
    tl::optional<bool> getTrnsStrgHgrFlag() const;
    tl::optional<bool> getTrnsStrgTieFlag() const;
    std::vector<AirportServices> getOtherServices() const;
    WindIndicator getWindIndcrFlag() const;
    const std::string& getIcaoId() const;
    const std::string& getMinOpNetwork() const;
    const std::string& getUserFeeFlag() const;

};

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR