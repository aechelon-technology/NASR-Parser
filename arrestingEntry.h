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

enum class ArrestingDevice
{
    BAK_6,
    BAK_9,
    BAK_12,
    BAK_12B,
    BAK_13,
    BAK_14,
    E5,
    E5_1,
    E27,
    E27B,
    E28,
    E28B,
    EMAS,
    M21,
    MA_1,
    MA_1A,
    MA_1A_MOD,
    UNKNOWN
};

const std::unordered_map<std::string, ArrestingDevice> ArrestingDeviceLookup
{
    { "BAK-6", ArrestingDevice::BAK_6 },
    { "BAK-9", ArrestingDevice::BAK_9 },
    { "BAK-12", ArrestingDevice::BAK_12 },
    { "BAK-12B", ArrestingDevice::BAK_12B },
    { "BAK-13", ArrestingDevice::BAK_13 },
    { "BAK-14", ArrestingDevice::BAK_14 },
    { "E5", ArrestingDevice::E5 },
    { "E5-1", ArrestingDevice::E5_1 },
    { "E27", ArrestingDevice::E27 },
    { "E27B", ArrestingDevice::E27B },
    { "E28", ArrestingDevice::E28 },
    { "E28B", ArrestingDevice::E28B },
    { "EMAS", ArrestingDevice::EMAS },
    { "M21", ArrestingDevice::M21 },
    { "MA-1", ArrestingDevice::MA_1 },
    { "MA-1A", ArrestingDevice::MA_1A },
    { "MA-1A MOD", ArrestingDevice::MA_1A_MOD }
};

typedef CSV::ParsableEnum<ArrestingDevice, ArrestingDeviceLookup, ArrestingDevice::UNKNOWN> ParsableArrestingDevice;

// ----------------------------------------------------------------------------

class ArrestingEntry : public Data::AirportData
{
public:
    ArrestingEntry(const CSV::Row& row) : Data::AirportData(row) {}
    const std::string& getRwyId() const;
    const std::string& getRwyEndId() const;
    ArrestingDevice getArrestDeviceCode() const;
};

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR