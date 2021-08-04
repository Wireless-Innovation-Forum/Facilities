/*-----------------------------------------------------------------------------*/
/*    Distributed by Wireless Innovation Forum                                 */
/*    Copyright 2021 SDS Project Authors. All Rights Reserved.				   */
/*    Licensed under the Apache License, Version 2.0 (the "License");		   */
/*    you may not use this file except in compliance with the License.		   */
/*    You may obtain a copy of the License at                                  */
/*                                                                             */
/*        http://www.apache.org/licenses/LICENSE-2.0						   */
/*																			   */
/*    Unless required by applicable law or agreed to in writing, software	   */
/*    distributed under the License is distributed on an "AS IS" BASIS,		   */
/*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/*    See the License for the specific language governing permissions and      */
/*    limitations under the License.										   */
/*-----------------------------------------------------------------------------*/
/* Title : TsfFacade.hpp								                	   */
/* Date:  2021-08-04														   */
/* Version:  1.0.0															   */
/* Purpose: The TsfFacade.hpp file is specified as the header file that        */
/*          declares the Facade class. 										   */
/*          TsfFacade.hpp has to be directly included by conformant radio      */
/*          applications and it is the only header to be directly included     */
/*-----------------------------------------------------------------------------*/

#ifndef TSF_FACADE
#define TSF_FACADE

#include "TsfPlatformProviderAdaptations.hpp"
#include "TsfServices.hpp"

#ifdef EXPLICIT_SERVICES_ACCESS
   #include "TsfExplicitServicesAccess.hpp"
#endif

#ifdef GENERIC_SERVICES_ACCESS
   #include "TsfGenericServicesAccess.hpp"
#endif

namespace WInnF_Cpp
{
   namespace TimeService
   {

      // Facade (section 2.2 of [PSM])
      class Facade
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
         virtual ~Facade() NOEXCEPT {}
      };
   } // namespace TimeService
} // namespace WInnF_Cpp

#endif // ifndef TSF_FACADE
