% Copyright 2017 Covidien LP
% All Rights Reserved. The information contained herein is confidential
% property of Covidien LP. The use, copying, transfer or disclosure of such
% information is prohibited except by express written agreement with Covidien LP.

function [str, namespace, additionalCode] = SraHalInterface

namespace = {'einstein' 'sra' 'hal_interface'};
additionalCode =  { ...
'const std::size_t UI_INDEX_ARM_ELBOW_BUTTON = 0;' ...
'const std::size_t UI_INDEX_LASER_ALIGNMENT_BUTTON = 1;' ...
'const std::size_t UI_INDEX_TILT_BUTTON = 2;' ...
'const std::size_t UI_INDEX_POSITION_BUTTON = 3;' ...
'const std::size_t UI_INDEX_FULCRUM_HANDLE_LEFT_BUTTON = 4;' ...
'const std::size_t UI_INDEX_IDU_LEFT_BUTTON = 5;' ...
'const std::size_t UI_INDEX_IDU_RIGHT_BUTTON= 6;' ...
'const std::size_t UI_INDEX_FULCRUM_HANDLE_RIGHT_BUTTON = 7;' ...
...
'const std::size_t UI_INDEX_SA_MANUAL_VERTICAL_AXES_USER_INTERFACE = UI_INDEX_ARM_ELBOW_BUTTON;' ...
'const std::size_t UI_INDEX_REGISTRATION_MODULE_USER_INTERFACE = UI_INDEX_LASER_ALIGNMENT_BUTTON;' ...
'const std::size_t UI_INDEX_RA_MANUAL_SA_PITCH_USER_INTERFACE = UI_INDEX_TILT_BUTTON;' ...
'const std::size_t UI_INDEX_RA_MANUAL_SETUP_USER_INTERFACE = UI_INDEX_POSITION_BUTTON;' ...
'const std::size_t UI_INDEX_RA_MANUAL_RCM_USER_INTERFACE = UI_INDEX_FULCRUM_HANDLE_LEFT_BUTTON;' ...
'const std::size_t UI_INDEX_RA_MANUAL_LINEAR_USER_INTERFACE_1 = UI_INDEX_IDU_LEFT_BUTTON;' ...
'const std::size_t UI_INDEX_RA_MANUAL_LINEAR_USER_INTERFACE_2 = UI_INDEX_IDU_RIGHT_BUTTON;' ...
'const std::size_t UI_INDEX_RA_MANUAL_RCM2_USER_INTERFACE = UI_INDEX_FULCRUM_HANDLE_RIGHT_BUTTON;' ...
...
'const std::size_t PORT_LATCH_INDEX_PORT_LATCH_RELEASE_USER_INTERFACE = 0;' ...
'const std::size_t PORT_LATCH_INDEX_PORT_LATCH_PORT_DETECT = 1;' ...
'constexpr const char * SRA_SYNC_ACTUALS_ID = "sra_sync_actuals";' ...
'constexpr const char * IDU_SYNC_ACTUALS_ID = "idu_sync_actuals";' ...
'constexpr const char * RA_PRIMARY_ACTUALS_ID = "ra_primary_actual";' ...
'constexpr const char * SA_PRIMARY_ACTUALS_ID = "sa_primary_actual";' ...
'constexpr const char * IDU_PRIMARY_ACTUALS_ID = "idu_primary_actual";' ...
'constexpr const char * SRA_UI_ACTUALS_ID = "sra_ui_actual";' ...
'constexpr const char * SRA_LATENCY_ID = "sra_latency";' ...
'constexpr const char * IDU_LATENCY_ID = "idu_latency";' ...
'constexpr const char * SRA_PRIMARY_TEMPERATURE_ID = "sra_primary_temperature";' ...
'constexpr const char * IDU_PRIMARY_TEMPERATURE_ID = "idu_primary_temperature";' ...
'constexpr const char * SRA_PRIMARY_POWER_SUPPLY_ID = "sra_primary_power_supply";' ...
'constexpr const char * IDU_PRIMARY_POWER_SUPPLY_ID = "idu_primary_power_supply";' ...
'constexpr const char * IDU_PRIMARY_MOTION_AND_ORIENTATION_ID = "idu_primary_motion_and_orientation";' ...
'constexpr const char * RA_SYNC_DESIRED_ID = "ra_sync_desired";' ...
'constexpr const char * RA_CONTROL_DESIRED_ID = "ra_control_desired";' ...
'constexpr const char * SA_SYNC_DESIRED_ID = "sa_sync_desired";' ...
'constexpr const char * IDU_SYNC_DESIRED_ID = "idu_sync_desired";' ...
'constexpr const char * SA_CONTROL_DESIRED_ID = "sa_control_desired";' ...
'constexpr const char * IDU_CONTROL_DESIRED_ID = "idu_control_desired";' ...
'constexpr const char * IDU_UI_DESIRED_ID = "idu_ui_desired";' ...
'constexpr const char * SRA_UI_DESIRED_ID = "sra_ui_desired";' ...
'constexpr const char * SRA_SYNC_SECONDARY_ACTUALS_ID = "sra_sync_secondary_actuals";' ...
'constexpr const char * RA_SECONDARY_ACTUALS_ID = "ra_secondary_actual";' ...
'constexpr const char * SA_SECONDARY_ACTUALS_ID = "sa_secondary_actual";' ...
'constexpr const char * SRA_UI_SECONDARY_ACTUALS_ID = "sra_ui_secondary_actual";' ...
'constexpr const char * SRA_SECONDARY_TEMPERATURE_ID = "sra_secondary_temperature";' ...
'constexpr const char * SRA_SECONDARY_POWER_SUPPLY_ID = "sra_secondary_power_supply";' ...
'constexpr const char * INSTRUMENT_ACTUALS_ID = "instrument_actual";' ...
'constexpr const char * INSTRUMENT_ACTUALS_REDUNDANT_ID = "instrument_actual_redundant";' ...
'constexpr const char * INSTRUMENT_DESIRED_ID = "instrument_desired";' ...
'constexpr const char * INSTRUMENT_DESIRED_REDUNDANT_ID = "instrument_desired_redundant";' ...
'constexpr const char * RELOAD_ACTUALS_ID = "reload_actual";' ...
'constexpr const char * RELOAD_ACTUALS_REDUNDANT_ID = "reload_actual_redundant";' ...
'constexpr const char * ADVANCED_INSTRUMENT_STATIC_ACTUALS_ID = "advanced_instrument_static_actual";' ...
'constexpr const char * ADVANCED_INSTRUMENT_STATIC_ACTUALS_REDUNDANT_ID = "advanced_instrument_static_actual_redundant";' ...
'constexpr const char * ADVANCED_INSTRUMENT_DYNAMIC_ACTUALS_ID = "advanced_instrument_dynamic_actual";' ...
'constexpr const char * ADVANCED_INSTRUMENT_DYNAMIC_ACTUALS_REDUNDANT_ID = "advanced_instrument_dynamic_actual_redundant";' ...
'constexpr const char * ADVANCED_INSTRUMENT_DESIRED_ID = "advanced_instrument_desired";' ...
'constexpr const char * ADVANCED_INSTRUMENT_DESIRED_REDUNDANT_ID = "advanced_instrument_desired_redundant";' ...
'constexpr const char * GENERIC_MEMORY_STATIC_VERSION_ID = "generic_memory_static_version";' ...
'constexpr const char * GENERIC_MEMORY_STATIC_VERSION_REDUNDANT_ID = "generic_memory_static_version_redundant";' ...
'constexpr const char * CORE_WRISTED_STATIC_ACTUAL_ID = "core_wristed_static_actual";' ...
'constexpr const char * CORE_WRISTED_STATIC_ACTUAL_REDUNDANT_ID = "core_wristed_static_actual_redundant";' ...
'constexpr const char * CORE_WRISTED_DYNAMIC_ACTUAL_ID = "core_wristed_dynamic_actual";' ...
'constexpr const char * CORE_WRISTED_DYNAMIC_ACTUAL_REDUNDANT_ID = "core_wristed_dynamic_actual_redundant";' ...
'constexpr const char * CORE_WRISTED_DESIRED_ID = "core_wristed_desired";' ...
'constexpr const char * CORE_WRISTED_DESIRED_REDUNDANT_ID = "core_wristed_desired_redundant";' ...
'constexpr const char * SIM_ACTUALS_ID = "sim_actual";' ...
'constexpr const char * SIM_ACTUALS_REDUNDANT_ID = "sim_actual_redundant";' ...
'constexpr const char * SIM_DESIRED_ID = "sim_desired";' ...
'constexpr const char * SIM_DESIRED_REDUNDANT_ID = "sim_desired_redundant";' ...
'constexpr const char * IDU_EOL_FIXTURE_DESIRED_ID = "idu_eol_fixture_desired";'
};

