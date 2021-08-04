/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrExplicitServicesAccess.hpp									   */
/* Date:  2021-08-04														   */
/* Purpose: XcvrExplicitServicesAccess.hpp defines the Explicit services access*/
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

#ifndef XCVR_EXPLICIT_SERVICES_ACCESS
#define XCVR_EXPLICIT_SERVICES_ACCESS

namespace WInnF_Cpp
{
  namespace Transceiver
  {
    namespace ActiveServicesAccess
    {
      // Access to specific active services
      class ExplicitServicesAccess
      {
       public:
         // Provide services
         // Management services group
         virtual Transceiver::Management::Reset* getReset() = 0;
         virtual Transceiver::Management::RadioSilence* getRadioSilence() = 0;

         // BurstControl services group
         virtual Transceiver::BurstControl::DirectCreation* getDirectCreation()          
            = 0;
         virtual Transceiver::BurstControl::RelativeCreation* getRelativeCreation() = 0;
         virtual Transceiver::BurstControl::AbsoluteCreation* getAbsoluteCreation() = 0;
         virtual Transceiver::BurstControl::StrobedCreation* getStrobedCreation() = 0;
         virtual Transceiver::BurstControl::Termination* getTermination() = 0;

         // BasebandSignal services group
         virtual Transceiver::BasebandSignal::RxPacketsLengthControl* getRxPacketsLengthControl() = 0;

         // Tuning services group
         virtual Transceiver::Tuning::InitialTuning* getInitialTuning() = 0;
         virtual Transceiver::Tuning::Retuning* getRetuning() = 0;

         // GainControl services group
         virtual Transceiver::GainControl::GainLocking* getGainLocking() = 0;

         // Strobing services group
         virtual Transceiver::Strobing::ApplicationStrobe* getApplicationStrobe() = 0;

         // Use services
         // Notifications services group
         virtual void setEvents( Transceiver::Notifications::Events* reference) 
           = 0;
         virtual void setErrors( Transceiver::Notifications::Errors* reference) 
           = 0;

         // GainControl services group
         virtual void setGainChanges( Transceiver::GainControl::GainChanges* reference) = 0;
         virtual ~ExplicitServicesAccess() NOEXCEPT {}
      };

      // Access to Tx channels services
      class TxServicesAccess : public ExplicitServicesAccess
      {
       public:
         // Getting references of provide SamplesTransmission instances
         virtual Transceiver::BasebandSignal::SamplesTransmission* getSamplesTransmission( uint16_t channelNumber) = 0;
         virtual ~TxServicesAccess() NOEXCEPT {}
      };

      // Access to Rx channels services
      class RxServicesAccess : public ExplicitServicesAccess
      {
       public:
         // Setting references to use SamplesReception instances
         virtual void setSamplesReception(
            Transceiver::BasebandSignal::SamplesReception* const reference,
            uint16_t channelNumber) = 0;
         virtual ~RxServicesAccess() NOEXCEPT {}
      };
    } // namespace ActiveServicesAccess
  } // namespace Transceiver
} // namespace WInnF_Cpp
#endif // ifndef XCVR_EXPLICIT_SERVICES_ACCESS
