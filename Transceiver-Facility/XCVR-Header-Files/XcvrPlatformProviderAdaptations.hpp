/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrPlatformProviderAdaptations.hpp					 		       */
/* Date:  2021-08-04														   */
/* Purpose: The XcvrPlatformProviderAdaptations.hpp file is specified as the   */
/*          header file specifying the ActiveServicesAccess property, Tx or Rx */
/*          metadata if needed and Interface declaration properties.           */
/*          XcvrPlatformProviderAdaptations.hpp has to be adapted by platform  */
/*          providers only in areas marked with *** PROVIDER-ADAPTATION ***.   */
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
