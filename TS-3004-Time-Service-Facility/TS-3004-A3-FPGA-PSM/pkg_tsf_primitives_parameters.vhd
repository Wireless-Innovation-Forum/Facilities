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
-- Title : pkg_tsf_primitives_parameters.vhd
-- Date:  25 December 2021
-- Version: V1.1.0
-- Purpose: The file pkg_tsf_primitives_parameters.vhd is defined as the standard 
-- VHDL package for parameters of the FPGA PSM specification primitives.
-- For primitives with optional implementation of exceptions specified by the PIM 
-- specification, the corresponding dedicated 1-bit RTL signal is not specified 
-- in the VDHL file
--

library ieee;
use ieee.std_logic_1164.all;

library tsf_api;
use tsf_api.pkg_tsf_api_types.all;

package pkg_tsf_primitives_parameters is

  -- TimeService::TerminalTime::TerminalTimeAccess ([PIM] §3.1.2)
  -- getTerminalTime ([PIM] §3.1.2.1.2)
  type getTerminalTime_outputType is record
    terminal_time : TimeValue_type;
  end record;
  -- PIM Exceptions: none

  -- getTerminalTimeUncertainty ([PIM] § 3.1.2.2.2)
  type getTerminalTimeUncertainty_outputType is record
    terminalTimeRateUncertainty : RateUncertainty_type;
  end record; 
  -- PIM Exceptions: none
  
  -- TimeService::SystemTime::SystemTimeAccess([PIM] §3.1.3)
  -- getCurrentTAI ([PIM] §3.1.3.1.2)
  type getCurrentTAI_outputType is record
    currentTAI      : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
  end record; 
  -- PIM Exceptions: none

  -- getCurrentUTC ([PIM] §3.1.3.2.2) 
  type getCurrentUTC_outputType is record
    currentUTC      : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
  end record; 
  -- PIM Exceptions: none

  -- getLastUpdateTAI ([PIM] §3.1.3.3.2)
  type getLastUpdateTAI_outputType is record
    lastUpdateTAI   : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
  end record; 
  -- PIM Exceptions: none

  -- getLastUpdateUTC ([PIM] §3.1.3.4.2)
  type getLastUpdateUTC_outputType is record
    lastUpdateUTC   : TimeValue_type;
 	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
  end record; 
  -- PIM Exceptions: none
  
  -- TimeService::SystemTime::StandardTimeProvision ([PIM] §3.1.4)
  -- provideTAI ([PIM] §3.1.4.1.2)
  type provideTAI_inputType is record
    providedTAI     : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
	 sourceId        : SourceId_type;
  end record;
  -- PIM Exceptions: FutureTimeStamp

  -- provideUTC ([PIM] §3.1.4.2.2)
  type provideUTC_inputType is record
    providedUTC     : TimeValue_type;
 	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
	 sourceId        : SourceId_type;
  end record;
  -- PIM Exceptions: FutureTimeStamp

  --  TimeService::StandardTimes::ReferencesNotification ([PIM] §3.1.5)
  -- notifyStandardTimeReference(§3.1.5.1.2)
  type notifyStandardTimeReference_inputType is record
    referenceTAI    : TimeValue_type;
	 referenceUTC    : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
	 sourceId        : SourceId_type;
  end record; 
  -- PIM Exceptions: none

  -- TimeService::SpecificTimes::SpecificTimeHandling ([PIM] §3.1.6)
  -- setSpecificTime([PIM] §3.1.6.1.2)
  type setSpecificTime_inputType is record
    specificTimeId  : SpecificTimeId_type;
	 specificTime    : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
  end record; 
  -- PIM Exceptions: FutureTimeStamp | InvalidSpecificTimeId

  -- getSpecificTime([PIM] §3.1.6.2.2)
  type getSpecificTime_inputType is record
    specificTimeId  : SpecificTimeId_type;
  end record; 
  type getSpecificTime_outputType is record
	 specificTime    : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
  end record;
  -- PIM Exceptions : InvalidSpecificTimeId
  
  --  TimeService::SpecificTimes::SettingsNotification ([PIM] §3.1.7)
  -- notifySpecificTimeSetting([PIM] §3.1.7.1.2)
  type notifySpecificTimeSetting_type  is record
	 specificTimeId  : SpecificTimeId_type;
	 specificTime    : TimeValue_type;
	 timeStamp       : TimeValue_type;
	 timeUncertainty : TimeUncertainty_type;
  end record; 
  -- PIM Exceptions: none

end package pkg_tsf_primitives_parameters;