shmio = ShmioGenerator('','');

% Types

str.BrakeState = {...
    'ENGAGED',      0; ...
    'DISENGAGED',   1; ...
};

str.MotorState = {...
    'OFF',                  0; ...
    'CURRENT_CONTROLLED',   1; ...
};

% Instrument Ids

str.InstrumentId = { ...
%==INSTRUMENTID_INSTRUMENTS_MATLAB==%
};

% Reload Ids
%   TODO define/pull ReloadId from JAMA just like InstrumentId
% str.ReloadId = { ...
% %==RELOADID_RELOADS_MATLAB==%
% };

% Synchronization

str.SraSyncActual.timestamp                                 = shmio.addMember('uint16'  , 5 , 1);

str.SraSyncSecondaryActual.timestamp                        = shmio.addMember('uint16'  , 5 , 1);

str.RaSyncDesired.timestamp                                 = shmio.addMember('uint16'  , 3 , 1);

str.SaSyncDesired.timestamp                                 = shmio.addMember('uint16'  , 2 , 1);

str.IduSyncDesired.timestamp                                = shmio.addMember('uint16'  , 1 , 1);

str.IduSyncActual.timestamp                                 = shmio.addMember('uint16'  , 1 , 1);

% Setup Arm

str.SaPrimaryActual.brake_state                             = shmio.addMember('BrakeState' , 4 , 1);
str.SaPrimaryActual.brake_state_quality                     = shmio.addMember('boolean'    , 4 , 1);
str.SaPrimaryActual.motor_state                             = shmio.addMember('MotorState' , 1 , 1);
str.SaPrimaryActual.motor_state_quality                     = shmio.addMember('boolean'    , 1 , 1);
str.SaPrimaryActual.brake_current                           = shmio.addMember('double'     , 4 , 1);
str.SaPrimaryActual.brake_current_quality                   = shmio.addMember('boolean'    , 4 , 1);
str.SaPrimaryActual.brake_voltage                           = shmio.addMember('double'     , 4 , 1);
str.SaPrimaryActual.brake_voltage_quality                   = shmio.addMember('boolean'    , 4 , 1);
str.SaPrimaryActual.motor_current                           = shmio.addMember('double'     , 1 , 1);
str.SaPrimaryActual.motor_current_quality                   = shmio.addMember('boolean'    , 1 , 1);
str.SaPrimaryActual.tau_motor                               = shmio.addMember('double'     , 1 , 1);
str.SaPrimaryActual.tau_motor_quality                       = shmio.addMember('boolean'    , 1 , 1);
str.SaPrimaryActual.theta                                   = shmio.addMember('double'     , 1 , 1);
str.SaPrimaryActual.theta_quality                           = shmio.addMember('boolean'    , 1 , 1);
str.SaPrimaryActual.tau_sensor                              = shmio.addMember('double'     , 1 , 1);
str.SaPrimaryActual.tau_sensor_quality                      = shmio.addMember('boolean'    , 1 , 1);
str.SaPrimaryActual.q                                       = shmio.addMember('double'     , 4 , 1);
str.SaPrimaryActual.q_quality                               = shmio.addMember('boolean'    , 4 , 1);

