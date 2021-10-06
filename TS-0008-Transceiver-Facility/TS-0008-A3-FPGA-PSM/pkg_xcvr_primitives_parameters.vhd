-- Distributed by Wireless Innovation Forum
-- Copyright 2021 SDS Transceiver WG Transceiver Next Task Group.
-- All Rights Reserved.
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
-- https://github.com/Wireless-Innovation-Forum/Facilities/blob/master/LICENSE
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
--
-- Title : pkg_xcvr_primitives_parameters.vhd
-- Date:  25 December 2021
-- Version: V2.1.0
-- Purpose: The file pkg_xcvr_primitives_parameters.vhd is defined as the 
--          standard VHDL package for the parameters of the FPGA PSM specification
--          primitives.
--          For primitives with optional implementation of exceptions specified by 
--          the PIM specification, the corresponding dedicated 1-bit RTL signal 
--          is not specified in the VDHL file
--

library ieee;
use ieee.std_logic_1164.all;

library xcvr_api;
use xcvr_api.pkg_xcvr_api_types.all;
use xcvr_api.pkg_xcvr_metadata_types.all;

package pkg_xcvr_primitives_parameters is

  -- Management::Reset ([PIM] §2.4.1.1)
  -- reset() has no parameters 
  -- PIM Exceptions: none

  -- Management::RadioSilence ([PIM] §2.4.1.2)
  -- startRadioSilence() and stopRadioSilence() have no parameters
  -- PIM Exceptions: none

  -- BurstControl::DirectCreation ([PIM] §2.4.2.1)
  -- startBurst()
  type start_burst_in is record
    requested_length: block_length_type;
  end record; 
  -- PIM Exceptions: MinBlockLength, MaxBlockLength

  -- BurstControl::RelativeCreation ([PIM] §2.4.2.2)
  -- scheduleRelativeBurst()
  type schedule_relative_burst_in_type is record
    requested_alternate : std_logic;
    requested_delay : delay_type;
    requested_length : block_length_type;
  end record; 
  -- PIM Exceptions: NoAlternateReferencing, MinFromPrevious, MaxFromPrevious,
  -- MinBlockLength, MaxBlockLength, RelativeMILT 

  -- BurstControl::AbsoluteCreation ([PIM] §2.4.2.3)
  -- scheduleAbsoluteBurst()
  type schedule_absolute_burst_in_type is record
    requested_start_time : time_spec_type;
    requested_length : block_length_type;
  end record; 
  -- PIM Exceptions: MaxNanoseconds, MinBlockLength, MaxBlockLength,
  -- AbsoluteMILT

  -- BurstControl::StrobedCreation ([PIM] §2.4.2.4)
  -- scheduleStrobedBurst()
  type schedule_strobed_burst_in_type is record
    requested_strobe_source : strobe_source_type;
    requested_delay : delay_type;
    requested_length : block_length_type;
  end record; 
  -- PIM Exceptions: StrobeSource, MinFromStrobe, MaxFromStrobe,
  -- MinBlockLength, MaxBlockLength

  -- BurstControl::Termination ([PIM] §2.4.2.5)
  -- setBlockLength()
  type set_block_length_in_type is record
    requested_length : block_length_type;
  end record; 
  -- PIM Exceptions: NoOngoingProcessing, MinBlockLength, MaxBlockLength

  -- stopBurst() has no parameter 
  -- PIM Exceptions: NoOngoingProcessing

  -- BasebandSignal::SamplesReception ([PIM] §2.4.3.1)
  -- pushRxBlock(), replacing pushRxPacket()
  type push_rx_block_in_sample_type is record
    rx_baseband_sample : baseband_sample_type;
  end record;
  type push_rx_block_in_metadata_type is record
    rx_meta_data : rx_metadata_type;
  end record; 
  -- PIM Exceptions: none

  -- BasebandSignal::SamplesTransmission ([PIM] §2.4.3.2)
  -- pushTxBlock(), replacing pushTxPacket() 
  type push_tx_block_in_sample_type is record
    tx_baseband_sample : baseband_sample_type;
  end record; 
  type push_tx_block_in_metadata_type is record
    tx_meta_data : tx_metadata_type;
  end record; 
  -- PIM Exceptions: MaxTxPacketsLength, TxPacketsMILT

  -- BasebandSignal::RxPacketsLengthControl ([PIM] §2.4.3.3): not mapped
  -- setRxPacketsLength(): not mapped
  
  -- Tuning::InitialTuning ([PIM] §2.4.4.1)
  -- setTuning()
  type set_tuning_in_type is record
    requested_preset : tuning_preset_type;
    requested_frequency : carrier_freq_type;
    requested_gain : gain_type;
    requested_burst_number : burst_number_type;
  end record;  
  -- PIM Exceptions: MaxTuningPreset, MinCarrierFreq, MaxCarrierFreq,
  -- MinGain, MaxGain, TuningMILT

  -- Tuning::Retuning ([PIM] §2.4.4.2)
  -- retune()
  type retune_in_type is record
    requested_frequency : carrier_freq_type;
    requested_gain : gain_type;
    requested_delay : delay_type;
  end record;  
  -- PIM Exceptions: NoOngoingProcessing, MinCarrierFreq, MaxCarrierFreq,
  -- MinGain, MaxGain, MinFromOnGoing, MaxFromOnGoing, RetuningMILT
 
  -- Notifications::Events ([PIM] §2.4.5.1)
  -- notifyEvent()
  type notify_event_in_type is record
    notified_event : event_type;
  end record;  
  -- PIM Exceptions: none

  -- Notifications::Errors ([PIM] §2.4.5.2)
  -- notifyError()
  type notify_error_in_type is record
    notified_error : error_type;
  end record;  
  -- PIM Exceptions: none

  -- GainControl::GainChanges ([PIM] §2.4.6.1)
  -- indicateGain()
  type indicate_gain_in_type is record
    new_gain : gain_type;
    first_valid_sample : sample_number_type;
  end record;  
  -- PIM Exceptions: none

  -- GainControl::GainLocking ([PIM] §2.4.6.2)
  -- lockGain() and unlockgain() have no parameter
  -- PIM Exceptions: NoOngoingProcessingException

  -- TransceiverTime::TimeAccess ([PIM] §2.4.7.1)
  -- getCurrentTime()
  type get_current_time_out_type is record
    current_time : time_spec_type;
  end record;  
  -- PIM Exceptions: none

  -- getLastStartTime()
  type get_last_start_time_out_type is record
    last_start_time : time_spec_type;
    last_burst_number : burst_number_type;
  end record;  
  -- PIM Exceptions: none

  -- Strobing::ApplicationStrobe ([PIM] §2.4.8.1)
  -- triggerStrobe() has no parameter
  -- PIM Exceptions: none

end package pkg_xcvr_primitives_parameters;
