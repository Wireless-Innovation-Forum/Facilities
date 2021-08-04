/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrFacades.hpp								                	   */
/* Date:  2021-08-04														   */
/* Purpose: The XcvrFacades.hpp file is specified as the header file that      */
/*          declares the Facade class. 										   */
/*          XcvrFacades.hpp has to be directly included by conformant radio    */
/*          applications and it is the only header to be directly included     */
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

#ifndef XCVR_FACADES
#define XCVR_FACADES

#include "XcvrPlatformProviderAdaptations.hpp"
#include "XcvrServices.hpp"

#ifdef EXPLICIT_SERVICES_ACCESS
   #include "XcvrExplicitServicesAccess.hpp"
#endif

#ifdef GENERIC_SERVICES_ACCESS
   #include "XcvrGenericServicesAccess.hpp"
#endif

namespace WInnF_Cpp
{
  namespace Transceiver
  {

    // TxFacade (section 2.2.1 of [PSM])
    class TxFacade
    {
     public:
#ifdef EXPLICIT_SERVICES_ACCESS
       virtual ActiveServicesAccess::ExplicitServicesAccess *
         getExplicitServicesAccess() NOEXCEPT = 0; 
#endif

#ifdef GENERIC_SERVICES_ACCESS
       virtual ActiveServicesAccess::GenericServicesAccess *
         getGenericServicesAccess() NOEXCEPT = 0;
#endif
       virtual void activeServicesInitialized()= 0;
       virtual void activeServicesReleased()= 0;

       virtual void getSamplesTransmission(
         uint16_t channelNumber) NOEXCEPT = 0;
       virtual ~TxFacade() NOEXCEPT {}
    };
     // RxFacade (section 2.2.1 of [PSM])
    class RxFacade
    {
     public:
#ifdef EXPLICIT_SERVICES_ACCESS
       virtual ActiveServicesAccess::ExplicitServicesAccess *
         getExplicitServicesAccess() NOEXCEPT = 0; 
#endif

#ifdef GENERIC_SERVICES_ACCESS
       virtual ActiveServicesAccess::GenericServicesAccess *
         getGenericServicesAccess() NOEXCEPT = 0;
#endif

       virtual void activeServicesInitialized()= 0;
       virtual void activeServicesReleased()= 0;

       virtual void setSamplesReception(
         Transceiver::BasebandSignal::SamplesReception* const reference,
         uint16_t channelNumber) NOEXCEPT = 0;
       virtual ~RxFacade() NOEXCEPT {}
     };
  } // namespace Transceiver
} // namespace WInnF_Cpp

#endif // ifndef XCVR_FACADES
