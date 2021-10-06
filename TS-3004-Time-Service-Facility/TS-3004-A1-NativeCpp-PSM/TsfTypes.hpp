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
/* Title : TsfTypes.hpp                                                        */
/* Date:  25 December 2021                                                     */
/* Version:  V1.1.0                                                            */
/* Purpose: The TsfTypes.hpp file declares the API types of the                */
/*          Time Service Facility PIM Specification.                           */
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
