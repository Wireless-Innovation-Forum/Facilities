-- Distributed by Wireless Innovation Forum
-- Copyright 2021 SDS Harmonized Timing Service Task Group.
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
-- Title : pkg_tsf_api_types.vhd
-- Date:  25 December 2021
-- Version: V1.1.0
-- Purpose: The pkg_tsf_api_types.vhd file is defined as the standard VHDL 
-- package for the types of the FPGA PSM specification.
-- Specific types are introduced for sourceId and specificTimeId parameters, 
-- specified as int (not a valid IDL type) by Time Service Facility PIM Specification
--

library ieee;
use ieee.std_logic_1164.all;

package pkg_tsf_api_types is

  -- Constant reflecting version of the PIM Specification
  constant C_TSF_PIM_VERSION : std_logic_vector( 23 downto 0):= X"010000";
  
  -- SourceId_type (int in the [PIM], no dedicated type)
  subtype SourceId_type is std_logic_vector(7 downto 0);

  -- SpecificTimeId_type (int in the [PIM], no dedicated type)
  subtype SpecificTimeId_type is std_logic_vector(15 downto 0);
  
  -- TimeValue ([PIM] §3.4.1)
  -- struct TimeValue {
  --  long seconds,             // in seconds
  --  long nanoseconds};        // in nanoseconds (<1.000.000.000)
  --  const TimeValue UndefinedTime = {0xFFFFFFFF, 0xFFFFFFFF};

  type TimeValue_type is record
	seconds	:		std_logic_vector(31 downto 0);
	nanoseconds :	std_logic_vector(31 downto 0);
  end record TimeValue_type;
  constant UndefinedTime : TimeValue_type := (
	seconds => X"FFFFFFFF",
	nanoseconds => X"FFFFFFFF");
  
  -- TimeUncertainty ([PIM] §3.4.2)
  -- typedef long TimeUncertainty;
  subtype TimeUncertainty_type is std_logic_vector(31 downto 0);
  constant Beyond2SecTimeUncertainty : TimeUncertainty_type     := X"FFFFFFF0";
  constant Beyond4SecTimeUncertainty : TimeUncertainty_type     := X"FFFFFFF1";
  constant Beyond8SecTimeUncertainty : TimeUncertainty_type     := X"FFFFFFF2";
  constant Beyond16SecTimeUncertainty : TimeUncertainty_type    := X"FFFFFFF3";
  constant Beyond32SecTimeUncertainty : TimeUncertainty_type    := X"FFFFFFF4";
  constant Beyond64SecTimeUncertainty : TimeUncertainty_type    := X"FFFFFFF5";
  constant Beyond128SecTimeUncertainty : TimeUncertainty_type   := X"FFFFFFF6";
  constant Beyond256SecTimeUncertainty : TimeUncertainty_type   := X"FFFFFFF7";
  constant Beyond512SecTimeUncertainty : TimeUncertainty_type   := X"FFFFFFF8";
  constant Beyond1024SecTimeUncertainty : TimeUncertainty_type  := X"FFFFFFF9";
  constant Beyond2048SecTimeUncertainty : TimeUncertainty_type  := X"FFFFFFFA";
  constant Beyond4096SecTimeUncertainty : TimeUncertainty_type  := X"FFFFFFFB";
  constant Beyond8192SecTimeUncertainty : TimeUncertainty_type  := X"FFFFFFFC";
  constant Beyond16384SecTimeUncertainty : TimeUncertainty_type := X"FFFFFFFD";
  constant UnknownTimeUncertainty  : TimeUncertainty_type       := X"FFFFFFFE";  
  constant UndefinedTimeUncertainty  : TimeUncertainty_type     := X"FFFFFFFF";

  -- RateUncertainty ([PIM] §3.4.3)
  -- typedef long RateUncertainty; 
  subtype RateUncertainty_type is std_logic_vector(31 downto 0);
  constant UnknownRateUncertainty : RateUncertainty_type := X"FFFFFFFF";
  
end package pkg_tsf_api_types;
