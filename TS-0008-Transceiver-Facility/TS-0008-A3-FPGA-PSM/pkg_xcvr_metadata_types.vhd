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
-- Title : pkg_xcvr_metadata_types.vhd
-- Date:  25 December 2021
-- Version: V2.1.0
-- Purpose: The file pkg_xcvr_metadata_types.vhd is defined as the standard 
--          VHDL package used to declare meta-data types.
--          It is applicable if TX_META_DATA or RX_META_DATA is equal to TRUE
--

library ieee;
use ieee.std_logic_1164.all;

library xcvr_api;
use xcvr_api.pkg_xcvr_interface_declaration_properties.all; 
use xcvr_api.pkg_xcvr_api_types.all;

package pkg_xcvr_metadata_types is

  -- MetaData ([PIM] §3.4.12)
  -- typedef struct TxMetaData (keep if C_TX_META_DATA = '1')
  type tx_metadata_type is record
    <user-defined>;   -- USER-DEFINED FIELDS
  end record;

  -- typedef struct RxMetaData (keep if C_RX_META_DATA = '1')
  type rx_metadata_type is record
    <user-defined>;   -- USER-DEFINED FIELDS
  end record;

end package pkg_xcvr_metadata_types;