str.SaControlDesired.brake_state                            = shmio.addMember('BrakeState' , 4 , 1);
str.SaControlDesired.motor_state                            = shmio.addMember('MotorState' , 1 , 1);
str.SaControlDesired.tau_motor                              = shmio.addMember('double'     , 1 , 1);

str.SaSecondaryActual.q                                     = shmio.addMember('double'     , 4 , 1);
str.SaSecondaryActual.q_quality                             = shmio.addMember('boolean'    , 4 , 1);
str.SaSecondaryActual.brake_overvoltage                     = shmio.addMember('boolean'    , 4 , 1);
str.SaSecondaryActual.brake_overcurrent                     = shmio.addMember('boolean'    , 3 , 1);

% Robot Arm

str.RaPrimaryActual.brake_state                             = shmio.addMember('BrakeState' , 3 , 1);
str.RaPrimaryActual.brake_state_quality                     = shmio.addMember('boolean'    , 3 , 1);
str.RaPrimaryActual.motor_state                             = shmio.addMember('MotorState' , 4 , 1);
str.RaPrimaryActual.motor_state_quality                     = shmio.addMember('boolean'    , 4 , 1);
str.RaPrimaryActual.brake_current                           = shmio.addMember('double'     , 3 , 1);
str.RaPrimaryActual.brake_current_quality                   = shmio.addMember('boolean'    , 3 , 1);
str.RaPrimaryActual.brake_voltage                           = shmio.addMember('double'     , 3 , 1);
str.RaPrimaryActual.brake_voltage_quality                   = shmio.addMember('boolean'    , 3 , 1);
str.RaPrimaryActual.hall_position                           = shmio.addMember('double'     , 2 , 1);
str.RaPrimaryActual.hall_position_quality                   = shmio.addMember('boolean'    , 2 , 1);
str.RaPrimaryActual.motor_current                           = shmio.addMember('double'     , 4 , 1);
str.RaPrimaryActual.motor_current_quality                   = shmio.addMember('boolean'    , 4 , 1);
str.RaPrimaryActual.tau_motor                               = shmio.addMember('double'     , 4 , 1);
str.RaPrimaryActual.tau_motor_quality                       = shmio.addMember('boolean'    , 4 , 1);
str.RaPrimaryActual.theta                                   = shmio.addMember('double'     , 4 , 1);
str.RaPrimaryActual.theta_quality                           = shmio.addMember('boolean'    , 4 , 1);
str.RaPrimaryActual.q                                       = shmio.addMember('double'     , 2 , 1);
str.RaPrimaryActual.q_quality                               = shmio.addMember('boolean'    , 2 , 1);
str.RaPrimaryActual.tau_sensor                              = shmio.addMember('double'     , 3 , 1);
str.RaPrimaryActual.tau_sensor_quality                      = shmio.addMember('boolean'    , 3 , 1);
str.RaPrimaryActual.reference_switch                        = shmio.addMember('boolean'    , 2 , 1);
str.RaPrimaryActual.reference_switch_quality                = shmio.addMember('boolean'    , 2 , 1);
str.RaPrimaryActual.emergency_release                       = shmio.addMember('boolean'    , 1 , 1);
str.RaPrimaryActual.emergency_release_quality               = shmio.addMember('boolean'    , 1 , 1);

