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

#include "airport.h"

namespace NASR
{

// ----------------------------------------------------------------------------

class AirportImpl : public IAirport
{
public:
    AirportImpl(const APT::BaseEntry &base,
                const std::vector<APT::ArrestingEntry> &arresting,
                const std::vector<APT::AttendanceEntry> &attendance,
                const std::vector<APT::ContactEntry> &contact,
                const std::vector<APT::RemarksEntry> &remarks,
                const std::vector<APT::RunwayEntry> &runways,
                const std::vector<APT::RunwayEndEntry> &runwayEnds,
                const std::vector<ILS::BaseEntry> &ilsBase,
                const std::vector<ILS::GlideslopeEntry> &glideslope,
                const std::vector<ILS::DMEEntry> &dme,
                const std::vector<ILS::MarkerEntry> &marker,
                const std::vector<ILS::RemarksEntry> &ilsRemarks);

    virtual const APT::BaseEntry &getBaseEntry() const override;
    virtual const std::vector<APT::ArrestingEntry> &getArrestingEntries() const override;
    virtual const std::vector<APT::AttendanceEntry> &getAttendanceEntries() const override;
    virtual const std::vector<APT::ContactEntry> &getContactEntries() const override;
    virtual const std::vector<APT::RemarksEntry> &getRemarksEntries() const override;
    virtual const std::vector<APT::RunwayEntry> &getRunwayEntries() const override;
    virtual const std::vector<APT::RunwayEndEntry> &getRunwayEndsEntries() const override;

    virtual const std::vector<ILS::BaseEntry> &getILSBaseEntries() const override;
    virtual const std::vector<ILS::GlideslopeEntry> &getGlideslopeEntries() const override;
    virtual const std::vector<ILS::DMEEntry> &getDMEEntries() const override;
    virtual const std::vector<ILS::MarkerEntry> &getMarkerEntries() const override;
    virtual const std::vector<ILS::RemarksEntry> &getILSRemarksEntries() const override;

private:
    APT::BaseEntry _base;
    std::vector<APT::ArrestingEntry> _arresting;
    std::vector<APT::AttendanceEntry> _attendance;
    std::vector<APT::ContactEntry> _contact;
    std::vector<APT::RemarksEntry> _remarks;
    std::vector<APT::RunwayEntry> _runways;
    std::vector<APT::RunwayEndEntry> _runwayEnds;

