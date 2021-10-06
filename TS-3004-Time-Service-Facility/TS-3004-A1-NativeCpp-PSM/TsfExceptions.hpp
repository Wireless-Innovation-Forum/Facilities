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
/* Title : TsfExceptions.hpp                                                   */
/* Date:  25 December 2021                                                     */
/* Version:  V1.1.0                                                            */
/* Purpose: The TsfExceptions.hpp file is specified as the header file that    */
/*          declares all useable exceptions.                                   */
/*          TsfExceptions.hpp is used if EXCEPTION_USE is equal to true        */
/*-----------------------------------------------------------------------------*/

#ifndef TSF_EXCEPTIONS
#define TSF_EXCEPTIONS

#include <stdexcept>

#ifndef NOEXCEPT
   #if __cplusplus < 201103L
      #define NOEXCEPT
   #else
      #define NOEXCEPT noexcept
   #endif
#endif

// Exceptions identifiers (section 3.2 of [PIM])
namespace WInnF_Cpp
{
   namespace TimeService
   {
      // General exceptions
      class FutureTimeStampException : public std::invalid_argument
      {
       public:
         FutureTimeStampException(char const *msg = "") NOEXCEPT
             : ::std::invalid_argument(msg)
         {
         }
         FutureTimeStampException(::std::string const &msg) NOEXCEPT
             : ::std::invalid_argument(msg)
         {
         }
      };

      // Range exceptions
      class InvalidSpecificTimeId : public std::range_error
      {
       public:
         InvalidSpecificTimeId(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
         {
         }
         InvalidSpecificTimeId(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
         {
         }
      };

      // Services access exceptions – specified by Native C++ Mapping Rules
      class UnavailableServiceException : public std::runtime_error
      {
       public:
         UnavailableServiceException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
         {
         }
         UnavailableServiceException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
         {
         }
      };
      class InvalidReferenceException : public std::runtime_error
      {
       public:
         InvalidReferenceException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
         {
         }
         InvalidReferenceException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
         {
         }
      };
   } // namespace TimeService
} // namespace WInnF_Cpp

#endif // ifndef TSF_EXCEPTIONS
