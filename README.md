# FAA NASR Parsing Library

This library improves access to the Federal Aviation Admininstration's 28-Day NASR Subscription data by providing a C++11 compliant parser for the data found in the `APT_BASE.csv`, `APT_ARS.csv`, `APT_ATT.csv`, `APT_CON.csv`, `APT_RMK.csv`, `APT_RWY.csv`, and `APT_RWY_END.csv` files, as well as the `ILS_BASE.csv`, `ILS_GS.csv`, `ILS_DME.csv`, `ILS_MKR.csv`, and `ILS_RMK.csv` files.

The current data from the Federal Aviation Administration can be found here: https://www.faa.gov/air_traffic/flight_info/aeronav/aero_data/NASR_Subscription/

Please note the 28-Day NASR Subscription contains **time-sensitive** information that may be subject to change.  Please ensure that your data comes from the current cycle, and consult NOTAMs for the latest information.

## Usage

To use this library, include `airport.h` and create an instance of `NASR::AirportFileManager`.  Use `YourAirportFileManagerInstance.getAirport(<FAA Location Identifier>)` to retrieve data pertaining to a specific airport.

> Note that the argument to `getAirport()` expects the FAA location identifier of the airport (as seen in the `ARPT_ID` column from the CSV files), **not** the ICAO location identifier.

Alternatively, you can also use `YourAirportFileManagerInstance.getAirportByICAO(<ICAO Location Identifier>)` if you have an ICAO code for an airport.  Using `getAirportByICAO()` will fall back to searching for an FAA location identifier if the specified ICAO code is not found.

## Building

Prior to building, you should first obtain a copy of [`tl::optional`](https://github.com/TartanLlama/optional/releases/tag/v1.0.0), then ensure that your build system has the appropriate search paths set up to locate and use `#include <optional.hpp>` (with Microsoft Visual C++, this can be set up using the `AdditionalIncludeDirectories` prop).

After obtaining `tl::optional` and setting your include directory search paths, you should be able to build using any compiler that supports both the C++11 standard and the `#pragma once` directive.

### Usage Example

```cpp
auto directory = R"(C:\Users\example\Downloads\11_Aug_2022_CSV)";
NASR::AirportFileManager nasr{ directory };

auto airports = { "SFO", "OAK", "SJC" };

for (auto &airportIdentifier : airports)
{
    auto airport = nasr.getAirport(airportIdentifier);
    auto name = airport->getBaseEntry().getAirportName();
    auto elevation = airport->getBaseEntry().getElevation();
    auto city = airport->getBaseEntry().getCity();
    auto state = airport->getBaseEntry().getStateCode();
    auto valid = airport->getBaseEntry().getEffectiveDate().toString();
    std::cout << "Hello from " << name << " airport (" << elevation << " feet) in " << city << ", " << state << " (effective: " << valid << ")" << std::endl;
}
```

## Acknowledgements
This library makes use of the [`tl::optional`](https://github.com/TartanLlama/optional) library written by Sy Brand ([@TartanLlama](https://github.com/TartanLlama) on GitHub).  `tl::optional` is dedicated to the public domain under the CC0 1.0 Universal license.

# License (BSD-3-Clause)

Copyright 2022-2023, Aechelon Technology, Inc.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.