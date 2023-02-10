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

enum class ILSType
{
    ILS,
    MLS,
    SDF,
    LOC,
    LDA,
    ISMLS,
    ILS_DME,
    SDF_DME,
    LOC_DME,
    LOC_GS,
    LDA_DME,
    UNKNOWN
};

const std::unordered_map<std::string, ILSType> ILSTypeLookup
{
    { "ILS", ILSType::ILS },
    { "MLS", ILSType::MLS },
    { "SDF", ILSType::SDF },
    { "LOCALIZER", ILSType::LOC },
    { "LDA", ILSType::LDA },
    { "ISMLS", ILSType::ISMLS },
    { "ILS/DME", ILSType::ILS_DME },
    { "SDF/DME", ILSType::SDF_DME },
    { "LOC/DME", ILSType::LOC_DME },
    { "LOC/GS", ILSType::LOC_GS },
    { "LDA/DME", ILSType::LDA_DME }
};

typedef CSV::ParsableEnum<ILSType, ILSTypeLookup, ILSType::UNKNOWN> ParsableILSType;

// ----------------------------------------------------------------------------

enum class RunwayMarkingType
{
    PRECISION_INSTRUMENT,
    NONPRECISION_INSTRUMENT,
    BASIC,
    NUMBERS_ONLY,
    NONSTANDARD_OTHER_THAN_NUMBERS_ONLY,
    BUOYS_SEAPLANE_BASE,
    SHORT_TAKEOFF_AND_LANDING,
    NONE,
    UNKNOWN
};

const std::unordered_map<std::string, RunwayMarkingType> RunwayMarkingTypeLookup
{
    { "PIR", RunwayMarkingType::PRECISION_INSTRUMENT },
    { "NPI", RunwayMarkingType::NONPRECISION_INSTRUMENT },
    { "BSC", RunwayMarkingType::BASIC },
    { "NRS", RunwayMarkingType::NUMBERS_ONLY },
    { "NSTD", RunwayMarkingType::NONSTANDARD_OTHER_THAN_NUMBERS_ONLY },
    { "BUOY", RunwayMarkingType::BUOYS_SEAPLANE_BASE },
    { "STOL", RunwayMarkingType::SHORT_TAKEOFF_AND_LANDING },
    { "NONE", RunwayMarkingType::NONE }
};

typedef CSV::ParsableEnum<RunwayMarkingType, RunwayMarkingTypeLookup, RunwayMarkingType::UNKNOWN> ParsableRunwayMarkingType;

// ----------------------------------------------------------------------------

enum class RunwayMarkingsCondition
{
    GOOD,
    FAIR,
    POOR,
    UNKNOWN
};

const std::unordered_map<std::string, RunwayMarkingsCondition> RunwayMarkingsConditionLookup
{
    { "GOOD", RunwayMarkingsCondition::GOOD },
    { "FAIR", RunwayMarkingsCondition::FAIR },
    { "POOR", RunwayMarkingsCondition::POOR },
    { "G", RunwayMarkingsCondition::GOOD },
    { "F", RunwayMarkingsCondition::FAIR },
    { "P", RunwayMarkingsCondition::POOR }
};

typedef CSV::ParsableEnum<RunwayMarkingsCondition, RunwayMarkingsConditionLookup, RunwayMarkingsCondition::UNKNOWN> ParsableRunwayMarkingsCondition;

// ----------------------------------------------------------------------------

enum class VisualGlideSlopeIndicator
{
    SAVASI,
    VASI,
    PAPI,
    TRICOLOR_VASI,
    PULSATING_VASI,
    SYSTEM_OF_PANELS,
    S2L,
    S2R,
    V2L,
    V2R,
    V4L,
    V4R,
    V6L,
    V6R,
    V12,
    V16,
    P2L,
    P2R,
    P4L,
    P4R,
    NONSTANDARD_VASI_SYSTEM,
    PRIVATELY_OWNED_APPROACH_SLOPE_INDICATOR_LIGHT_SYSTEM,
    NONSPECIFIC_VASI_SYSTEM,
    NO_APPROACH_SLOPE_LIGHT_SYSTEM,
    TRIL,
    TRIR,
    PSIL,
    PSIR,
    PNIL,
    PNIR,
    UNKNOWN
};

