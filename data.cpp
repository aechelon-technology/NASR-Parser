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

#include "data.h"

#include <chrono>
#include <iomanip>
#include <regex>
#include <sstream>

namespace NASR
{

namespace Data
{

// ----------------------------------------------------------------------------

namespace stdc = std::chrono;

// ----------------------------------------------------------------------------

namespace Detail
{

// ----------------------------------------------------------------------------

constexpr int SECONDS_IN_AIRAC_CYCLE = 60 * 60 * 24 * 28; // 60 seconds * 60 minutes * 24 hours * 28 days
using cycles = stdc::duration<int, std::ratio<SECONDS_IN_AIRAC_CYCLE>>;

// ----------------------------------------------------------------------------

stdc::system_clock::time_point GetTimePoint(int year, int month, int day)
{
    std::tm tm{ 0 };
    tm.tm_year = year - 1900; // years since 1900
    tm.tm_mon = month - 1;    // month on interval [0, 11]
    tm.tm_mday = day;         // day of month
    return stdc::system_clock::from_time_t(std::mktime(&tm));
}

// ----------------------------------------------------------------------------

stdc::system_clock::time_point GetEpoch()
{
    // 2020-01-02 (https://www.icao.int/airnavigation/information-management/Pages/AIRAC.aspx)
    return GetTimePoint(2020, 1, 2);
}

// ----------------------------------------------------------------------------

} // namespace Detail

// ----------------------------------------------------------------------------

AIRAC::AIRAC(std::tm time)
{
    int requestedYear = time.tm_year + 1900;
    const stdc::system_clock::time_point epoch = Detail::GetEpoch();
    const stdc::system_clock::time_point requestedTime = stdc::system_clock::from_time_t(std::mktime(&time));
    stdc::system_clock::time_point startOfYear = Detail::GetTimePoint(requestedYear, 1, 1);

    const Detail::cycles fullCyclesSinceEpoch = stdc::duration_cast<Detail::cycles>(requestedTime - epoch);
    const stdc::system_clock::time_point startOfRequestedCycle = epoch + fullCyclesSinceEpoch;

    if (startOfRequestedCycle < startOfYear)
    {
        requestedYear -= 1;
        startOfYear = Detail::GetTimePoint(requestedYear, 1, 1);
    }

    const int cycleInYear = stdc::duration_cast<Detail::cycles>(startOfRequestedCycle - startOfYear).count() + 1;

    _identifier = ((requestedYear % 1000) * 100) + cycleInYear;
}

// ----------------------------------------------------------------------------

int AIRAC::getIdentifier() const
{
    return _identifier;
}

// ----------------------------------------------------------------------------

Date::Date() : _valid(false), _year(0), _month(0), _day(0) {}

// ----------------------------------------------------------------------------

Date::Date(int year, uint8_t month, uint8_t day)
    : _year(year), _month(month), _day(day), _valid(true)
{}

// ----------------------------------------------------------------------------

Date::Date(const std::string &yyyymmdd)
    : _valid(false), _year(0), _month(0), _day(0)
{
    parse(yyyymmdd);
}

// ----------------------------------------------------------------------------

void Date::parse(const std::string &data)
{
    const std::regex re(R"((\d{4})/(\d{2})/(\d{2}))");
    std::smatch m;
    std::regex_match(data, m, re);

    _year = CSV::Utils::ParseNumber<int>(m[1]);
    _month = static_cast<uint8_t>(CSV::Utils::ParseNumber<int>(m[2]));
    _day = static_cast<uint8_t>(CSV::Utils::ParseNumber<int>(m[3]));
    _valid = _month >= 1 && _month <= 12 && _day >= 1 && _day <= 31;
}

// ----------------------------------------------------------------------------

bool Date::isValid() const
{
    return _valid;
}

// ----------------------------------------------------------------------------

std::time_t Date::getUnixTime() const
{
    std::tm tm = getStruct();
    return std::mktime(&tm);
}

// ----------------------------------------------------------------------------

int Date::getYear() const
{
    return _year;
}

// ----------------------------------------------------------------------------

uint8_t Date::getMonth() const
{
    return _month;
}

// ----------------------------------------------------------------------------

uint8_t Date::getDay() const
{
    return _day;
}

// ----------------------------------------------------------------------------

int Date::getCycle() const
{
    return AIRAC(getStruct()).getIdentifier();
}

// ----------------------------------------------------------------------------

std::string Date::toString(const char *fmt) const
{
    std::tm tm = getStruct();
    std::ostringstream out;
    out << std::put_time(&tm, fmt);
    return out.str();
}

// ----------------------------------------------------------------------------

std::tm Date::getStruct() const
{
    std::tm tm{ 0 };
    tm.tm_year = _year - 1900; // years since 1900
    tm.tm_mon = _month - 1;    // month on interval [0, 11]
    tm.tm_mday = _day;         // day
    return tm;
}

// ----------------------------------------------------------------------------

CoordinateDMS::CoordinateDMS()
    : _degrees(0), _minutes(0), _seconds(0), _valid(false)
{
}

// ----------------------------------------------------------------------------

CoordinateDMS::CoordinateDMS(double degrees, double minutes, double seconds, char hemisphere)
{
    int sign = 0;
    switch (hemisphere)
    {
        case 'N':
        case 'E':
            sign = 1;
            break;
        case 'S':
        case 'W':
            sign = -1;
            break;
        default:
            _valid = false;
            break;
    }
    if ((sign != 0) && (degrees >= 0) && (minutes >= 0) && (seconds >= 0))
    {
        _degrees = degrees * sign;
        _minutes = minutes;
        _seconds = seconds;
        _valid = true;
    }
    else
    {
        _degrees = 0;
        _minutes = 0;
        _seconds = 0;
        _valid = false;
    }
}

// ----------------------------------------------------------------------------

bool CoordinateDMS::valid() const
{
    return _valid;
}

// ----------------------------------------------------------------------------

double CoordinateDMS::getDecimalDegrees() const
{
    const int sign = (_degrees >= 0) - (_degrees < 0); // not a standard signum -- instead of zero it outputs +1
    return sign * (abs(_degrees) + (abs(_minutes) / 60.0) + (abs(_seconds) / 3600.0));
}

// ----------------------------------------------------------------------------

tl::optional<CoordinateDMS> CoordinateDMS::MakeOptional(tl::optional<double> degrees, tl::optional<double> minutes, tl::optional<double> seconds, tl::optional<char> hemisphere)
{
    if (degrees && minutes && seconds && hemisphere)
    {
        CoordinateDMS out{*degrees, *minutes, *seconds, *hemisphere};
        return out.valid() ? tl::optional<CoordinateDMS>(std::move(out)) : tl::nullopt;
    }
    return tl::nullopt;
}

// ----------------------------------------------------------------------------

LatitudeLongitude::LatitudeLongitude()
    : _latitude(0), _longitude(0), _valid(false)
{
}

// ----------------------------------------------------------------------------

LatitudeLongitude::LatitudeLongitude(double latitude, double longitude)
    : _latitude(latitude), _longitude(longitude), _valid(true)
{
}

// ----------------------------------------------------------------------------

LatitudeLongitude::LatitudeLongitude(const CoordinateDMS &latitude, const CoordinateDMS &longitude)
{
    if (latitude.valid() && longitude.valid())
    {
        _latitude = latitude.getDecimalDegrees();
        _longitude = longitude.getDecimalDegrees();
        _valid = true;
    }
    else
    {
        _latitude = 0;
        _longitude = 0;
        _valid = false;
    }
}

// ----------------------------------------------------------------------------

tl::optional<LatitudeLongitude> LatitudeLongitude::MakeOptional(tl::optional<CoordinateDMS> latitude, tl::optional<CoordinateDMS> longitude)
{
    if (latitude && longitude)
    {
        LatitudeLongitude out{ *latitude, *longitude };
        return out.valid() ? tl::optional<LatitudeLongitude>(std::move(out)) : tl::nullopt;
    }
    return tl::nullopt;
}

// ----------------------------------------------------------------------------

bool LatitudeLongitude::valid() const
{
    return _valid;
}

// ----------------------------------------------------------------------------

double LatitudeLongitude::getLatitude() const
{
    return _latitude;
}

// ----------------------------------------------------------------------------

double LatitudeLongitude::getLongitude() const
{
    return _longitude;
}

// ----------------------------------------------------------------------------

Date AirportData::getEffectiveDate() const
{
    return _data["EFF_DATE"];
}

// ----------------------------------------------------------------------------

std::string AirportData::getSiteNumber() const
{
    return _data["SITE_NO"];
}

// ----------------------------------------------------------------------------

LandingFacilityTypeCode AirportData::getSiteTypeCode() const
{
    return _data.get<ParsableLandingFacilityTypeCode>("SITE_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

std::string AirportData::getStateCode() const
{
    return _data["STATE_CODE"];
}

// ----------------------------------------------------------------------------

std::string AirportData::getLocationIdentifier() const
{
    return _data["ARPT_ID"];
}

// ----------------------------------------------------------------------------

std::string AirportData::getCity() const
{
    return _data["CITY"];
}

// ----------------------------------------------------------------------------

std::string AirportData::getCountryCode() const
{
    return _data["COUNTRY_CODE"];
}

// ----------------------------------------------------------------------------

std::string ILSData::getRunwayEnd() const
{
    return _data["RWY_END_ID"];
}

// ----------------------------------------------------------------------------

std::string ILSData::getIlsLocId() const
{
    return _data["ILS_LOC_ID"];
}

// ----------------------------------------------------------------------------

ILS::SystemType ILSData::getSystemTypeCode() const
{
    return _data.get<ILS::ParsableSystemType>("SYSTEM_TYPE_CODE").value();
}

// ----------------------------------------------------------------------------

} // namespace Data

} // namespace NASR