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
-- Title : pkg_xcvr_interface_declaration_properties.vhd
-- Date:  25 December 2021
-- Version: V2.1.0
-- Purpose: The pkg_xcvr_interface_declaration_properties.vhd file is defined 
--          as the standard VHDL package for handling of interface declaration 
--          properties
--

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

-- Interface declaration properties ([PIM] 4.5)
package pkg_xcvr_interface_declaration_properties is

  -- 1) Variable types properties (CARRIER_FREQ_TYPE, CARRIER_FREQ_TYPE, CARRIER_FREQ_TYPE)
  -- Enumerated values constants
  -- int16
  constant C_INT16 : std_logic_vector( 1 downto 0) := "00";
  -- int32
  constant C_INT32 : std_logic_vector( 1 downto 0) := "01";
  -- int64
  constant C_INT64 : std_logic_vector( 1 downto 0) := "10";
  -- float32: not mapped

  -- Setting of enumerated values
  -- enum CARRIER_FREQ_TYPE {int32, int64};
  constant C_CARRIER_FREQ_TYPE : std_logic_vector( 1 downto 0) := <C_INT32|C_INT64>; -- USER SELECTION REQUIRED

  -- enum DELAY_TYPE {int32, int64};
  constant C_DELAY_TYPE : std_logic_vector( 1 downto 0) := <C_INT32|C_INT64>; -- USER SELECTION REQUIRED

  -- enum IQ_TYPE {int16, int32, float32};
  constant C_IQ_TYPE : std_logic_vector( 1 downto 0) := <C_INT16|C_INT32>; -- USER SELECTION REQUIRED
 
  -- enum CARRIER_FREQ_TYPE {int32, int64};
  constant C_CARRIER_FREQ_VECTOR_SIZE : natural;

  -- enum DELAY_TYPE {int32, int64};
  constant C_DELAY_VECTOR_SIZE : natural;
  
  -- enum IQ_TYPE {int16, int32, float32};
  constant C_IQ_VECTOR_SIZE : natural;
  -- float32: not mapped

  -- 2) Optional meta-data properties
  -- boolean TX_META_DATA
  constant C_TX_META_DATA : std_logic := '<1|0>'; -- USER SELECTION REQUIRED
  -- boolean RX_META_DATA
  constant C_RX_META_DATA : std_logic := '<1|0>'; -- USER SELECTION REQUIRED

end package pkg_xcvr_interface_declaration_properties;

package body pkg_xcvr_interface_declaration_properties is
  function set_carrier_freq_vector_size(constant_type : in std_logic_vector(1 downto 0)) return natural is
    begin
    if (constant_type = C_INT32) then
      return 32;
    elsif (constant_type = C_INT64) then
      return 64;
    else
      assert false report "<C_INT32|C_INT64>" severity error;
      return 32;
    end if;
  end set_carrier_freq_vector_size;

  function set_delay_vector_size(constant_type : in std_logic_vector(1 downto 0)) return natural is
  begin
    if (constant_type = C_INT32) then
      return 32;
    elsif (constant_type = C_INT64) then
      return 64;
    else
      assert false report "<C_INT32|C_INT64>" severity error;
      return 32;
    end if;
  end set_delay_vector_size;

  function set_iq_vector_size(constant_type : in std_logic_vector(1 downto 0)) return natural is
  begin
    if (constant_type = C_INT16) then
      return 16;
    elsif (constant_type = C_INT32) then
      return 32;
    else
      assert false report "<C_INT16|C_INT32>" severity error;
      return 16;
    end if;
  end set_iq_vector_size;

  -- Resulting vector sizes computations
  -- enum CARRIER_FREQ_TYPE {int32, int64};
  constant C_CARRIER_FREQ_VECTOR_SIZE : natural := set_carrier_freq_vector_size( C_CARRIER_FREQ_TYPE);

  -- enum DELAY_TYPE {int32, int64};
  constant C_DELAY_VECTOR_SIZE : natural := set_delay_vector_size( C_DELAY_TYPE);
  
  -- enum IQ_TYPE {int16, int32, float32};
  constant C_IQ_VECTOR_SIZE : natural:= set_iq_vector_size( C_IQ_TYPE);
  -- float32: not mapped
  
end package body pkg_xcvr_interface_declaration_properties;