str.RaControlDesired.brake_state                            = shmio.addMember('BrakeState' , 3 , 1);
str.RaControlDesired.motor_state                            = shmio.addMember('MotorState' , 4 , 1);
str.RaControlDesired.tau_motor                              = shmio.addMember('double'     , 4 , 1);

str.RaSecondaryActual.q                                     = shmio.addMember('double'     , 2 , 1);
str.RaSecondaryActual.q_quality                             = shmio.addMember('boolean'    , 2 , 1);
str.RaSecondaryActual.hall_position                         = shmio.addMember('double'     , 2 , 1);
str.RaSecondaryActual.hall_position_quality                 = shmio.addMember('boolean'    , 2 , 1);
str.RaSecondaryActual.brake_overvoltage                     = shmio.addMember('boolean'    , 3 , 1);
str.RaSecondaryActual.reference_switch                      = shmio.addMember('boolean'    , 2 , 1);
str.RaSecondaryActual.reference_switch_quality              = shmio.addMember('boolean'    , 2 , 1);
str.RaSecondaryActual.emergency_release                     = shmio.addMember('boolean'    , 1 , 1);
str.RaSecondaryActual.emergency_release_quality             = shmio.addMember('boolean'    , 1 , 1);

% User Interfaces

str.UiActual.button                                         = shmio.addMember('boolean'    , 8 , 1);
str.UiActual.button_quality                                 = shmio.addMember('boolean'    , 8 , 1);
str.UiActual.llm_position                                   = shmio.addMember('double'     , 1 , 1);
str.UiActual.llm_position_quality                           = shmio.addMember('boolean'    , 1 , 1);
str.UiActual.port_latch                                     = shmio.addMember('boolean'    , 2 , 1);
str.UiActual.port_latch_quality                             = shmio.addMember('boolean'    , 2 , 1);
str.UiActual.pinch_sensor                                   = shmio.addMember('boolean'    , 5 , 1);
str.UiActual.pinch_sensor_quality                           = shmio.addMember('boolean'    , 5 , 1);

