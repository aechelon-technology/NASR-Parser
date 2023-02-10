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
#include <utility>

namespace NASR
{

// ----------------------------------------------------------------------------

namespace APT
{

// ----------------------------------------------------------------------------

enum class SurfaceType
{
    PORTLAND_CEMENT_CONCRETE,
    ASPHALT_OR_BITUMINOUS_CONCRETE,
    SNOW,
    ICE,
    PIERCED_STEEL_PLANKING_OR_LANDING_MATS_OR_MEMBRANES,
    OILED_OR_SOIL_CEMENT_OR_LIME_STABILIZED,
    GRAVEL_OR_CINDERS_OR_CRUSHED_ROCK_OR_CORAL_OR_SHELLS_OR_SLAG,
    GRASS_OR_SOD,
    NATURAL_SOIL,
    PARTIALLY_CONCRETE_OR_ASPHALT_OR_BITUMEN_OR_BOUND_MACADAM,
    MATERIAL_NOT_SPECIFIED,
    WATER,
    ALUMINUM,
    BRICK,
    CALICHE,
    CORAL,
    DECK,
    GRASS,
    MATS,
    METAL,
    NSTD,
    OIL_AND_CHIP,
    PSP,
    SAND,
    SOD,
    STEEL,
    TRTD,
    WOOD,
    UNKNOWN
};

const std::unordered_map<std::string, SurfaceType> SurfaceTypeLookup
{
    { "CONC", SurfaceType::PORTLAND_CEMENT_CONCRETE },
    { "ASPH", SurfaceType::ASPHALT_OR_BITUMINOUS_CONCRETE },
    { "SNOW", SurfaceType::SNOW },
    { "ICE", SurfaceType::ICE },
    { "MATS", SurfaceType::PIERCED_STEEL_PLANKING_OR_LANDING_MATS_OR_MEMBRANES },
    { "TREATED", SurfaceType::OILED_OR_SOIL_CEMENT_OR_LIME_STABILIZED },
    { "GRVL", SurfaceType::GRAVEL_OR_CINDERS_OR_CRUSHED_ROCK_OR_CORAL_OR_SHELLS_OR_SLAG },
    { "GRAVEL", SurfaceType::GRAVEL_OR_CINDERS_OR_CRUSHED_ROCK_OR_CORAL_OR_SHELLS_OR_SLAG },
    { "TURF", SurfaceType::GRASS_OR_SOD },
    { "DIRT", SurfaceType::NATURAL_SOIL },
    { "PEM", SurfaceType::PARTIALLY_CONCRETE_OR_ASPHALT_OR_BITUMEN_OR_BOUND_MACADAM },
    { "ROOFTOP", SurfaceType::MATERIAL_NOT_SPECIFIED },
    { "ROOF-TOP", SurfaceType::MATERIAL_NOT_SPECIFIED },
    { "WATER", SurfaceType::WATER },
    { "ALUM", SurfaceType::ALUMINUM },
    { "ALUMINUM", SurfaceType::ALUMINUM },
    { "BRICK", SurfaceType::BRICK },
    { "CALICHE", SurfaceType::CALICHE },
    { "CORAL", SurfaceType::CORAL },
    { "DECK", SurfaceType::DECK },
    { "GRASS", SurfaceType::GRASS },
    { "MATS", SurfaceType::MATS },
    { "METAL", SurfaceType::METAL },
    { "NSTD", SurfaceType::NSTD },
    { "OIL&CHIP", SurfaceType::OIL_AND_CHIP },
    { "PSP", SurfaceType::PSP },
    { "SAND", SurfaceType::SAND },
    { "SOD", SurfaceType::SOD },
    { "STEEL", SurfaceType::STEEL },
    { "TRTD", SurfaceType::TRTD },
    { "WOOD", SurfaceType::WOOD }
};

typedef CSV::ParsableEnum<SurfaceType, SurfaceTypeLookup, SurfaceType::UNKNOWN> ParsableSurfaceType;

// ----------------------------------------------------------------------------

enum class SurfaceCondition
{
    EXCELLENT,
    GOOD,
    FAIR,
    POOR,
    FAILED,
    UNKNOWN
};

const std::unordered_map<std::string, SurfaceCondition> SurfaceConditionLookup
{
    { "EXCELLENT", SurfaceCondition::EXCELLENT },
    { "GOOD", SurfaceCondition::GOOD },
    { "FAIR", SurfaceCondition::FAIR },
    { "POOR", SurfaceCondition::POOR },
    { "FAILED", SurfaceCondition::FAILED }
};

typedef CSV::ParsableEnum<SurfaceCondition, SurfaceConditionLookup, SurfaceCondition::UNKNOWN> ParsableSurfaceCondition;

// ----------------------------------------------------------------------------

enum class SurfaceTreatment
{
    SAW_CUT_OR_PLASTIC_GROOVED,
    POROUS_FRICTION_COURSE,
    AGGREGATE_FRICTION_SEAL_COAT,
    RUBBERIZED_FRICTION_SEAL_COAT,
    WIRE_COMB_OR_WIRE_TINE,
    NO_SPECIAL_SURFACE_TREATMENT,
    UNKNOWN
};

const std::unordered_map<std::string, SurfaceTreatment> SurfaceTreatmentLookup
{
    { "GRVD", SurfaceTreatment::SAW_CUT_OR_PLASTIC_GROOVED },
    { "PFC", SurfaceTreatment::POROUS_FRICTION_COURSE },
    { "AFSC", SurfaceTreatment::AGGREGATE_FRICTION_SEAL_COAT },
    { "RFSC", SurfaceTreatment::RUBBERIZED_FRICTION_SEAL_COAT },
    { "WC", SurfaceTreatment::WIRE_COMB_OR_WIRE_TINE },
    { "NONE", SurfaceTreatment::NO_SPECIAL_SURFACE_TREATMENT }
};

typedef CSV::ParsableEnum<SurfaceTreatment, SurfaceTreatmentLookup, SurfaceTreatment::UNKNOWN> ParsableSurfaceTreatment;

// ----------------------------------------------------------------------------

enum class PavementType
{
    RIGID,
    FLEXIBLE,
    UNKNOWN
};

const std::unordered_map<std::string, PavementType> PavementTypeLookup
{
    { "R", PavementType::RIGID },
    { "F", PavementType::FLEXIBLE }
};

typedef CSV::ParsableEnum<PavementType, PavementTypeLookup, PavementType::UNKNOWN> ParsablePavementType;

// ----------------------------------------------------------------------------

enum class RunwayDeterminationMethod
{
    TECHNICAL,
    USING_AIRCRAFT,
    UNKNOWN
};

const std::unordered_map<std::string, RunwayDeterminationMethod> RunwayDeterminationMethodLookup
{
    { "T", RunwayDeterminationMethod::TECHNICAL },
    { "U", RunwayDeterminationMethod::USING_AIRCRAFT }
};

typedef CSV::ParsableEnum<RunwayDeterminationMethod, RunwayDeterminationMethodLookup, RunwayDeterminationMethod::UNKNOWN> ParsableRunwayDeterminationMethod;

// ----------------------------------------------------------------------------

enum class RunwayLightsEdgeIntensity
{
    HIGH,
    MEDIUM,
    LOW,
    NONSTANDARD_LIGHTING_SYSTEM,
    NO_EDGE_LIGHTING_SYSTEM,
    UNKNOWN
};

const std::unordered_map<std::string, RunwayLightsEdgeIntensity> RunwayLightsEdgeIntensityLookup
{
    { "HIGH", RunwayLightsEdgeIntensity::HIGH },
    { "MED", RunwayLightsEdgeIntensity::MEDIUM },
    { "LOW", RunwayLightsEdgeIntensity::LOW },
    { "NSTD", RunwayLightsEdgeIntensity::NONSTANDARD_LIGHTING_SYSTEM },
    { "NONE", RunwayLightsEdgeIntensity::NO_EDGE_LIGHTING_SYSTEM }
};

typedef CSV::ParsableEnum<RunwayLightsEdgeIntensity, RunwayLightsEdgeIntensityLookup, RunwayLightsEdgeIntensity::UNKNOWN> ParsableRunwayLightsEdgeIntensity;

// ----------------------------------------------------------------------------

class RunwayEntry : public Data::AirportData
{
public:
    RunwayEntry(const CSV::Row& row) : Data::AirportData(row) {}
    const std::string& getRwyId() const;
    int getRwyLen() const;
    int getRwyWidth() const;
    std::pair<tl::optional<SurfaceType>, tl::optional<SurfaceType>> getSurfaceTypeCode() const;
    SurfaceCondition getCondition() const;
    SurfaceTreatment getTreatmentCode() const;
    tl::optional<int> getPCN() const;
    PavementType getPavementTypeCode() const;
    tl::optional<char> getSubgradeStrengthCode() const;
    tl::optional<char> getTirePresCode() const;
    RunwayDeterminationMethod getDtrmMethodCode() const;
    RunwayLightsEdgeIntensity getRwyLgtCode() const;
    const std::string& getRwyLenSource() const;
    Data::Date getLengthSourceDate() const;
    tl::optional<double> getGrossWtSw() const;
    tl::optional<double> getGrossWtDw() const;
    tl::optional<double> getGrossWtDtw() const;
    tl::optional<double> getGrossWtDdtw() const;
};

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR