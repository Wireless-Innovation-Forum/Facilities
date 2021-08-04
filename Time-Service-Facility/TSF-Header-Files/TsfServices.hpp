/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : TsfServices.hpp					 		                           */
/* Date:  2021-08-04														   */
/* Purpose: The TsfServices.hpp file is specified as the header file that      */
/*          declares the service interfaces of the Time Service Facility       */
/*	 		PIM Specification. 											       */
/*-----------------------------------------------------------------------------*/
/* In addition to the rights and licenses granted by the undersigned pursuant  */
/* to Section 4 of the IPR Policy, the undersigned hereby agrees as follows: if*/
/* this Code Contribution is included in whole or in part in the Specification */
/* or Other Work Product of the Committee named above, the undersigned hereby  */
/* grants the Forum and its members a non-exclusive, irrevocable, worldwide,   */
/* perpetual, royalty-free license under the undersigned’s copyrights in its   */
/* Code Contribution right to sublicense the right to implementers or users, as*/
/* appropriate, of such Code Contribution to copy, modify, and redistribute    */
/* such Code Contribution or included portion thereof.                         */
/* THIS CODE CONTRIBUTION IS PROVIDED TO THE FORUM BY THE UNDERSIGNED "AS IS"  */
/* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   */
/* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, */
/* ARE DISCLAIMED. IN NO EVENT SHALL THE UNDERSIGNED BE LIABLE FOR ANY DIRECT, */
/* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES          */
/* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;*/
/* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION), HOWEVER CAUSED AND*/
/* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  */
/* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF    */
/* THIS CODE CONTRIBUTION, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