str.UiDesired.llm_laser_brightness                          = shmio.addMember('double'     , 1 , 1);

str.UiSecondaryActual.button                                = shmio.addMember('boolean'    , 8 , 1);
str.UiSecondaryActual.button_quality                        = shmio.addMember('boolean'    , 8 , 1);
str.UiSecondaryActual.port_latch                            = shmio.addMember('boolean'    , 2 , 1);
str.UiSecondaryActual.port_latch_quality                    = shmio.addMember('boolean'    , 2 , 1);
str.UiSecondaryActual.pinch_sensor                          = shmio.addMember('boolean'    , 5 , 1);
str.UiSecondaryActual.pinch_sensor_quality                  = shmio.addMember('boolean'    , 5 , 1);

str.IduUiDesired.alarms_override                            = shmio.addMember('boolean'    , 1 , 1);

% Platform

str.SraLatency.latency                                      = shmio.addMember('double'     , 6 , 1);
str.SraLatency.latency_quality                              = shmio.addMember('boolean'    , 6 , 1);

str.SraTemperature.computing_board                          = shmio.addMember('int8'       , 5 , 1);
str.SraTemperature.computing_board_quality                  = shmio.addMember('boolean'    , 5 , 1);
str.SraTemperature.inverter                                 = shmio.addMember('int8'       , 6 , 1);
str.SraTemperature.inverter_quality                         = shmio.addMember('boolean'    , 6 , 1);
str.SraTemperature.remote                                   = shmio.addMember('int8'       , 5 , 1);
str.SraTemperature.remote_quality                           = shmio.addMember('boolean'    , 5 , 1);
str.SraTemperature.zynq                                     = shmio.addMember('int8'       , 5 , 1);
str.SraTemperature.zynq_quality                             = shmio.addMember('boolean'    , 5 , 1);

str.SraSecondaryTemperature.inverter_temperature_ok         = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryTemperature.inverter_temperature_ok_quality = shmio.addMember('boolean'    , 5 , 1);

str.SraPowerSupply.dc_link_voltage                          = shmio.addMember('double'     , 5 , 1);
str.SraPowerSupply.dc_link_voltage_quality                  = shmio.addMember('boolean'    , 5 , 1);
str.SraPowerSupply.dc_link_current                          = shmio.addMember('double'     , 4 , 1);
str.SraPowerSupply.dc_link_current_quality                  = shmio.addMember('boolean'    , 4 , 1);
str.SraPowerSupply.crowbar_state                            = shmio.addMember('boolean'    , 1 , 1);
str.SraPowerSupply.crowbar_state_quality                    = shmio.addMember('boolean'    , 1 , 1);

str.SraSecondaryPowerSupply.analog_supply_voltage_ok        = shmio.addMember('boolean'    , 3 , 1);
str.SraSecondaryPowerSupply.dc_link_voltage_ok              = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.dc_link_current_ok              = shmio.addMember('boolean'    , 4 , 1);
str.SraSecondaryPowerSupply.within_limits_12v               = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_1v0               = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_1v5               = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_1v8               = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_3v3               = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_5v                = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_vdda              = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_vref              = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_vtt               = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_vttref            = shmio.addMember('boolean'    , 5 , 1);
str.SraSecondaryPowerSupply.within_limits_quality           = shmio.addMember('boolean'    , 5 , 1);

% IDU