const std::unordered_map<std::string, VisualGlideSlopeIndicator> VisualGlideSlopeIndicatorLookup
{
    { "SAVASI", VisualGlideSlopeIndicator::SAVASI },
    { "VASI", VisualGlideSlopeIndicator::VASI },
    { "PAPI", VisualGlideSlopeIndicator::PAPI },
    { "TRI", VisualGlideSlopeIndicator::TRICOLOR_VASI },
    { "PSI", VisualGlideSlopeIndicator::PULSATING_VASI },
    { "PNI", VisualGlideSlopeIndicator::SYSTEM_OF_PANELS },
    { "S2L", VisualGlideSlopeIndicator::S2L },
    { "S2R", VisualGlideSlopeIndicator::S2R },
    { "V2L", VisualGlideSlopeIndicator::V2L },
    { "V2R", VisualGlideSlopeIndicator::V2R },
    { "V4L", VisualGlideSlopeIndicator::V4L },
    { "V4R", VisualGlideSlopeIndicator::V4R },
    { "V6L", VisualGlideSlopeIndicator::V6L },
    { "V6R", VisualGlideSlopeIndicator::V6R },
    { "V12", VisualGlideSlopeIndicator::V12 },
    { "V16", VisualGlideSlopeIndicator::V16 },
    { "P2L", VisualGlideSlopeIndicator::P2L },
    { "P2R", VisualGlideSlopeIndicator::P2R },
    { "P4L", VisualGlideSlopeIndicator::P4L },
    { "P4R", VisualGlideSlopeIndicator::P4R },
    { "NSTD", VisualGlideSlopeIndicator::NONSTANDARD_VASI_SYSTEM },
    { "PVT", VisualGlideSlopeIndicator::PRIVATELY_OWNED_APPROACH_SLOPE_INDICATOR_LIGHT_SYSTEM },
    { "VAS", VisualGlideSlopeIndicator::NONSPECIFIC_VASI_SYSTEM },
    { "NONE", VisualGlideSlopeIndicator::NO_APPROACH_SLOPE_LIGHT_SYSTEM },
    { "N", VisualGlideSlopeIndicator::NO_APPROACH_SLOPE_LIGHT_SYSTEM },
    { "TRIL", VisualGlideSlopeIndicator::TRIL },
    { "TRIR", VisualGlideSlopeIndicator::TRIR },
    { "PSIL", VisualGlideSlopeIndicator::PSIL },
    { "PSIR", VisualGlideSlopeIndicator::PSIR },
    { "PNIL", VisualGlideSlopeIndicator::PNIL },
    { "PNIR", VisualGlideSlopeIndicator::PNIR }
};

typedef CSV::ParsableEnum<VisualGlideSlopeIndicator, VisualGlideSlopeIndicatorLookup, VisualGlideSlopeIndicator::UNKNOWN> ParsableVisualGlideSlopeIndicator;

// ----------------------------------------------------------------------------

enum class RVREquipment
{
    TOUCHDOWN,
    MIDFIELD,
    ROLLOUT,
    NO_RVR_AVAILABLE,
    UNKNOWN
};

const std::unordered_map<std::string, RVREquipment> RVREquipmentLookup
{
    { "T", RVREquipment::TOUCHDOWN },
    { "M", RVREquipment::MIDFIELD },
    { "R", RVREquipment::ROLLOUT },
    { "N", RVREquipment::NO_RVR_AVAILABLE }
};

typedef CSV::ParsableEnum<RVREquipment, RVREquipmentLookup, RVREquipment::UNKNOWN> ParsableRVREquipment;

// ----------------------------------------------------------------------------

enum class ApproachLightSystem
{
    AFOVRN,
    ALSAF,
    ALSF1,
    ALSF2,
    MALS,
    MALSF,
    MALSR,
    RAIL,
    SALS,
    SALSF,
    SSALS,
    SSALF,
    SSALR,
    ODALS,
    RLLS,
    MIL_OVRN,
    NONSTANDARD_ALL_OTHERS,
    NO_APPROACH_LIGHTING,
    UNKNOWN
};