    std::vector<ILS::BaseEntry> _ilsBase;
    std::vector<ILS::GlideslopeEntry> _glideslope;
    std::vector<ILS::DMEEntry> _dme;
    std::vector<ILS::MarkerEntry> _marker;
    std::vector<ILS::RemarksEntry> _ilsRemarks;
};

// ----------------------------------------------------------------------------

AirportImpl::AirportImpl(const APT::BaseEntry &base,
                         const std::vector<APT::ArrestingEntry> &arresting,
                         const std::vector<APT::AttendanceEntry> &attendance,
                         const std::vector<APT::ContactEntry> &contact,
                         const std::vector<APT::RemarksEntry> &remarks,
                         const std::vector<APT::RunwayEntry> &runways,
                         const std::vector<APT::RunwayEndEntry> &runwayEnds,
                         const std::vector<ILS::BaseEntry> &ilsBase,
                         const std::vector<ILS::GlideslopeEntry> &glideslope,
                         const std::vector<ILS::DMEEntry> &dme,
                         const std::vector<ILS::MarkerEntry> &marker,
                         const std::vector<ILS::RemarksEntry> &ilsRemarks)
    : _base(base),
      _arresting(arresting),
      _attendance(attendance),
      _contact(contact),
      _remarks(remarks),
      _runways(runways),
      _runwayEnds(runwayEnds),
      _ilsBase(ilsBase),
      _glideslope(glideslope),
      _dme(dme),
      _marker(marker),
      _ilsRemarks(ilsRemarks)
{}

// ----------------------------------------------------------------------------

const APT::BaseEntry &AirportImpl::getBaseEntry() const
{
    return _base;
}

// ----------------------------------------------------------------------------

const std::vector<APT::ArrestingEntry> &AirportImpl::getArrestingEntries() const
{
    return _arresting;
}

// ----------------------------------------------------------------------------

const std::vector<APT::AttendanceEntry> &AirportImpl::getAttendanceEntries() const
{
    return _attendance;
}

// ----------------------------------------------------------------------------

const std::vector<APT::ContactEntry> &AirportImpl::getContactEntries() const
{
    return _contact;
}

// ----------------------------------------------------------------------------

const std::vector<APT::RemarksEntry> &AirportImpl::getRemarksEntries() const
{
    return _remarks;
}

// ----------------------------------------------------------------------------

const std::vector<APT::RunwayEntry> &AirportImpl::getRunwayEntries() const
{
    return _runways;
}

// ----------------------------------------------------------------------------

const std::vector<APT::RunwayEndEntry> &AirportImpl::getRunwayEndsEntries() const
{
    return _runwayEnds;
}

// ----------------------------------------------------------------------------

const std::vector<ILS::BaseEntry> &AirportImpl::getILSBaseEntries() const
{
    return _ilsBase;
}

// ----------------------------------------------------------------------------

const std::vector<ILS::GlideslopeEntry> &AirportImpl::getGlideslopeEntries() const
{
    return _glideslope;
}

// ----------------------------------------------------------------------------

const std::vector<ILS::DMEEntry> &AirportImpl::getDMEEntries() const
{
    return _dme;
}

// ----------------------------------------------------------------------------

const std::vector<ILS::MarkerEntry> &AirportImpl::getMarkerEntries() const
{
    return _marker;
}

// ----------------------------------------------------------------------------

const std::vector<ILS::RemarksEntry> &AirportImpl::getILSRemarksEntries() const
{
    return _ilsRemarks;
}

// ----------------------------------------------------------------------------

AirportFile::AirportFile()
    : CSV::File()
{
}

// ----------------------------------------------------------------------------

AirportFile::AirportFile(const std::string &filename)
    : CSV::File(filename)
{
    _cachedColumns.emplace("ARPT_ID", getColumn("ARPT_ID"));
}

// ----------------------------------------------------------------------------

std::vector<std::string> AirportFile::getAirportIdentifiers() const
{
    return _cachedColumns.at("ARPT_ID").get();
}

// ----------------------------------------------------------------------------

std::vector<size_t> AirportFile::getAirportRowIndices(const std::string &locationIdentifier) const
{
    return _cachedColumns.at("ARPT_ID").where(locationIdentifier);
}

// ----------------------------------------------------------------------------

const CSV::Column &AirportFile::getCachedColumn(const std::string &name)
{
    std::list<std::pair<std::string const, NASR::CSV::Column>>::iterator search = _cachedColumns.find(name);
    if (search != _cachedColumns.end())
    {
        return search->second;
    }
    else
    {
        return _cachedColumns.emplace(name, getColumn(name)).first->second;
    }
}

// ----------------------------------------------------------------------------

std::string Join(const std::string &base, const std::string &filename)
{
    // todo: do more about stripping extra \ or / characters
    return base + "\\" + filename;
}

// ----------------------------------------------------------------------------

AirportFileManager::AirportFileManager()
{
}

// ----------------------------------------------------------------------------

AirportFileManager::AirportFileManager(const std::string &directory)
    : _directory(directory)
{
    loadFrom(directory);
}

// ----------------------------------------------------------------------------

bool AirportFileManager::isInitialized() const
{
    return _base.isValid() &&
           _arresting.isValid() &&
           _attendance.isValid() &&
           _contact.isValid() &&
           _remarks.isValid() &&
           _runway.isValid() &&
           _runwayEnds.isValid() &&
           _ilsBase.isValid() &&
           _glideslope.isValid() &&
           _dme.isValid() &&
           _marker.isValid() &&
           _ilsRemarks.isValid();
}

// ----------------------------------------------------------------------------

void AirportFileManager::loadFrom(const std::string &csvDirectory)
{
    _directory = csvDirectory;

    // load APT files
    _base = AirportFile(Join(csvDirectory, "APT_BASE.csv"));
    _arresting = AirportFile(Join(csvDirectory, "APT_ARS.csv"));
    _attendance = AirportFile(Join(csvDirectory, "APT_ATT.csv"));
    _contact = AirportFile(Join(csvDirectory, "APT_CON.csv"));
    _remarks = AirportFile(Join(csvDirectory, "APT_RMK.csv"));
    _runway = AirportFile(Join(csvDirectory, "APT_RWY.csv"));
    _runwayEnds = AirportFile(Join(csvDirectory, "APT_RWY_END.csv"));

    // load ILS files
    _ilsBase = AirportFile(Join(csvDirectory, "ILS_BASE.csv"));
    _glideslope = AirportFile(Join(csvDirectory, "ILS_GS.csv"));
    _dme = AirportFile(Join(csvDirectory, "ILS_DME.csv"));
    _marker = AirportFile(Join(csvDirectory, "ILS_MKR.csv"));
    _ilsRemarks = AirportFile(Join(csvDirectory, "ILS_RMK.csv"));
}

// ----------------------------------------------------------------------------

const std::string &AirportFileManager::getLastLoadedDirectory() const
{
    return _directory;
}

// ----------------------------------------------------------------------------

std::vector<std::string> AirportFileManager::getAirportIdentifiers() const
{
    return _base.getAirportIdentifiers();
}

// ----------------------------------------------------------------------------

IAirport::Ptr AirportFileManager::getAirport(const std::string &identifier) const
{
    std::vector<size_t> baseIndices = _base.getAirportRowIndices(identifier);
    if (baseIndices.size() != 1)
    {
        return nullptr;
    }

    return std::make_shared<AirportImpl>(
               APT::BaseEntry(_base.getRow(baseIndices[0])),
               getEntriesForAirport<APT::ArrestingEntry>(_arresting, identifier),
               getEntriesForAirport<APT::AttendanceEntry>(_attendance, identifier),
               getEntriesForAirport<APT::ContactEntry>(_contact, identifier),
               getEntriesForAirport<APT::RemarksEntry>(_remarks, identifier),
               getEntriesForAirport<APT::RunwayEntry>(_runway, identifier),
               getEntriesForAirport<APT::RunwayEndEntry>(_runwayEnds, identifier),
               getEntriesForAirport<ILS::BaseEntry>(_ilsBase, identifier),
               getEntriesForAirport<ILS::GlideslopeEntry>(_glideslope, identifier),
               getEntriesForAirport<ILS::DMEEntry>(_dme, identifier),
               getEntriesForAirport<ILS::MarkerEntry>(_marker, identifier),
               getEntriesForAirport<ILS::RemarksEntry>(_remarks, identifier));
}

// ----------------------------------------------------------------------------

IAirport::Ptr AirportFileManager::getAirportByICAO(const std::string &identifier)
{
    std::vector<size_t> indices = _base.getCachedColumn("ICAO_ID").where(identifier);
    if (indices.size() == 1)
    {
        return getAirport(_base[indices[0]]["ARPT_ID"]);
    }
    return getAirport(identifier);
}

// ----------------------------------------------------------------------------

} // namespace NASR