str.IduPrimaryActual.motor_state                            = shmio.addMember('MotorState' , 4 , 1);
str.IduPrimaryActual.motor_state_quality                    = shmio.addMember('boolean'    , 4 , 1);
str.IduPrimaryActual.hall_position                          = shmio.addMember('double'     , 4 , 1);
str.IduPrimaryActual.hall_position_quality                  = shmio.addMember('boolean'    , 4 , 1);
str.IduPrimaryActual.motor_current                          = shmio.addMember('double'     , 4 , 1);
str.IduPrimaryActual.motor_current_quality                  = shmio.addMember('boolean'    , 4 , 1);
str.IduPrimaryActual.tau_motor                              = shmio.addMember('double'     , 4 , 1);
str.IduPrimaryActual.tau_motor_quality                      = shmio.addMember('boolean'    , 4 , 1);
str.IduPrimaryActual.theta                                  = shmio.addMember('double'     , 4 , 1);
str.IduPrimaryActual.theta_quality                          = shmio.addMember('boolean'    , 4 , 1);
str.IduPrimaryActual.tau_sensor                             = shmio.addMember('double'     , 4 , 1);
str.IduPrimaryActual.tau_sensor_raw                         = shmio.addMember('uint32'     , 4 , 1);
str.IduPrimaryActual.tau_sensor_quality                     = shmio.addMember('boolean'    , 4 , 1);
str.IduPrimaryActual.tau_sensor_initialization_ready        = shmio.addMember('boolean'    , 4 , 1);

str.IduControlDesired.motor_state                           = shmio.addMember('MotorState' , 4 , 1);
str.IduControlDesired.tau_motor                             = shmio.addMember('double'     , 4 , 1);
str.IduControlDesired.sra_comm_loss                         = shmio.addMember('boolean'    , 1 , 1);

str.IduLatency.latency                                      = shmio.addMember('double'     , 1 , 1);
str.IduLatency.latency_quality                              = shmio.addMember('boolean'    , 1 , 1);

str.IduTemperature.distal                                   = shmio.addMember('int8'       , 3 , 1);
str.IduTemperature.distal_quality                           = shmio.addMember('boolean'    , 3 , 1);
str.IduTemperature.nexus                                    = shmio.addMember('int8'       , 1 , 1);
str.IduTemperature.nexus_quality                            = shmio.addMember('boolean'    , 1 , 1);
str.IduTemperature.zynq                                     = shmio.addMember('int8'       , 1 , 1);
str.IduTemperature.zynq_quality                             = shmio.addMember('boolean'    , 1 , 1);
str.IduTemperature.fan_quality                              = shmio.addMember('boolean'    , 1 , 1);

str.IduPowerSupply.dclink_current_12v                       = shmio.addMember('double'     , 1 , 1);
str.IduPowerSupply.dclink_quality_12v                       = shmio.addMember('boolean'    , 1 , 1);
str.IduPowerSupply.dclink_current_48v                       = shmio.addMember('double'     , 2 , 1);
str.IduPowerSupply.dclink_quality_48v                       = shmio.addMember('boolean'    , 2 , 1);
str.IduPowerSupply.dclink_voltage_12v                       = shmio.addMember('double'     , 1 , 1);
str.IduPowerSupply.dclink_voltage_48v                       = shmio.addMember('double'     , 2 , 1);

str.IduMotionAndOrientation.acc_acceleration                = shmio.addMember('float'      , 3 , 1);
str.IduMotionAndOrientation.acc_quality                     = shmio.addMember('boolean'    , 1 , 1);
str.IduMotionAndOrientation.imu_acceleration                = shmio.addMember('float'      , 3 , 1);
str.IduMotionAndOrientation.imu_gyroscope                   = shmio.addMember('float'      , 3 , 1);
str.IduMotionAndOrientation.imu_magnetometer                = shmio.addMember('float'      , 3 , 1);
str.IduMotionAndOrientation.imu_quality                     = shmio.addMember('boolean'    , 1 , 1);

str.SimActual.present                                       = shmio.addMember('boolean'    , 1 , 1);
str.SimActual.rom_id                                        = shmio.addMember('uint8'      , 8 , 1);
str.SimActual.procedure_id                                  = shmio.addMember('uint8'      , 6 , 1);
str.SimActual.counter                                       = shmio.addMember('uint32'     , 1 , 1);
str.SimActual.counter_limit                                 = shmio.addMember('uint32'     , 1 , 1);
str.SimActual.metric                                        = shmio.addMember('uint32'     , 1 , 1);
str.SimActual.serial_number                                 = shmio.addMember('uint8'      , 10, 1);
str.SimActual.training                                      = shmio.addMember('boolean'    , 1 , 1);
str.SimActual.memory_quality                                = shmio.addMember('boolean'    , 1 , 1);
str.SimActual.block_validation_fail                         = shmio.addMember('boolean'    , 4 , 1);
str.SimActual.memory_auth_fail                              = shmio.addMember('boolean'    , 2 , 1);
str.SimActual.hardware_auth_fail                            = shmio.addMember('boolean'    , 1 , 1);

