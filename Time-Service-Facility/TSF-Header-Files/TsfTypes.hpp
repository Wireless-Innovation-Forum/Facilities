/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : TsfTypes.hpp					 				                       */
/* Date:  2021-08-04														   */
/* Purpose: The TsfTypes.hpp file declares the API types of the 			   */
/*          Time Service Facility PIM Specification. 					       */
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

#ifndef TSF_TYPES
#define TSF_TYPES

#if __cplusplus >= 201103L // C++2011
  #include <cstdint>
#else
  #include <stdint.h>
#endif

#include "TsfPlatformProviderAdaptations.hpp"

// Support of exceptions (section 3.8 of [PIM])
#ifdef EXCEPTIONS_SUPPORT
   #include "TsfExceptions.hpp"
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
   namespace TimeService
   {

      // SourceId (signed int in the [PIM], no dedicated type)
      typedef uint8_t SourceId;

      // SpecificTimeId (signed int in the [PIM], no dedicated type)
      typedef uint16_t SpecificTimeId;

      // TimeValue (section 3.4.1 of [PIM])
      struct TimeValue
      {
         uint32_t seconds;     // in seconds
         uint32_t nanoseconds; // in nanoseconds (<1.000.000.000)
      };

      const TimeValue UndefinedTime = {0xFFFFFFFF, 0xFFFFFFFF};

      // TimeUncertainty (section 3.4.2 of [PIM])
      typedef int32_t TimeUncertainty;

      const TimeUncertainty Beyond2SecTimeUncertainty     = 0xFFFFFFF0;
      const TimeUncertainty Beyond4SecTimeUncertainty     = 0xFFFFFFF1;
      const TimeUncertainty Beyond8SecTimeUncertainty     = 0xFFFFFFF2;
      const TimeUncertainty Beyond16SecTimeUncertainty    = 0xFFFFFFF3;
      const TimeUncertainty Beyond32SecTimeUncertainty    = 0xFFFFFFF4;
      const TimeUncertainty Beyond64SecTimeUncertainty    = 0xFFFFFFF5;
      const TimeUncertainty Beyond128SecTimeUncertainty   = 0xFFFFFFF6;
      const TimeUncertainty Beyond256SecTimeUncertainty   = 0xFFFFFFF7;
      const TimeUncertainty Beyond512SecTimeUncertainty   = 0xFFFFFFF8;
      const TimeUncertainty Beyond1024SecTimeUncertainty  = 0xFFFFFFF9;
      const TimeUncertainty Beyond2048SecTimeUncertainty  = 0xFFFFFFFA;
      const TimeUncertainty Beyond4096SecTimeUncertainty  = 0xFFFFFFFB;
      const TimeUncertainty Beyond8192SecTimeUncertainty  = 0xFFFFFFFC;
      const TimeUncertainty Beyond16384SecTimeUncertainty = 0xFFFFFFFD;

      const TimeUncertainty UnknownTimeUncertainty   = 0xFFFFFFFE;
      const TimeUncertainty UndefinedTimeUncertainty = 0xFFFFFFFF;

      // RateUncertainty (section 3.4.3 of [PIM])
      typedef int32_t RateUncertainty;

      const RateUncertainty UnknownRateUncertainty = 0xFFFFFFFF;
   } // namespace TimeService
} // namespace WInnF_Cpp
#endif // #ifndef TSF_TYPES
