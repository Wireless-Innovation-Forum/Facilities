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
/* Title : TsfExplicitServicesAccess.hpp                                       */
/* Date:  2021-08-04                                                           */
/* Version:  1.0.0                                                             */
/* Purpose: TsfExplicitServicesAccess.hpp defines the Explicit services access */
/*          class for active services access                                   */
/*-----------------------------------------------------------------------------*/

#ifndef TSF_EXPLICIT_SERVICES_ACCESS
#define TSF_EXPLICIT_SERVICES_ACCESS

namespace WInnF_Cpp
{
   namespace TimeService
   {
      namespace ActiveServicesAccess
      {
         // Access to specific active services
         class ExplicitServicesAccess
         {
          public:
            // Provide services instances
            // TerminalTime services group
            virtual TerminalTime::TerminalTimeAccess *getTerminalTimeAccess()
                = 0;

            // SystemTime services group
            virtual SystemTime::SystemTimeAccess *getSystemTimeAccess() = 0;
            virtual SystemTime::StandardTimeProvision *
            getStandardTimeProvision() = 0;

            // SpecificTimes services group
            virtual SpecificTimes::SpecificTimeHandling *
            getSpecificTimeHandling() = 0;

            // Use services
            // StandardTimes services group
            virtual void setReferencesNotification(
                StandardTimes::ReferencesNotification *reference) = 0;

            // SpecificTimes services group
            virtual void setSettingsNotification(
                SpecificTimes::SettingsNotification *reference) = 0;

            virtual ~ExplicitServicesAccess() NOEXCEPT {}
         };
      } // namespace ActiveServicesAccess
   } // namespace TimeService
} // namespace WInnF_Cpp
#endif // ifndef TSF_EXPLICIT_SERVICES_ACCESS
