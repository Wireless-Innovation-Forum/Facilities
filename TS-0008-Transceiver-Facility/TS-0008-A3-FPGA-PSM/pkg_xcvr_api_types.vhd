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
-- Title : pkg_xcvr_api_types.vhd
-- Date:  25 December 2021
-- Version: V2.1.0
-- Purpose: The pkg_xcvr_api_types.vhd file is defined as the standard VHDL 
--          package for the types of the FPGA PSM specification
--

library ieee;
use ieee.std_logic_1164.all;

library xcvr_api;
use xcvr_api.pkg_xcvr_interface_declaration_properties.all;

package pkg_xcvr_api_types is
	
  -- Constant reflecting value of XCVR_PIM_VERSION property
  constant C_XCVR_API_VERSION : std_logic_vector( 23 downto 0):= X"020000";

  -- BasebandPacket ([PIM] §3.4.2) : the FPGA PSM does not use the concept of    
  -- packets for baseband samples exchange; each baseband sample is transferred
  -- individually within the digital stream 

  -- BlockLength ([PIM] §3.4.3)
  -- typedef unsigned long BlockLength;
 
  subtype block_length_type is std_logic_vector( 31 downto 0);
  constant C_UNDEFINED_BLOCK_LENGTH : block_length_type := (others => '1');

  -- IQ ([PIM] §3.4.11)
  -- typedef <short|long|float> IQ
  subtype iq_type is std_logic_vector( C_IQ_VECTOR_SIZE-1 downto 0);

  -- BasebandSample ([PIM] §3.4.4)
  -- struct BasebandSample {IQ valueI, IQ valueQ};
  type baseband_sample_type is record
    valueI : iq_type;
    valueQ : iq_type;
  end record;

  -- BurstNumber ([PIM] §3.3.5)
  -- typedef unsigned long BurstNumber;
  subtype burst_number_type is std_logic_vector( 15 downto 0);

  -- CarrierFreq ([PIM] §3.4.6), in Hz
  -- typedef <unsigned long|unsigned long long> CarrierFreq
  subtype carrier_freq_type is std_logic_vector( C_CARRIER_FREQ_VECTOR_SIZE-1 downto 0);

  -- const CarrierFreq UndefinedCarrierFreq = <0xFFFFFFFF | 0xFFFFFFFFFFFFFFFF>
  constant C_UNDEFINED_CARRIER_FREQ : carrier_freq_type := (others => '1');

  -- Delay ([PIM] §3.4.7), in ns
  -- typedef <unsigned long|unsigned long long> Delay
  subtype delay_type is std_logic_vector( C_DELAY_VECTOR_SIZE-1 downto 0);

  -- const Delay UndefinedDelay = <0xFFFFFFFF | 0xFFFFFFFFFFFFFFFF>
  constant C_UNDEFINED_DELAY : delay_type := (others => '1');

  -- Error ([PIM] §3.4.8)
  -- enum Error { errorDelayedTuning, ...
  subtype error_type is std_logic_vector( 3 downto 0);
  constant C_DELAYED_TUNING_ERROR            : error_type := X"0";
  constant C_TUNING_TIMEOUT_ERROR            : error_type := X"1";
  constant C_DELAYED_FIRST_SAMPLE_ERROR      : error_type := X"2";
  constant C_FIRST_SAMPLE_TIMEOUT_ERROR      : error_type := X"3";
  constant C_TRANSMISSION_UNDERFLOW_ERROR    : error_type := X"4";
  constant C_RECEPTION_OVERFLOW_ERROR        : error_type := X"5";
  constant C_SHORTER_TRANSMITTED_BLOCK_ERROR : error_type := X"6";
  constant C_LONGER_TRANSMITTED_BLOCK_ERROR  : error_type := X"7";

  -- Event ([PIM] §3.4.9)
  -- enum Event { eventProcessingStart, ...
  subtype event_type is std_logic_vector( 2 downto 0);
  constant C_PROCESSING_START_EVENT : event_type := "000";
  constant C_PROCESSING_STOP_EVENT  : event_type := "001";
  constant C_SILENCE_START_EVENT    : event_type := "010";
  constant C_SILENCE_STOP_EVEVNT    : event_type := "011";

  -- Gain ([PIM] §3.4.10), in 1/10 dB
  -- typedef short Gain;
  subtype gain_type is std_logic_vector( 15 downto 0); -- SIGNED

  -- const Gain UndefinedGain = 0xFFFF;
  constant C_UNDEFINED_GAIN : gain_type := (others => '1');

  -- MetaData ([PIM] §3.4.12) : specified by pkg_xcvr_metadata_types.vhd

  -- PacketLength ([PIM] §3.4.13): not mapped

  -- SampleNumber ([PIM] §3.4.14)
  -- typedef unsigned long SampleNumber;
  subtype sample_number_type is std_logic_vector( 31 downto 0);

  -- StrobeSource ([PIM] §3.4.15)
  -- enum StrobeSource { ApplicationStrobe,...
  subtype strobe_source_type is std_logic_vector( 3 downto 0);
  constant C_APPLICATION_STROBE : strobe_source_type := X"0";
  constant C_TIME_REF_PPS       : strobe_source_type := X"1";
  constant C_GNSS_PPS           : strobe_source_type := X"2";
  constant C_USER_STROBE_1      : strobe_source_type := X"3";
  constant C_USER_STROBE_2      : strobe_source_type := X"4";
  constant C_USER_STROBE_3      : strobe_source_type := X"5";
  constant C_USER_STROBE_4      : strobe_source_type := X"6";

  -- TimeSpec ([PIM] §3.4.16)
  -- struct TimeSpec { unsigned long seconds, unsigned long nanoseconds};
  type time_spec_type is record
    seconds     : std_logic_vector( 31 downto 0);   -- in seconds
    nanoseconds : std_logic_vector( 31 downto 0);   -- in ns (<1.000.000.000)
  end record;

  -- const TimeSpec UndefinedTimeSpec = {0xFFFFFFFF, 0xFFFFFFFF};
  constant C_UNDEFINED_TIME_SPEC : time_spec_type := (others => (others => '1'));

  -- TuningPreset ([PIM] §3.4.17)
  -- typedef unsigned short TuningPreset;
  subtype tuning_preset_type is std_logic_vector( 15 downto 0);

  -- const TuningPreset UndefinedTuningPreset = 0xFFFF;
  constant C_UNDEFINED_TUNING_PRESET : tuning_preset_type := (others => '1');

end package pkg_xcvr_api_types;