str.SimDesired.rom_id                                       = shmio.addMember('uint8'      , 8 , 1);
str.SimDesired.procedure_id                                 = shmio.addMember('uint8'      , 6 , 1);
str.SimDesired.counter                                      = shmio.addMember('uint32'     , 1 , 1);
str.SimDesired.metric                                       = shmio.addMember('uint32'     , 1 , 1);

str.InstrumentActual.present                                = shmio.addMember('boolean'    , 1 , 1);
str.InstrumentActual.rom_id                                 = shmio.addMember('uint8'      , 8,  1);
str.InstrumentActual.id                                     = shmio.addMember('InstrumentId');
str.InstrumentActual.procedure_id                           = shmio.addMember('uint8'      , 6 , 1);
str.InstrumentActual.counter                                = shmio.addMember('uint32'     , 2 , 1);
str.InstrumentActual.counter_limit                          = shmio.addMember('uint32'     , 2 , 1);
str.InstrumentActual.increment_coefficient                  = shmio.addMember('uint32'     , 2 , 1);
str.InstrumentActual.metric                                 = shmio.addMember('uint32'     , 8 , 1);
str.InstrumentActual.serial_number                          = shmio.addMember('uint8'      , 10, 1);
str.InstrumentActual.single_use_unique_id                   = shmio.addMember('uint8'      , 8 , 1);
str.InstrumentActual.training                               = shmio.addMember('boolean'    , 1 , 1);
str.InstrumentActual.gamma_coefficient                      = shmio.addMember('double'     , 1 , 1);
str.InstrumentActual.excessive_firing_force                 = shmio.addMember('double'     , 1 , 1);
str.InstrumentActual.memory_quality                         = shmio.addMember('boolean'    , 1 , 1);
str.InstrumentActual.block_validation_fail                  = shmio.addMember('boolean'    , 4 , 1);
str.InstrumentActual.memory_auth_fail                       = shmio.addMember('boolean'    , 2 , 1);
str.InstrumentActual.hardware_auth_fail                     = shmio.addMember('boolean'    , 1 , 1);

str.InstrumentDesired.rom_id                                = shmio.addMember('uint8'      , 8 , 1);
str.InstrumentDesired.procedure_id                          = shmio.addMember('uint8'      , 6 , 1);
str.InstrumentDesired.counter                               = shmio.addMember('uint32'     , 2 , 1);
str.InstrumentDesired.metric                                = shmio.addMember('uint32'     , 8 , 1);

str.ReloadActual.present                                    = shmio.addMember('boolean'    , 1 , 1);
str.ReloadActual.detect_switch_status                       = shmio.addMember('boolean'    , 1 , 1);
str.ReloadActual.rom_id                                     = shmio.addMember('uint8'      , 8 , 1);
str.ReloadActual.id                                         = shmio.addMember('uint16'     , 1 , 1);  %TODO use ReloadId
str.ReloadActual.counter                                    = shmio.addMember('uint32'     , 1 , 1);
str.ReloadActual.lot_number                                 = shmio.addMember('uint8'      , 15, 1);
str.ReloadActual.memory_quality                             = shmio.addMember('boolean'    , 1 , 1);

% Generic Instrument
% Note 1: Generic instrument SHMIOs *MUST* set packed=true to work properly
% Note 2: Pub/Sub implementations of the below generic SHMIOs must:
%           a) set packed=true
%           b) be identical in size (in bytes) to generic equivalent
%           c) use the same connection string in Simulink and C++, defined above
%           d) define a SHMIO identical to the instrument memory map

str.AdvancedInstrumentStaticActual.packed                   = true;
str.AdvancedInstrumentStaticActual.data                     = shmio.addMember('uint8'      , 63, 1);

