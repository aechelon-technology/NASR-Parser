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
#include "data.h"

#include <string>
#include <unordered_map>

namespace NASR
{

// ----------------------------------------------------------------------------

namespace APT
{

// ----------------------------------------------------------------------------

enum class RemarksTable
{
    AIRPORT,
    AIRPORT_ATTEND_SCHED,
    AIRPORT_CONTACT,
    AIRPORT_SERVICE,
    ARRESTING_DEVICE,
    FUEL_TYPE,
    RUNWAY,
    RUNWAY_END,
    RUNWAY_END_OBSTN,
    RUNWAY_SURFACE_TYPE,
    UNKNOWN
};

const std::unordered_map<std::string, RemarksTable> RemarksTableLookup
{
    { "AIRPORT", RemarksTable::AIRPORT },
    { "AIRPORT_ATTEND_SCHED", RemarksTable::AIRPORT_ATTEND_SCHED },
    { "AIRPORT_CONTACT", RemarksTable::AIRPORT_CONTACT },
    { "AIRPORT_SERVICE", RemarksTable::AIRPORT_SERVICE },
    { "ARRESTING_DEVICE", RemarksTable::ARRESTING_DEVICE },
    { "FUEL_TYPE", RemarksTable::FUEL_TYPE },
    { "RUNWAY", RemarksTable::RUNWAY },
    { "RUNWAY_END", RemarksTable::RUNWAY_END },
    { "RUNWAY_END_OBSTN", RemarksTable::RUNWAY_END_OBSTN },
    { "RUNWAY_SURFACE_TYPE", RemarksTable::RUNWAY_SURFACE_TYPE }
};

typedef CSV::ParsableEnum<RemarksTable, RemarksTableLookup, RemarksTable::UNKNOWN> ParsableRemarksTable;

// ----------------------------------------------------------------------------

class RemarksEntry : public Data::AirportData
{
public:
    RemarksEntry(const CSV::Row& row) : Data::AirportData(row) {}
    const std::string& getLegacyElementNumber() const;
    RemarksTable getTableName() const;
    const std::string& getRefColName() const;
    const std::string& getElement() const;
    int getRefColSeqNo() const;
    const std::string& getRemark() const;
};

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR