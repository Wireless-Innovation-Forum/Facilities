/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : TsfGenericServicesAccess.hpp									       */
/* Date:  2021-08-04														   */
/* Purpose: TsfGenericServicesAccess.hpp defines the Generic services access   */
/*          class for active services access								   */
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

#ifndef TSF_GENERIC_SERVICES_ACCESS
#define TSF_GENERIC_SERVICES_ACCESS

#include "TsfTypes.hpp"

namespace WInnF_Cpp
{
   namespace TimeService
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
   }    // namespace TimeService
} // namespace WInnF_Cpp
#endif // ifndef TSF_GENERIC_SERVICES_ACCESS