str.AdvancedInstrumentDynamicActual.packed                  = true;
str.AdvancedInstrumentDynamicActual.data                    = shmio.addMember('uint8'      , 63, 1);

str.AdvancedInstrumentDesired.packed                        = true;
str.AdvancedInstrumentDesired.data                          = shmio.addMember('uint8'      , 63, 1);

% Ligasure Implementation of Generic Instrument Static Actual

str.LigasureStatic.packed                                   = true;
str.LigasureStatic.jaw_position                             = shmio.addMember('uint16'     , 9 , 1);
str.LigasureStatic.jaw_equation_version                     = shmio.addMember('uint8'      , 1 , 1);
str.LigasureStatic.blade_ext_position                       = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.blade_ext_version                        = shmio.addMember('uint8'      , 1 , 1);
str.LigasureStatic.blade_ret_position                       = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.blade_ret_version                        = shmio.addMember('uint8'      , 1 , 1);
str.LigasureStatic.artic_coef_k_yaw                         = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.artic_coef_k_pitch                       = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.jaw_coef_m                               = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.blade_coef_h                             = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.blade_ext_error_limit                    = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.blade_ret_error_limit                    = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.jaw_knee_cal_position_lower_limit        = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.jaw_knee_cal_position_upper_limit        = shmio.addMember('uint16'     , 1 , 1);
str.LigasureStatic.padding                                  = shmio.addMember('uint8'      , 22, 1);

% Ligasure Implementation of Generic Instrument Dynamic Actual/Desired

str.LigasureDynamic.packed                                  = true;
str.LigasureDynamic.blade_ext_error_counter                 = shmio.addMember('uint16'     , 1 , 1);
str.LigasureDynamic.blade_ret_error_counter                 = shmio.addMember('uint16'     , 1 , 1);
str.LigasureDynamic.device_kill_flag                        = shmio.addMember('uint16'     , 1 , 1);
str.LigasureDynamic.padding                                 = shmio.addMember('uint8'     , 57 , 1);

% Generic Version Information

str.GenericMemoryStaticVersion.data_structure_version         = shmio.addMember('uint8'    ,  1, 1);
str.GenericMemoryStaticVersion.hardware_version               = shmio.addMember('uint8'    ,  1, 1);

% Core Wristed Instrument Implementation of Generic Instrument Static Actual

str.CoreWristedStaticActual.controller1_id                    = shmio.addMember('uint8'    ,  1, 1);
str.CoreWristedStaticActual.controller1_counter_limit         = shmio.addMember('uint32'   ,  2, 1);
str.CoreWristedStaticActual.controller2_id                    = shmio.addMember('uint8'    ,  1, 1);
str.CoreWristedStaticActual.controller2_counter_limit         = shmio.addMember('uint32'   ,  2, 1);
str.CoreWristedStaticActual.csda_state                        = shmio.addMember('uint16'   ,  1, 1);
str.CoreWristedStaticActual.generic                           = shmio.addMember('uint16'   , 10, 1);

% Core Wristed Instrument Implementation of Generic Instrument Dynamic Actual/Desired

str.CoreWristedDynamic.controller_id_used                     = shmio.addMember('uint8'    ,  1, 1);
str.CoreWristedDynamic.counter                                = shmio.addMember('uint32'   ,  2, 1);
str.CoreWristedDynamic.generic                                = shmio.addMember('uint16'   , 10, 1);

% IDU End of Line Fixture

str.IduEolFixtureDesired.update_counter                     = shmio.addMember('uint32'     , 1 , 1);
str.IduEolFixtureDesired.led_red                            = shmio.addMember('uint8'      , 1 , 1);
str.IduEolFixtureDesired.led_green                          = shmio.addMember('uint8'      , 1 , 1);
str.IduEolFixtureDesired.led_blue                           = shmio.addMember('uint8'      , 1 , 1);
str.IduEolFixtureDesired.led_brightness                     = shmio.addMember('double'     , 1 , 1);
str.IduEolFixtureDesired.fan_control_watchdog               = shmio.addMember('uint16'     , 1 , 1);

% IDU Data Recorder

str.IduDataRecorderTriggers.idu_trigger_sra_datarecorder = shmio.addMember('uint32');
str.IduDataRecorderTriggers.idu_trigger_msc_datarecorder = shmio.addMember('uint32');
