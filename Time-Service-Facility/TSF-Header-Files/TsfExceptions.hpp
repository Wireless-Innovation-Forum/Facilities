/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : TsfExceptions.hpp												   */
/* Date:  2021-08-04														   */
/* Purpose: The TsfExceptions.hpp file is specified as the header file that    */
/*          declares all useable exceptions.								   */
/*          TsfExceptions.hpp is used if EXCEPTION_USE is equal to true        */
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
