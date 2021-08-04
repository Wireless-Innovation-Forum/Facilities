/*-----------------------------------------------------------------------------*/
/*    Distributed by Wireless Innovation Forum                                 */
/*    Copyright 2021 SDS Project Authors. All Rights Reserved.                 */
/*    Licensed under the Apache License, Version 2.0 (the "License");          */
/*    you may not use this file except in compliance with the License.         */
/*    You may obtain a copy of the License at                                  */
/*                                                                             */
/*        http://www.apache.org/licenses/LICENSE-2.0                           */
/*                                                                             */
/*    Unless required by applicable law or agreed to in writing, software      */
/*    distributed under the License is distributed on an "AS IS" BASIS,        */
/*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/*    See the License for the specific language governing permissions and      */
/*    limitations under the License.                                           */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrExplicitServicesAccess.hpp                                      */
/* Date:  2021-08-04                                                           */
/* Version:  1.0.0                                                             */
/* Purpose: XcvrExplicitServicesAccess.hpp defines the Explicit services access*/
/*          class for active services access                                   */
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
