/*-----------------------------------------------------------------------------*/
/*    Distributed by Wireless Innovation Forum                                 */
/*    Copyright 2021 SDS Harmonized Timing Service Task Group.                 */
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
/* Title : TsfServices.hpp                                                     */
/* Date:  25 December 2021                                                     */
/* Version:  V1.1.0                                                            */
/* Purpose: The TsfServices.hpp file is specified as the header file that      */
/*          declares the service interfaces of the Time Service Facility       */
/*          PIM Specification.                                                 */
/*-----------------------------------------------------------------------------*/

#ifndef TSF_SERVICES
#define TSF_SERVICES

#if __cplusplus < 199711L
   #error C++ version must be C++98 or later
#endif

// TsfPimVersion property (section 1.5 of [PSM])
#define TsfPimVersion 0x010000L // For V1.0.0

#include "TsfTypes.hpp"

namespace WInnF_Cpp
{
   namespace TimeService
   {
      namespace TerminalTime
      {
         // TerminalTime::TerminalTimeAccess (section 3.1.2 of [PIM])
         class TerminalTimeAccess
         {
          public:
            virtual void getTerminalTime(
                TimeValue *terminalTime) const NOEXCEPT = 0;
            virtual void getTerminalTimeRateUncertainty(
                RateUncertainty *terminalTimeRateUncertainty)
                const NOEXCEPT = 0;
            virtual ~TerminalTimeAccess() NOEXCEPT {}
         };
      } // namespace TerminalTime

      namespace SystemTime
      {
         // SystemTime::SystemTimeAccess (section 3.1.3 of [PIM])
         class SystemTimeAccess
         {
          public:
            virtual void getCurrentTAI(
                TimeValue *      currentTAI,
                TimeValue *      timeStamp,
                TimeUncertainty *timeUncertainty) const NOEXCEPT = 0;
            virtual void getCurrentUTC(
                TimeValue *      currentUTC,
                TimeValue *      timeStamp,
                TimeUncertainty *timeUncertainty) const NOEXCEPT = 0;
            virtual void getLastUpdateTAI(
                TimeValue *      lastUpdateTAI,
                TimeValue *      timeStamp,
                TimeUncertainty *timeUncertainty) const NOEXCEPT = 0;
            virtual void getLastUpdateUTC(
                TimeValue *      lastUpdateUTC,
                TimeValue *      timeStamp,
                TimeUncertainty *timeUncertainty) const NOEXCEPT = 0;
            virtual ~SystemTimeAccess() NOEXCEPT {}
         };

         // SystemTime::StandardTimeProvision (section 3.1.4 of [PIM])
         class StandardTimeProvision
         {
          public:
            virtual void provideTAI(TimeValue       providedTAI,
                                    TimeValue       timeStamp,
                                    TimeUncertainty timeUncertainty,
                                    SourceId        sourceId) = 0;
            virtual void provideUTC(TimeValue       providedUTC,
                                    TimeValue       timeStamp,
                                    TimeUncertainty timeUncertainty,
                                    SourceId        sourceId) = 0;
            virtual ~StandardTimeProvision() NOEXCEPT {}
         };
      } // namespace SystemTime

      namespace StandardTimes
      {
         // StandardTimes::ReferencesNotification (section 3.1.5 of [PIM])
         class ReferencesNotification
         {
          public:
            virtual void notifyStandardTimeReference(
                TimeValue       referenceTAI,
                TimeValue       referenceUTC,
                TimeValue       timeStamp,
                TimeUncertainty timeUncertainty,
                SourceId        sourceId) NOEXCEPT = 0;
            virtual ~ReferencesNotification() NOEXCEPT {}
         };
      } // namespace StandardTimes

      namespace SpecificTimes
      {
         // SpecificTimes::SpecificTimeHandling (section 3.1.6 of [PIM])
         class SpecificTimeHandling
         {
          public:
            virtual void setSpecificTime(SpecificTimeId  specificTimeId,
                                         TimeValue       specificTime,
                                         TimeValue       timeStamp,
                                         TimeUncertainty timeUncertainty) = 0;
            virtual void getSpecificTime(
                SpecificTimeId   specificTimeId,
                TimeValue *      specificTime,
                TimeValue *      timeStamp,
                TimeUncertainty *timeUncertainty) const = 0;
            virtual ~SpecificTimeHandling() NOEXCEPT {}
         };


         // SpecificTimes::SettingsNotification (section 3.1.7 of [PIM])
         class SettingsNotification
         {
          public:
            virtual void notifySpecificTimeSetting(
                SpecificTimeId  specificTimeId,
                TimeValue       specificTime,
                TimeValue       timeStamp,
                TimeUncertainty timeUncertainty) NOEXCEPT = 0;
            virtual ~SettingsNotification() NOEXCEPT {}
         };
      } // namespace SpecificTimes
   }    // namespace TimeService
} // namespace WInnF_Cpp

#endif // ifndef TSF_SERVICES
