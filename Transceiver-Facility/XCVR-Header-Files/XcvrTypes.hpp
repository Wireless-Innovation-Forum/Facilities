/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrTypes.hpp					 		                           */
/* Date:  2021-08-04														   */
/* Purpose: The 3.4	XcvrTypes.hpp file declares the API types of the 		   */
/*          Transceiver Facility PIM Specification. 					       */
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


#ifndef XCVR_TYPES
#define XCVR_TYPES

#if __cplusplus >= 201103L // C++2011
  #include <cstdint>
#else
  #include <stdint.h>
#endif

#include "XcvrPlatformProviderAdaptations.hpp"

#if __cplusplus >= 201103L // C++2011
  #include <vector>
#endif // #if __cplusplus >= 201103L

// Support of exceptions (section 3.2 of [PIM])
#ifdef EXCEPTIONS_SUPPORT
  #include "XcvrExceptions.hpp"
#else
// If exceptions are not supported, make sure NOEXCEPT is defined
   #ifndef NOEXCEPT
      #if __cplusplus < 201103L
         #define NOEXCEPT
      #else
         #define NOEXCEPT noexcept
      #endif
   #endif
#endif

namespace WInnF_Cpp
{
  namespace Transceiver
  {
    // Optional types templated declarations
    template<int I> struct OptionalTypes{};
    template<> struct OptionalTypes<Datatype_int16>
    {
      typedef uint16_t IQ;
    };
    template<> struct OptionalTypes<Datatype_int32>
    {
      typedef uint32_t IQ;
      typedef uint32_t Delay;
      typedef uint32_t CarrierFreq;
    };
    template<> struct OptionalTypes<Datatype_int64>
    {
      typedef uint64_t Delay;
      typedef uint64_t CarrierFreq;
    };
    template<> struct OptionalTypes<Datatype_float32>
    {
      typedef float IQ;
    };

    // IQ (section 3.4.11 of [PIM])
    typedef OptionalTypes<XCVR_IQ_TYPE>::IQ IQ;

    // BasebandSample (section 3.4.4 of [PIM])
    struct BasebandSample {IQ valueI; IQ valueQ;};

    // BasebandPacket (section 3.4.2 of [PIM])
    #if __cplusplus == 199711L // C++1998/2003
    // IDL to C++ mapping of "typedef sequence <BasebandSample> BasebandPacket;"
    class BasebandPacket
    {
      public:
      BasebandPacket();
      BasebandPacket( uint32_t max);
      BasebandPacket( uint32_t max, uint32_t length, BasebandSample *bbs, bool release = false);
      ~ BasebandPacket();
      BasebandPacket &operator =(const BasebandPacket &);
      uint32_t maximum() const;
      void length( uint32_t);
      uint32_t length() const;
      BasebandSample &operator []( uint32_t index);
      const BasebandSample &operator []( uint32_t index) const;
      bool release() const;
      void replace( uint32_t max, uint32_t length, BasebandSample *bbs, bool release = false);
      BasebandSample *get_buffer( bool orphan = false);
      const BasebandSample *get_buffer() const;
      static BasebandSample *allocbuff( uint32_t nelems);
      static void freebuff(BasebandSample *);
    };
    #elif __cplusplus>= 201103L // C++2011
      typedef std::vector<BasebandSample> BasebandPacket;
    #endif // #if __cplusplus == 199711L // C++1998/2003

    // BlockLength (section 3.4.3 of [PIM])
    typedef uint32_t BlockLength;
    const BlockLength UndefinedBlockLength = 0xFFFFFFFF;

    // BurstNumber (section 3.4.5 of [PIM])
    typedef uint32_t BurstNumber;

    // CarrierFreq (section 3.4.6 of [PIM]), in Hz
    typedef OptionalTypes<XCVR_CARRIER_FREQ_TYPE>::CarrierFreq CarrierFreq;

    #if XCVR_CARRIER_FREQ_TYPE == int32
      const CarrierFreq UndefinedCarrierFreq = 0xFFFFFFFF;
    #elif XCVR_CARRIR_FREQ_TYPE == int64
      const CarrierFreq UndefinedCarrierFreq = 0x7FFFFFFFFFFFFFFF;
    #else
      #error const XCVR_CARRIER_FREQ_TYPE must be equal to "int32" or "int64"
    #endif // #if XCVR_CARRIER_FREQ_TYPE == int32

    // Delay (section 3.4.7 of [PIM]), in ns
    typedef OptionalTypes<XCVR_DELAY_TYPE>::Delay Delay;
  
    #if XCVR_DELAY_TYPE == int32
      const Delay UndefinedDelay = 0xFFFFFFFF;
    #elif XCVR_DELAY_TYPE == int64
      const Delay UndefinedDelay = 0x7FFFFFFFFFFFFFFF;
    #else
      #error cont XCVR_DELAY_TYPE must be equal to "int32" or "int64"
    #endif // #if XCVR_DELAY_TYPE == int32

    // Error (section 3.4.8 of [PIM])
    #if __cplusplus == 199711L // C++1998/2003
    enum Error
    {
    #elif __cplusplus >= 201103L // C++2011
    enum class Error 
    {
    #endif // #if __cplusplus == 199711L // C++1998/2003
      DelayedTuningError,
      TuningTimeoutError,
      DelayedFirstSampleError,
      FirstSampleTimeoutError,
      TransmissionUnderflowError,
      ReceptionOverflowError,
      ShorterTransmittedBlockError,
      LongerTransmittedBlockError,
      DelayedTuning,
      TuningTimeout,
      DelayedFirstSample,
      FirstSampleTimeout,
      TransmissionUnderflow,
      ReceptionOverflow,
      ShorterTransmittedBlock,
      LongerTransmittedBlock
    };

    // Event (section 3.4.9 of [PIM])
    #if __cplusplus == 199711L // C++1998/2003
    enum Event
    {
    #elif __cplusplus >= 201103L // C++2011
    enum class Event
    {
    #endif // #if __cplusplus == 199711L // C++1998/2003
      ProcessingStartEvent,
      ProcessingStopEvent,
      SilenceStartEvent,
      SilenceStopEvent
      };

    // Gain (section 3.4.10 of [PIM]), in 1/10 dB
    typedef int16_t Gain;
    const Gain UndefinedGain = 0xFFFF;

    // MetaData (section 3.4.12 of [PIM])
    // Declared in XcvrUserAdaptations.hpp

    // PacketLength (section 3.4.13 of [PIM])
    typedef uint32_t PacketLength;

    // SampleNumber (section 3.4.14 of [PIM])
    typedef uint32_t SampleNumber;

    // StrobeSource (section 3.4.15 of [PIM])
    enum StrobeSource
    {
      ApplicationStrobe,
      TimeRef_PPS,
      GNSS_PPS,
      UserStrobe1,
      UserStrobe2,
      UserStrobe3,
      UserStrobe4
    };

    // TimeSpec (section 3.4.16 of [PIM])
    struct TimeSpec
    {
      uint32_t seconds;             // in seconds
      uint32_t nanoseconds;
    };       // in nanoseconds (<1.000.000.000)
    const TimeSpec UndefinedTimeSpec = {0xFFFFFFFF, 0xFFFFFFFF};

    // TuningPreset (section 3.4.17 of [PIM])
    typedef uint16_t TuningPreset;
    const TuningPreset UndefinedTuningPreset = 0xFFFF;
  }
}

#endif // #ifndef XCVR_TYPES
