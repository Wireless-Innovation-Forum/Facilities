/*-----------------------------------------------------------------------------*/
/*    Distributed by Wireless Innovation Forum                                 */
/*    Copyright 2021 SDS Project Authors. All Rights Reserved.				   */
/*    Licensed under the Apache License, Version 2.0 (the "License");		   */
/*    you may not use this file except in compliance with the License.		   */
/*    You may obtain a copy of the License at                                  */
/*                                                                             */
/*        http://www.apache.org/licenses/LICENSE-2.0						   */
/*																			   */
/*    Unless required by applicable law or agreed to in writing, software	   */
/*    distributed under the License is distributed on an "AS IS" BASIS,		   */
/*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/*    See the License for the specific language governing permissions and      */
/*    limitations under the License.										   */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrPlatformProviderAdaptations.hpp					 		       */
/* Date:  2021-08-04														   */
/* Purpose: The XcvrPlatformProviderAdaptations.hpp file is specified as the   */
/*          header file specifying the ActiveServicesAccess property, Tx or Rx */
/*          metadata if needed and Interface declaration properties.           */
/*          XcvrPlatformProviderAdaptations.hpp has to be adapted by platform  */
/*          providers only in areas marked with *** PROVIDER-ADAPTATION ***.   */
/*-----------------------------------------------------------------------------*/

// Specifies user-adaptations:
//   1 Interface declaration properties, specified by section 4.5 of [PIM]
//   2 Tx or Rx metadata, if needed,
//   3 ACTIVE_SERVICES_ACCESS property, specified by section 3.5 of [PSM]

#ifndef XCVR_USER_ADAPTATIONS
#define XCVR_USER_ADAPTATIONS

// ACTIVE_SERVICES_ACCESS
// *** PROVIDER-ADAPTATION ***
#define EXPLICIT_SERVICES_ACCESS // comment if EXPLICIT is not supported
#define GENERIC_SERVICES_ACCESS  // comment if GENERIC is not supported
#define EXCEPTIONS_SUPPORT	    // comment if EXCEPTIONS is not supported

// 1 Interface declaration properties
namespace WInnF_Cpp
{
  namespace Transceiver
  {
    // PIM enumerated identifiers : int16, int32, int64, float32
    // Datatype_ prefix for disambiguation vs. <cstdint> types
    enum{ Datatype_int16, Datatype_int32, Datatype_int64, Datatype_float32};

    // *** PROVIDER-ADAPTATION *** CARRIER_FREQ_TYPE value
    const int XCVR_CARRIER_FREQ_TYPE = Datatype_int32; // Specify "Datatype_int32" or "Datatype_int64"

    // *** PROVIDER-ADAPTATION *** DELAY_TYPE value
    const int XCVR_DELAY_TYPE = Datatype_int32; // Specify "Datatype_int32" or "Datatype_int64"

    // *** PROVIDER-ADAPTATION *** IQ_TYPE value
    const int XCVR_IQ_TYPE = Datatype_int32;  // Specify "Datatype_int16", "Datatype_int32" or " Datatype_float32"
  }
}

// TX_META_DATA and RX_META_DATA values
// *** PROVIDER-ADAPTATION *** XCVR_TX_META_DATA value
// #define XCVR_TX_META_DATA FALSE // Uncomment if FALSE
#if XCVR_TX_META_DATA == TRUE
namespace WInnF_Cpp
{
  namespace Transceiver
  {
    typedef struct TxMetaData
    {
      // *** PROVIDER-ADAPTATION ***
      // Specify declaration of Tx metadata fields
    };
  }
}
#endif // #if XCVR_TX_META_DATA == TRUE

// *** PROVIDER-ADAPTION *** XCVR_RX_META_DATA value
// #define XCVR_RX_META_DATA FALSE // Uncomment if FALSE
#if XCVR_RX_META_DATA == TRUE
namespace WInnF_Cpp
{
  namespace Transceiver
  {
    typedef struct RxMetaData
    {
      // *** USER-ADAPTATION ***
      // Specify declaration of Rx metadata fields
    };
  }
}
#endif // #if XCVR_RX_META_DATA == TRUE

#endif // #ifndef XCVR_USER_ADAPTATIONS