const std::unordered_map<std::string, ApproachLightSystem> ApproachLightSystemLookup
{
    { "AFOVRN", ApproachLightSystem::AFOVRN },
    { "ALSAF", ApproachLightSystem::ALSAF },
    { "ALSF1", ApproachLightSystem::ALSF1 },
    { "ALSF2", ApproachLightSystem::ALSF2 },
    { "MALS", ApproachLightSystem::MALS },
    { "MALSF", ApproachLightSystem::MALSF },
    { "MALSR", ApproachLightSystem::MALSR },
    { "RAIL", ApproachLightSystem::RAIL },
    { "SALS", ApproachLightSystem::SALS },
    { "SALSF", ApproachLightSystem::SALSF },
    { "SSALS", ApproachLightSystem::SSALS },
    { "SSALF", ApproachLightSystem::SSALF },
    { "SSALR", ApproachLightSystem::SSALR },
    { "ODALS", ApproachLightSystem::ODALS },
    { "RLLS", ApproachLightSystem::RLLS },
    { "MIL OVRN", ApproachLightSystem::MIL_OVRN },
    { "NSTD", ApproachLightSystem::NONSTANDARD_ALL_OTHERS },
    { "NONE", ApproachLightSystem::NO_APPROACH_LIGHTING }
};

typedef CSV::ParsableEnum<ApproachLightSystem, ApproachLightSystemLookup, ApproachLightSystem::UNKNOWN> ParsableApproachLightSystem;

// ----------------------------------------------------------------------------

enum class ObstructionMarking
{
    MARKED,
    LIGHTED,
    MARKED_AND_LIGHTED,
    NONE,
    UNKNOWN
};

const std::unordered_map<std::string, ObstructionMarking> ObstructionMarkingLookup
{
    { "M", ObstructionMarking::MARKED },
    { "L", ObstructionMarking::LIGHTED },
    { "ML", ObstructionMarking::MARKED_AND_LIGHTED },
    { "LM", ObstructionMarking::MARKED_AND_LIGHTED },
    { "NONE", ObstructionMarking::NONE }
};

typedef CSV::ParsableEnum<ObstructionMarking, ObstructionMarkingLookup, ObstructionMarking::UNKNOWN> ParsableObstructionMarking;

// ----------------------------------------------------------------------------

enum class Part77RunwayCategory
{
    UTILITY_RUNWAY_WITH_A_VISUAL_APPROACH,
    OTHER_THAN_UTILITY_RUNWAY_WITH_A_VISUAL_APPROACH,
    UTILITY_RUNWAY_WITH_A_NONPRECISION_APPROACH,
    OTHER_THAN_UTILITY_RUNWAY_WITH_A_NONPRECISION_APPROACH_HAVING_VISIBILITY_MINIMUMS_GREATER_THAN_3_4_MILE,
    OTHER_THAN_UTILITY_RUNWAY_WITH_A_NONPRECISION_APPROACH_HAVING_VISIBILITY_MINIMUMS_AS_LOW_AS_3_4_MILE,
    PRECISION_INSTRUMENT_RUNWAY,
    UNKNOWN
};

const std::unordered_map<std::string, Part77RunwayCategory> Part77RunwayCategoryLookup
{
    { "A(V)", Part77RunwayCategory::UTILITY_RUNWAY_WITH_A_VISUAL_APPROACH },
    { "B(V)", Part77RunwayCategory::OTHER_THAN_UTILITY_RUNWAY_WITH_A_VISUAL_APPROACH },
    { "A(NP)", Part77RunwayCategory::UTILITY_RUNWAY_WITH_A_NONPRECISION_APPROACH },
    { "C", Part77RunwayCategory::OTHER_THAN_UTILITY_RUNWAY_WITH_A_NONPRECISION_APPROACH_HAVING_VISIBILITY_MINIMUMS_GREATER_THAN_3_4_MILE },
    { "D", Part77RunwayCategory::OTHER_THAN_UTILITY_RUNWAY_WITH_A_NONPRECISION_APPROACH_HAVING_VISIBILITY_MINIMUMS_AS_LOW_AS_3_4_MILE },
    { "PIR", Part77RunwayCategory::PRECISION_INSTRUMENT_RUNWAY }
};

typedef CSV::ParsableEnum<Part77RunwayCategory, Part77RunwayCategoryLookup, Part77RunwayCategory::UNKNOWN> ParsablePart77RunwayCategory;

// ----------------------------------------------------------------------------

