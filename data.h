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

#pragma once

#include "csv.h"

#include <ctime>
#include <string>
#include <unordered_map>

namespace NASR
{

// ----------------------------------------------------------------------------

namespace ILS
{

// ----------------------------------------------------------------------------

enum class SystemType
{
    ILS,
    SDF,
    LOC,
    LDA,
    ILS_DME,
    SDF_DME,
    LOC_DME,
    LOC_GS,
    LDA_DME,
    UNKNOWN
};

const std::unordered_map<std::string, SystemType> SystemTypeLookup
{
    { "LS", SystemType::ILS },
    { "SF", SystemType::SDF },
    { "LC", SystemType::LOC },
    { "LA", SystemType::LDA },
    { "LD", SystemType::ILS_DME },
    { "SD", SystemType::SDF_DME },
    { "LE", SystemType::LOC_DME },
    { "LG", SystemType::LOC_GS },
    { "DD", SystemType::LDA_DME }
};

typedef CSV::ParsableEnum<SystemType, SystemTypeLookup, SystemType::UNKNOWN> ParsableSystemType;

// ----------------------------------------------------------------------------

enum class SourceCode
{
    AIR_FORCE,
    COAST_GUARD,
    CANADIAN_AIRAC,
    FAA,
    TECH_OPS_AFS_530,
    NOS_HISTORICAL,
    NGS,
    DOD_NGA,
    US_NAVY,
    OWNER,
    NOS_PHOTO_SURVEY_HISTORICAL,
    QUAD_PLOT_HISTORICAL,
    ARMY,
    SIAP,
    THIRD_PARTY_SURVEY,
    SURVEYED,
    UNKNOWN
};

const std::unordered_map<std::string, SourceCode> SourceCodeLookup
{
    { "A", SourceCode::AIR_FORCE },
    { "C", SourceCode::COAST_GUARD },
    { "D", SourceCode::CANADIAN_AIRAC },
    { "F", SourceCode::FAA },
    { "FS", SourceCode::TECH_OPS_AFS_530 },
    { "G", SourceCode::NOS_HISTORICAL },
    { "K", SourceCode::NGS },
    { "M", SourceCode::DOD_NGA },
    { "N", SourceCode::US_NAVY },
    { "O", SourceCode::OWNER },
    { "P", SourceCode::NOS_PHOTO_SURVEY_HISTORICAL },
    { "Q", SourceCode::QUAD_PLOT_HISTORICAL },
    { "R", SourceCode::ARMY },
    { "S", SourceCode::SIAP },
    { "T", SourceCode::THIRD_PARTY_SURVEY },
    { "Z", SourceCode::SURVEYED }
};

typedef CSV::ParsableEnum<SourceCode, SourceCodeLookup, SourceCode::UNKNOWN> ParsableSourceCode;

// ----------------------------------------------------------------------------

} // namespace ILS

// ----------------------------------------------------------------------------

namespace Data
{

// ----------------------------------------------------------------------------

class AIRAC
{
public:
    AIRAC(std::tm time);
    int getIdentifier() const;

private:
    int _identifier;
};

// ----------------------------------------------------------------------------

class Date : public CSV::IParsable
{
public:
    Date();
    Date(int year, uint8_t month, uint8_t day);
    Date(const std::string& yyyymmdd);
    virtual void parse(const std::string& data) override;

    bool isValid() const;
    std::time_t getUnixTime() const;
    int getYear() const;
    uint8_t getMonth() const;
    uint8_t getDay() const;
    int getCycle() const;
    std::string toString(const char* fmt = "%F") const;

private:
    std::tm getStruct() const;

private:
    bool _valid;
    int _year;
    uint8_t _month;
    uint8_t _day;
};

// ----------------------------------------------------------------------------

class CoordinateDMS
{
public:
    CoordinateDMS();
    CoordinateDMS(double degrees, double minutes, double seconds, char hemisphere);

    bool valid() const;
    double getDecimalDegrees() const;

