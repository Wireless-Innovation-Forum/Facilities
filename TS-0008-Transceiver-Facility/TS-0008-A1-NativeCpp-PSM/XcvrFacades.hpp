/*-----------------------------------------------------------------------------*/
/*    Distributed by Wireless Innovation Forum                                 */
/*    Copyright 2021 SDS Transceiver WG Transceiver Next Task Group.           */
/*    All Rights Reserved.                                                     */
/*    Licensed under the Apache License, Version 2.0 (the "License");          */
/*    you may not use this file except in compliance with the License.         */
/*    You may obtain a copy of the License at                                  */
/*                                                                             */
/* https://github.com/Wireless-Innovation-Forum/Facilities/blob/master/LICENSE */
/*                                                                             */
/*    Unless required by applicable law or agreed to in writing, software      */
/*    distributed under the License is distributed on an "AS IS" BASIS,        */
/*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/*    See the License for the specific language governing permissions and      */
/*    limitations under the License.                                           */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrFacades.hpp                                                     */
/* Date:  25 December 2021                                                     */
/* Version: V2.1.0                                                             */
/* Purpose: The XcvrFacades.hpp file is specified as the header file that      */
/*          declares the Facade class.                                         */
/*          XcvrFacades.hpp has to be directly included by conformant radio    */
/*          applications and it is the only header to be directly included     */
/*-----------------------------------------------------------------------------*/

#ifndef XCVR_FACADES
#define XCVR_FACADES

#include "XcvrPlatformProviderAdaptations.hpp"
#include "XcvrServices.hpp"

#ifdef EXPLICIT_SERVICES_ACCESS
   #include "XcvrExplicitServicesAccess.hpp"
#endif

#ifdef GENERIC_SERVICES_ACCESS
   #include "XcvrGenericServicesAccess.hpp"
#endif

namespace WInnF_Cpp
{
  namespace Transceiver
  {

    // TxFacade (section 2.2.1 of [PSM])
    class TxFacade
    {
     public:
#ifdef EXPLICIT_SERVICES_ACCESS
       virtual ActiveServicesAccess::ExplicitServicesAccess *
         getExplicitServicesAccess() NOEXCEPT = 0; 
#endif

#ifdef GENERIC_SERVICES_ACCESS
       virtual ActiveServicesAccess::GenericServicesAccess *
         getGenericServicesAccess() NOEXCEPT = 0;
#endif
       virtual void activeServicesInitialized()= 0;
       virtual void activeServicesReleased()= 0;

       virtual void getSamplesTransmission(
         uint16_t channelNumber) NOEXCEPT = 0;
       virtual ~TxFacade() NOEXCEPT {}
    };
     // RxFacade (section 2.2.1 of [PSM])
    class RxFacade
    {
     public:
#ifdef EXPLICIT_SERVICES_ACCESS
       virtual ActiveServicesAccess::ExplicitServicesAccess *
         getExplicitServicesAccess() NOEXCEPT = 0; 
#endif

#ifdef GENERIC_SERVICES_ACCESS
       virtual ActiveServicesAccess::GenericServicesAccess *
         getGenericServicesAccess() NOEXCEPT = 0;
#endif

       virtual void activeServicesInitialized()= 0;
       virtual void activeServicesReleased()= 0;

       virtual void setSamplesReception(
         Transceiver::BasebandSignal::SamplesReception* const reference,
         uint16_t channelNumber) NOEXCEPT = 0;
       virtual ~RxFacade() NOEXCEPT {}
     };
  } // namespace Transceiver
} // namespace WInnF_Cpp

#endif // ifndef XCVR_FACADES