class RunwayEndEntry : public Data::AirportData
{
public:
    RunwayEndEntry(const CSV::Row& row) : Data::AirportData(row) {}
    const std::string& getRwyId() const;
    const std::string& getRwyEndId() const;
    tl::optional<int> getTrueAlignment() const;
    ILSType getILSType() const;
    tl::optional<bool> isRightTraffic() const;
    RunwayMarkingType getRwyMarkingTypeCode() const;
    RunwayMarkingsCondition getRwyMarkingCond() const;
    tl::optional<double> getRwyEndLatDeg() const;
    tl::optional<double> getRwyEndLatMin() const;
    tl::optional<double> getRwyEndLatSec() const;
    tl::optional<char> getRwyEndLatHemis() const;
    tl::optional<double> getLatDecimal() const;
    tl::optional<Data::CoordinateDMS> getRwyEndLatitude() const;
    tl::optional<double> getRwyEndLongDeg() const;
    tl::optional<double> getRwyEndLongMin() const;
    tl::optional<double> getRwyEndLongSec() const;
    tl::optional<char> getRwyEndLongHemis() const;
    tl::optional<double> getLongDecimal() const;
    tl::optional<Data::CoordinateDMS> getRwyEndLongitude() const;
    tl::optional<Data::LatitudeLongitude> getRwyEndLatitudeLongitude() const;
    tl::optional<double> getRwyEndElev() const;
    tl::optional<int> getThrCrossingHgt() const;
    tl::optional<double> getVisualGlidePathAngle() const;
    tl::optional<double> getDisplacedThrLatDeg() const;
    tl::optional<double> getDisplacedThrLatMin() const;
    tl::optional<double> getDisplacedThrLatSec() const;
    tl::optional<char> getDisplacedThrLatHemis() const;
    tl::optional<double> getLatDisplacedThrDecimal() const;
    tl::optional<Data::CoordinateDMS> getDisplacedThresholdLatitude() const;
    tl::optional<double> getDisplacedThrLongDeg() const;
    tl::optional<double> getDisplacedThrLongMin() const;
    tl::optional<double> getDisplacedThrLongSec() const;
    tl::optional<char> getDisplacedThrLongHemis() const;
    tl::optional<double> getLongDisplacedThrDecimal() const;
    tl::optional<Data::CoordinateDMS> getDisplacedThresholdLongitude() const;
    tl::optional<Data::LatitudeLongitude> getDisplacedThresholdLatitudeLongitude() const;
    tl::optional<double> getDisplacedThrElev() const;
    tl::optional<int> getDisplacedThrLen() const;
    tl::optional<double> getTdzElev() const;
    VisualGlideSlopeIndicator getVgsiCode() const;
    const std::string& getRwyVisualRangeEquipCode() const;
    tl::optional<bool> getRwyVsbyValueEquipFlag() const;
    ApproachLightSystem getApchLgtSystemCode() const;
    tl::optional<bool> getRwyEndLgtsFlag() const;
    tl::optional<bool> getCntrlnLgtsAvblFlag() const;
    tl::optional<bool> getTdzLgtAvblFlag() const;
    const std::string& getObstnType() const;
    ObstructionMarking getObstnMrkdCode() const;
    const std::string& getFarPart77Code() const;
    tl::optional<int> getObstnClncSlope() const;
    tl::optional<int> getObstnHgt() const;
    tl::optional<int> getDistFromThr() const;
    tl::optional<int> getCntrlnOffset() const;
    const std::string& getCntrlnDirCode() const;
    const std::string& getRwyGrad() const;
    const std::string& getRwyGradDirection() const;
    const std::string& getRwyEndPsnSource() const;
    tl::optional<Data::Date> getRwyEndPsnDate() const;
    const std::string& getRwyEndElevSource() const;
    tl::optional<Data::Date> getRwyEndElevDate() const;
    const std::string& getDsplThrPsnSource() const;
    tl::optional<Data::Date> getRwyEndDsplThrPsnDate() const;
    const std::string& getDsplThrElevSource() const;
    tl::optional<Data::Date> getRwyEndDsplThrElevDate() const;
    const std::string& getTdzElevSource() const;
    tl::optional<Data::Date> getRwyEndTdzElevDate() const;
    tl::optional<int> getTkofRunAvbl() const;
    tl::optional<int> getTkofDistAvbl() const;
    tl::optional<int> getAcltStopDistAvbl() const;
    tl::optional<int> getLndgDistAvbl() const;
    tl::optional<int> getLahsoAld() const;
    const std::string& getRwyEndIntersectLahso() const;
    const std::string& getLahsoDesc() const;
    const std::string& getLahsoLat() const;
    tl::optional<double> getLatLahsoDecimal() const;
    const std::string& getLahsoLong() const;
    tl::optional<double> getLongLahsoDecimal() const;
    const std::string& getLahsoPsnSource() const;
    tl::optional<Data::Date> getRwyEndLahsoPsnDate() const;
};

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR