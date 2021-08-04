/*-----------------------------------------------------------------------------*/
/* Distributed by Wireless Innovation Forum                                    */
/*-----------------------------------------------------------------------------*/
/* Title : XcvrExceptions.hpp												   */
/* Date:  2021-08-04														   */
/* Purpose: The XcvrExceptions.hpp file is specified as the header file that   */
/*          declares all useable exceptions.								   */
/*          XcvrExceptions.hpp is used if EXCEPTION_USE is equal to true       */
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

#ifndef XCVR_EXCEPTIONS
#define XCVR_EXCEPTIONS

#include <stdexcept>

#ifndef NOEXCEPT
   #if __cplusplus < 201103L
      #define NOEXCEPT
   #else
      #define NOEXCEPT noexcept
   #endif
#endif

// Exceptions identifiers (section 3.1.19 of [PIM])
namespace WInnF_Cpp
{
  namespace Transceiver
  {
    // General exceptions
    class AlternateException: public std::invalid_argument
    {
     public:
       AlternateException(char const *msg = "") NOEXCEPT
             : ::std::invalid_argument(msg)
       {
       }
       AlternateException(::std::string const &msg) NOEXCEPT
             : ::std::invalid_argument(msg)
       {
       }
    };

    class NoOngoingProcessingException: public std::runtime_error
    {
     public:
       NoOngoingProcessingException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
       NoOngoingProcessingException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
    };

    class StrobeSourceException: public std::invalid_argument
    {
     public:
       StrobeSourceException(char const *msg = "") NOEXCEPT
             : ::std::invalid_argument(msg)
       {
       }
       StrobeSourceException(::std::string const &msg) NOEXCEPT
             : ::std::invalid_argument(msg)
       {
       }
    };

    // Range exceptions
    class MinBlockLengthException: public std::range_error
    {
     public:
       MinBlockLengthException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MinBlockLengthException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxBlockLengthException : public std::range_error
    {
     public:
       MaxBlockLengthException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxBlockLengthException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MinCarrierFreqException : public std::range_error
    {
     public:
       MinCarrierFreqException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MinCarrierFreqException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxCarrierFreqException : public std::range_error
    {
     public:
       MaxCarrierFreqException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxCarrierFreqException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MinFromOngoingException: public std::range_error
    {
     public:
       MinFromOngoingException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MinFromOngoingException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxFromOngoingException: public std::range_error
    {
     public:
       MaxFromOngoingException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxFromOngoingException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MinFromPreviousException: public std::range_error
    {
     public:
       MinFromPreviousException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MinFromPreviousException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxFromPreviousException: public std::range_error
    {
     public:
       MaxFromPreviousException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxFromPreviousException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MinFromStrobeException: public std::range_error
    {
     public:
       MinFromStrobeException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MinFromStrobeException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxFromStrobeException: public std::range_error
    {
     public:
       MaxFromStrobeException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxFromStrobeException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MinGainException: public std::range_error
    {
     public:
       MinGainException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MinGainException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxGainException: public std::range_error
    {
     public:
       MaxGainException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxGainException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxNanoSecondsException: public std::range_error
    {
     public:
       MaxNanoSecondsException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxNanoSecondsException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxRxPacketsLengthException: public std::range_error
    {
     public:
       MaxRxPacketsLengthException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxRxPacketsLengthException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxTuningPresetException: public std::range_error    {
     public:
       MaxTuningPresetException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxTuningPresetException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

    class MaxTxPacketsLengthException: public std::range_error
    {
     public:
       MaxTxPacketsLengthException(char const *msg = "") NOEXCEPT
             : ::std::range_error(msg)
       {
       }
       MaxTxPacketsLengthException(::std::string const &msg) NOEXCEPT
             : ::std::range_error(msg)
       {
       }
    };

     // MILT exceptions
     class AbsoluteMILTException: public std::runtime_error
    {
     public:
       AbsoluteMILTException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
       AbsoluteMILTException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
    };

     class RelativeMILTException: public std::runtime_error
    {
     public:
       RelativeMILTException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
       RelativeMILTException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
    };

     class RetuningMILTException: public std::runtime_error
    {
     public:
       RetuningMILTException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
       RetuningMILTException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
    };

     class Tuning_MILTException: public std::runtime_error
    {
     public:
       Tuning_MILTException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
       Tuning_MILTException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
    };

     class TxPacketsMILTException: public std::runtime_error
    {
     public:
       TxPacketsMILTException(char const *msg = "") NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
       TxPacketsMILTException(::std::string const &msg) NOEXCEPT
             : ::std::runtime_error(msg)
       {
       }
    };

    // Services access exceptions
    class AlreadyConfiguredException: public std::runtime_error
    {
     public:
       AlreadyConfiguredException(char const *msg = "") NOEXCEPT
           : ::std::runtime_error(msg)
       {
       }
       AlreadyConfiguredException(::std::string const &msg) NOEXCEPT
           : ::std::runtime_error(msg)
       {
       }
    };

    class MaxChannelNumberException: public std::range_error
    {
     public:
       MaxChannelNumberException(char const *msg = "") NOEXCEPT
           : ::std::range_error(msg)
       {
       }
       MaxChannelNumberException(::std::string const &msg) NOEXCEPT
           : ::std::range_error(msg)
       {
       }
    };

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
  } // namespace Transceiver
} // namespace WInnF_Cpp

#endif // ifndef XCVR_EXCEPTIONS
