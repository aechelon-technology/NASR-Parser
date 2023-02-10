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
#include "airportBaseEntry.h"
#include "arrestingEntry.h"
#include "attendanceEntry.h"
#include "contactEntry.h"
#include "airportRemarksEntry.h"
#include "runwayEntry.h"
#include "runwayEndEntry.h"
#include "ilsBaseEntry.h"
#include "glideslopeEntry.h"
#include "dmeEntry.h"
#include "markerEntry.h"
#include "ilsRemarksEntry.h"

#include <memory>

namespace NASR
{

// ----------------------------------------------------------------------------

class IAirport
{
public:
    typedef std::shared_ptr<IAirport> Ptr;

    // entries from APT files
    virtual const APT::BaseEntry& getBaseEntry() const = 0;
    virtual const std::vector<APT::ArrestingEntry>& getArrestingEntries() const = 0;
    virtual const std::vector<APT::AttendanceEntry>& getAttendanceEntries() const = 0;
    virtual const std::vector<APT::ContactEntry>& getContactEntries() const = 0;
    virtual const std::vector<APT::RemarksEntry>& getRemarksEntries() const = 0;
    virtual const std::vector<APT::RunwayEntry>& getRunwayEntries() const = 0;
    virtual const std::vector<APT::RunwayEndEntry>& getRunwayEndsEntries() const = 0;

    // entries from ILS files
    virtual const std::vector<ILS::BaseEntry>& getILSBaseEntries() const = 0;
    virtual const std::vector<ILS::GlideslopeEntry>& getGlideslopeEntries() const = 0;
    virtual const std::vector<ILS::DMEEntry>& getDMEEntries() const = 0;
    virtual const std::vector<ILS::MarkerEntry>& getMarkerEntries() const = 0;
    virtual const std::vector<ILS::RemarksEntry>& getILSRemarksEntries() const = 0;
};

// ----------------------------------------------------------------------------

class AirportFile : public CSV::File
{
public:
    AirportFile();
    AirportFile(const std::string& filename);
    std::vector<std::string> getAirportIdentifiers() const;
    std::vector<size_t> getAirportRowIndices(const std::string& locationIdentifier) const;
    const CSV::Column& getCachedColumn(const std::string& name);
private:
    std::unordered_map<std::string, CSV::Column> _cachedColumns;
};

// ----------------------------------------------------------------------------

class AirportFileManager
{
public:
    AirportFileManager();
    AirportFileManager(const std::string& directory);

    bool isInitialized() const;
    void loadFrom(const std::string& csvDirectory);
    const std::string& getLastLoadedDirectory() const;

    std::vector<std::string> getAirportIdentifiers() const;

    IAirport::Ptr getAirport(const std::string& identifier) const;
    IAirport::Ptr getAirportByICAO(const std::string& identifier);

private:

    template <typename T>
    std::vector<T> getEntriesForAirport(const AirportFile& source, const std::string& locationIdentifier) const
    {
        std::vector<T> out;
        std::vector<size_t> airportIndices = source.getAirportRowIndices(locationIdentifier);
        for (CSV::Row& row : source.getRows(airportIndices))
        {
            out.emplace_back(T(row));
        }
        return out;
    }

private:
    std::string _directory;

    // APT files
    AirportFile _base;
    AirportFile _arresting;
    AirportFile _attendance;
    AirportFile _contact;
    AirportFile _remarks;
    AirportFile _runway;
    AirportFile _runwayEnds;

    // ILS files
    AirportFile _ilsBase;
    AirportFile _glideslope;
    AirportFile _dme;
    AirportFile _marker;
    AirportFile _ilsRemarks;
};

// ----------------------------------------------------------------------------

} // namespace NASR