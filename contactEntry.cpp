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

#include "contactEntry.h"

namespace NASR
{

// ----------------------------------------------------------------------------

namespace APT
{

// ----------------------------------------------------------------------------

const std::string &ContactEntry::getTitle() const
{
    return _data["TITLE"];
}

// ----------------------------------------------------------------------------

const std::string &ContactEntry::getName() const
{
    return _data["NAME"];
}

// ----------------------------------------------------------------------------

const std::string &ContactEntry::getAddress1() const
{
    return _data["ADDRESS1"];
}

// ----------------------------------------------------------------------------

const std::string &ContactEntry::getAddress2() const
{
    return _data["ADDRESS2"];
}

// ----------------------------------------------------------------------------

const std::string &ContactEntry::getTitleCity() const
{
    return _data["TITLE_CITY"];
}

// ----------------------------------------------------------------------------

const std::string &ContactEntry::getState() const
{
    return _data["STATE"];
}

// ----------------------------------------------------------------------------

tl::optional<int> ContactEntry::getZipCode() const
{
    return _data.getOptional<int>("ZIP_CODE");
}

// ----------------------------------------------------------------------------

tl::optional<int> ContactEntry::getZipPlusFour() const
{
    return _data.getOptional<int>("ZIP_PLUS_FOUR");
}

// ----------------------------------------------------------------------------

const std::string &ContactEntry::getPhoneNo() const
{
    return _data["PHONE_NO"];
}

// ----------------------------------------------------------------------------

} // namespace APT

// ----------------------------------------------------------------------------

} // namespace NASR