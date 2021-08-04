/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrServices.hpp					 		                           */
/* Date:  2021-08-04														   */
/* Purpose: The XcvrServices.hpp file is specified as the header file that     */
/*          declares the service interfaces of the Transceiver Facility        */
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

#ifndef XCVR_SERVICES
#define XCVR_SERVICES

#if __cplusplus < 199711L
  #error C++ version must be C++98/2003 or later
#endif

// XCVR_PIM_VERSION property (section 1.2 of [PSM])
#define XCVR_API_VERSION 0x020000L // For V2.0.0

#include "XcvrTypes.hpp"

namespace WInnF_Cpp
{
  namespace Transceiver
  {
    namespace Management
    {
      // Management::Reset (section 2.4.1.1 of [PIM])
      class Reset
      {
       public:
         virtual void reset() = 0;
         virtual ~Reset() NOEXCEPT {}
      };

      // Management::RadioSilence (section 2.4.1.2 of [PIM])
      class RadioSilence
      {
       public:
         virtual void startRadioSilence() = 0;
         virtual void stopRadioSilence() = 0;
         virtual ~RadioSilence() NOEXCEPT {}
      };
    }

    namespace BurstControl
    {
      // BurstControl::DirectCreation (section 2.4.2.1 of [PIM])
      class DirectCreation
      {
       public:
         virtual void startBurst(
           BlockLength requestedLength) = 0;
         virtual ~DirectCreation() NOEXCEPT {}
      };

      // BurstControl::RelativeCreation (section 2.4.2.2 of [PIM])
      class RelativeCreation
      {
       public:
         virtual void scheduleRelativeBurst(
           bool requestedAlternate,
           Delay requestedDelay,
           BlockLength requestedLength) = 0;
         virtual ~RelativeCreation() NOEXCEPT {}
      };

      // BurstControl::AbsoluteCreation (section 2.4.2.3 of [PIM])
      class AbsoluteCreation
      {
       public:
         virtual void scheduleAbsoluteBurst(
           TimeSpec requestedStartTime,
           BlockLength requestedLength) = 0;
         virtual ~AbsoluteCreation() NOEXCEPT {}
      };

      // BurstControl::StrobedCreation (section 2.4.2.4 of [PIM])
      class StrobedCreation
      {
       public:
         virtual void scheduleStrobedBurst(
           StrobeSource requestedStrobeSource,
           Delay requestedDelay,
           BlockLength requestedLength) = 0;
           virtual ~StrobedCreation() NOEXCEPT {}
      };

      // BurstControl::Termination (section 2.4.2.5 of [PIM])
      class Termination
      {
       public:
         virtual void setBlockLength(
           BlockLength requestedLength) = 0;
         virtual void stopBurst() = 0;
         virtual ~Termination() NOEXCEPT {}
      };
    }

    namespace BasebandSignal
    {
      // BasebandSignal::SamplesReception (section 2.4.3.1 of [PIM])
      class SamplesReception
      {
       public:
       #if XCVR_RX_META_DATA == TRUE
         virtual void pushRxPacket(
           BasebandPacket rxPacket,
           bool endOfBlock,
           RxMetaData rxMetaData) = 0;
       #else
         virtual void pushRxPacket(
           BasebandPacket rxPacket,
           bool endOfBlock) = 0;
       #endif // #if XCVR_TX_META_DATA == TRUE
         virtual ~SamplesReception() NOEXCEPT {}
    };

      // BasebandSignal::SamplesTransmission (section 2.4.3.2 of [PIM])
      class SamplesTransmission
      {
       public:
       #if TX_META_DATA == TRUE
         virtual void pushTxPacket(
           BasebandPacket txPacket,
           bool endOfBlock,
           TxMetaData txMetaData) = 0;
       #else
         virtual void pushTxPacket(
           BasebandPacket txPacket,
           bool endOfBlock) = 0;
       #endif // #if TX_META_DATA == TRUE
         virtual ~SamplesTransmission() NOEXCEPT {}
      };

      // BasebandSignal::RxPacketsLengthControl (section 2.4.3.3 of [PIM])
      class RxPacketsLengthControl
      {
       public:
         virtual void setRxPacketsLength(
           PacketLength requestedLength) = 0;
         virtual ~RxPacketsLengthControl() NOEXCEPT {}
      };
    }

    namespace Tuning
    {
      // Tuning::InitialTuning (section 2.4.4.1 of [PIM])
      class InitialTuning
      {
       public:
         virtual void setTuning(
           TuningPreset requestedPreset,
           CarrierFreq requestedFrequency,
           Gain requestedGain,
           BurstNumber requestedBurstNumber) = 0;
         virtual ~InitialTuning() NOEXCEPT {}
      };

      // Tuning::Retuning (section 2.4.4.2 of [PIM])
      class Retuning
      {
       public:
         virtual void retune(
           CarrierFreq requestedFrequency,
           Gain requestedGain,
           Delay requestedDelay) = 0;
         virtual ~Retuning() NOEXCEPT {}
      };
    }

    namespace Notifications
    {
      // Notifications::Events (section 2.4.5.1 of [PIM])
      class Events
      {
       public:
         virtual void notifyEvent(
           Event notifiedEvent) = 0;
         virtual ~Events() NOEXCEPT {}
      };

      // Notifications::Errors (section 2.4.5.2 of [PIM])
      class Errors
      {
       public:
         virtual void notifyError(
           Error notifiedError) = 0;
         virtual ~Errors() NOEXCEPT {}
      };
    }

    namespace GainControl
    {
      // GainControl::GainChanges (section 2.4.6.1 of [PIM])
      class GainChanges
      {
       public:
         virtual void indicateGain(
          Gain newGain,
          SampleNumber firstValidSample) = 0;
         virtual ~GainChanges() NOEXCEPT {}
      };

      // GainControl::GainLocking (section 2.4.6.2 of [PIM])
      class GainLocking
      {
       public:
         virtual void lockGain() = 0;
         virtual void unlockGain() = 0;
         virtual ~GainLocking() NOEXCEPT {}
      };
    }

    namespace TransceiverTime
    {
      // TransceiverTime::TimeAccess (section 2.4.7.1 of [PIM])
      class TimeAccess
      {
       public:
         virtual void getCurrentTime(
           TimeSpec* currentTime) const = 0;
         virtual void getLastStartTime(
           TimeSpec* lastStartTime,
           BurstNumber* lastBurstNumber) const = 0;
         virtual ~TimeAccess() NOEXCEPT {}
      };
    }

    namespace Strobing 
    {
      // Strobing::ApplicationStrobe (section 2.4.8.1 of [PIM])
      class ApplicationStrobe
      {
       public:
         virtual void triggerStrobe(void);
         virtual ~ApplicationStrobe() NOEXCEPT {}
      };
    }
  }
}

#endif // ifndef XCVR_SERVICES