    static tl::optional<CoordinateDMS> MakeOptional(tl::optional<double> degrees, tl::optional<double> minutes, tl::optional<double> seconds, tl::optional<char> hemisphere);

private:
    bool _valid;
    double _degrees;
    double _minutes;
    double _seconds;
};

// ----------------------------------------------------------------------------

class LatitudeLongitude
{
public:
    LatitudeLongitude();
    LatitudeLongitude(double latitude, double longitude);
    LatitudeLongitude(const CoordinateDMS& latitude, const CoordinateDMS& longitude);

    static tl::optional<LatitudeLongitude> MakeOptional(tl::optional<CoordinateDMS> latitude, tl::optional<CoordinateDMS> longitude);

    bool valid() const;
    double getLatitude() const;
    double getLongitude() const;

private:
    bool _valid;
    double _latitude;
    double _longitude;

};

// ----------------------------------------------------------------------------

enum class LandingFacilityTypeCode
{
    AIRPORT,
    BALLOONPORT,
    SEAPLANE_BASE,
    GLIDERPORT,
    HELIPORT,
    ULTRALIGHT,
    UNKNOWN
};

const std::unordered_map<std::string, LandingFacilityTypeCode> LandingFacilityTypeCodeLookup
{
    { "A", LandingFacilityTypeCode::AIRPORT },
    { "B", LandingFacilityTypeCode::BALLOONPORT },
    { "C", LandingFacilityTypeCode::SEAPLANE_BASE },
    { "G", LandingFacilityTypeCode::GLIDERPORT },
    { "H", LandingFacilityTypeCode::HELIPORT },
    { "U", LandingFacilityTypeCode::ULTRALIGHT }
};

typedef CSV::ParsableEnum<LandingFacilityTypeCode, LandingFacilityTypeCodeLookup, LandingFacilityTypeCode::UNKNOWN> ParsableLandingFacilityTypeCode;

// ----------------------------------------------------------------------------

enum class FAARegion
{
    ALASKA,
    CENTRAL,
    EASTERN,
    GREAT_LAKES,
    NEW_ENGLAND,
    NORTHWEST_MOUNTAIN,
    SOUTHERN,
    SOUTHWEST,
    WESTERN_PACIFIC,
    UNKNOWN
};

const std::unordered_map<std::string, FAARegion> FAARegionCodeLookup
{
    { "AAL", FAARegion::ALASKA },
    { "ACE", FAARegion::CENTRAL },
    { "AEA", FAARegion::EASTERN },
    { "AGL", FAARegion::GREAT_LAKES },
    { "ANE", FAARegion::NEW_ENGLAND },
    { "ANM", FAARegion::NORTHWEST_MOUNTAIN },
    { "ASO", FAARegion::SOUTHERN },
    { "ASW", FAARegion::SOUTHWEST },
    { "AWP", FAARegion::WESTERN_PACIFIC }
};

typedef CSV::ParsableEnum<FAARegion, FAARegionCodeLookup, FAARegion::UNKNOWN> ParsableFAARegionCode;

// ----------------------------------------------------------------------------

class IAirportData
{
public:
    virtual Date getEffectiveDate() const = 0;
    virtual std::string getSiteNumber() const = 0;
    virtual LandingFacilityTypeCode getSiteTypeCode() const = 0;
    virtual std::string getStateCode() const = 0;
    virtual std::string getLocationIdentifier() const = 0;
    virtual std::string getCity() const = 0;
    virtual std::string getCountryCode() const = 0;
};

// ----------------------------------------------------------------------------

class AirportData : public IAirportData
{
public:
    AirportData(const CSV::Row& row) : _data(row) {}
    virtual Date getEffectiveDate() const override;
    virtual std::string getSiteNumber() const override;
    virtual LandingFacilityTypeCode getSiteTypeCode() const override;
    virtual std::string getStateCode() const override;
    virtual std::string getLocationIdentifier() const override;
    virtual std::string getCity() const override;
    virtual std::string getCountryCode() const override;
protected:
    CSV::Row _data;
};

// ----------------------------------------------------------------------------

class ILSData : public AirportData
{
public:
    ILSData(const CSV::Row& row) : AirportData(row) {}
    std::string getRunwayEnd() const;
    std::string getIlsLocId() const;
    ILS::SystemType getSystemTypeCode() const;
};

// ----------------------------------------------------------------------------

} // namespace Data

} // namespace NASR