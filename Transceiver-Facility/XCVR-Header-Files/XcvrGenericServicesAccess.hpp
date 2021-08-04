/*-----------------------------------------------------------------------------*/
/*    Distributed by Wireless Innovation Forum                                 */
/*    Copyright 2021 SDS Project Authors. All Rights Reserved.                 */
/*    Licensed under the Apache License, Version 2.0 (the "License");          */
/*    you may not use this file except in compliance with the License.         */
/*    You may obtain a copy of the License at                                  */
/*                                                                             */
/*        http://www.apache.org/licenses/LICENSE-2.0                           */
/*                                                                             */
/*    Unless required by applicable law or agreed to in writing, software      */
/*    distributed under the License is distributed on an "AS IS" BASIS,        */
/*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/*    See the License for the specific language governing permissions and      */
/*    limitations under the License.                                           */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrGenericServicesAccess.hpp                                       */
/* Date:  2021-08-04                                                           */
/* Version: 2.0.0                                                              */
/* Purpose: XcvrGenericServicesAccess.hpp defines the Generic services access  */
/*          class for active services access                                   */
/*-----------------------------------------------------------------------------*/

#ifndef XCVR_GENERIC_SERVICES_ACCESS
#define XCVR_GENERIC_SERVICES_ACCESS

#include "XcvrTypes.hpp"

namespace WInnF_Cpp
{
  namespace Transceiver
  {
    namespace ActiveServicesAccess
    {
      class Object
      {
       public:
         virtual ~Object() NOEXCEPT {}
      };

      class GenericServicesAccess
      {
       public:
         // Access to active provide services
         virtual Object *getProvideService(
           const char *ServiceName) = 0;

         // Access to active use services
         virtual void setUseService(const char *ServiceName,
                                    Object *    provider) = 0;

         virtual ~GenericServicesAccess() NOEXCEPT {}
      };
    } // namespace ActiveServicesAccess
  } // namespace Transceiver
} // namespace WInnF_Cpp
#endif // ifndef XCVR_GENERIC_SERVICES_ACCESS
