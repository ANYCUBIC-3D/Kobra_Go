/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#ifndef HC32F46x
  #error "Oops! Select an HC32F46x board in 'options > c/c++->defines.'"
#endif


#define BOARD_INFO_NAME      "AC_TRI_F1"
#define DEFAULT_MACHINE_NAME "HC32F460KCTA"

#define BOARD_NO_NATIVE_USB
//#define SD_LOG
#define IS_8M


#ifdef NEW_probe

#define Z_MIN_LED_PIN                       PB7
#define INIT_Z_MIN_LED_PIN                  SET_OUTPUT(Z_MIN_LED_PIN)
#define Z_MIN_LED_PIN_H()                    OUT_WRITE(Z_MIN_LED_PIN, HIGH);
#define Z_MIN_LED_PIN_L()                    OUT_WRITE(Z_MIN_LED_PIN, LOW);

#endif

#ifdef   BLTOUCH
//#define Z_MIN_PIN                           PA1   //PB8
#define SERVO0_PIN                          PA0   // BLTouch OUT
#endif


//
// EEPROM
//
#define FLASH_EEPROM_EMULATION
#define MARLIN_EEPROM_SIZE              0x2000  // 4KB

//
// Limit Switches
//
#define ONBOARD_ENDSTOPPULLUPS              // this remove #error "SENSORLESS_HOMING requires ENDSTOPPULLUP_XMIN

#define X_MIN_PIN                           PH2
#define Y_MIN_PIN                           PC13

#ifndef  Z_MIN_PIN
#define Z_MIN_PIN                           PC14
#endif

#define X_MAX_PIN                           -1
#define Y_MAX_PIN                           -1
#define Z_MAX_PIN                           -1

//
// Steppers
//
#define X_ENABLE_PIN                        PA15
#define X_STEP_PIN                          PA12
#define X_DIR_PIN                           PA11
//#define X_STALL_PIN                         PA6

#define Y_ENABLE_PIN                        X_ENABLE_PIN
#define Y_STEP_PIN                          PA9
#define Y_DIR_PIN                           PA8
//#define Y_STALL_PIN                         PC5

#define Z_ENABLE_PIN                        X_ENABLE_PIN
#define Z_STEP_PIN                          PC7
#define Z_DIR_PIN                           PC6
//#define Z_STALL_PIN                         PA8

#define Z2_ENABLE_PIN                       X_ENABLE_PIN
#define Z2_STEP_PIN                         -1
#define Z2_DIR_PIN                          -1
//#define Z2_STALL_PIN                        PB2



#define E0_ENABLE_PIN                       X_ENABLE_PIN
#define E0_STEP_PIN                       	PB15
#define E0_DIR_PIN                        	PB14
//#define E0_STALL_PIN                        PC13

#define E1_ENABLE_PIN                       X_ENABLE_PIN
#define E1_STEP_PIN                         -1
#define E1_DIR_PIN                          -1
//#define E1_STALL_PIN                        PB2

#if 1//HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
#define TMC6609

//#define X_HARDWARE_SERIAL  Serial1
//#define Y_HARDWARE_SERIAL  Serial1
//#define Z_HARDWARE_SERIAL  Serial1
//#define E0_HARDWARE_SERIAL Serial1

//#define E1_HARDWARE_SERIAL Serial3

//
// Software serial
//
  #define X_SERIAL_TX_PIN                   PB2
  #define X_SERIAL_RX_PIN                   PB2

  #define Y_SERIAL_TX_PIN                   X_SERIAL_TX_PIN
  #define Y_SERIAL_RX_PIN                   X_SERIAL_RX_PIN

  #define Z_SERIAL_TX_PIN                   X_SERIAL_TX_PIN
  #define Z_SERIAL_RX_PIN                   X_SERIAL_RX_PIN

  #define E0_SERIAL_TX_PIN                  X_SERIAL_TX_PIN
  #define E0_SERIAL_RX_PIN                  X_SERIAL_RX_PIN

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE                     19200
#endif



//
// Temperature Sensors
//
#define TEMP_0_PIN                          PC3   // T0
#define TEMP_BED_PIN                        PC1   // TB
#define  ADC_CHANNEL_COUNT 3u

//
// Heaters
//
#define HEATER_0_PIN                        PB8
#define HEATER_BED_PIN                      PB9

//
// Fans
//
#define FAN_PIN                             PB5     // model fan
#define FAN1_PIN                            PB13    // auto fan for E0
#define FAN2_PIN                            PB12    // controller fan
#define CONTROLLER_FAN_PIN                  FAN2_PIN
#define FAN_SOFT_PWM

//
// Misc
//
#define BEEPER_PIN                          PB7
#define FIL_RUNOUT_PIN                      PC15

#define LED_PIN                             -1
#define CASE_LIGHT_PIN                      -1
#define POWER_LOSS_PIN                      PC2
#define POWER_MONITOR_VOLTAGE_PIN           PC2


#define AUTO_LEVEL_RX_PIN                   PA1

//
// SD CaA1
//
#define SDIO_SUPPORT
#define SD_DETECT_PIN                       PA10
//
// SPI
//
  #define SPI_DEVICE                          -1
  #define SCK_PIN                             -1
  #define MISO_PIN                            -1
  #define MOSI_PIN                            -1
  #define SS_PIN                              -1

//
// SDIO
//
  #define SDIO_READ_RETRIES                   16
  #define SDIO_D0_PIN                         PC8
  #define SDIO_D1_PIN                         PC9
  #define SDIO_D2_PIN                         PC10
  #define SDIO_D3_PIN                         PC11
  #define SDIO_CK_PIN                         PC12
  #define SDIO_CMD_PIN                        PD2
/*
 * SDIO Pins
 */
#define BOARD_SDIO_D0 			PC8
#define BOARD_SDIO_D1 			PC9
#define BOARD_SDIO_D2 			PC10
#define BOARD_SDIO_D3 			PC11
#define BOARD_SDIO_CLK 			PC12
#define BOARD_SDIO_CMD 			PD2
#define BOARD_SDIO_DET 			SD_DETECT_PIN


// USARTS

#define BOARD_USART1_TX_PIN     -1     // MOTO
#define BOARD_USART1_RX_PIN     -1

#define BOARD_USART2_TX_PIN     PA2     // DEBUG
#define BOARD_USART2_RX_PIN     PA3

#define BOARD_USART3_TX_PIN     -1     // MOTO
#define BOARD_USART3_RX_PIN     -1

#define BOARD_USART4_TX_PIN     PB4     // LCD
#define BOARD_USART4_RX_PIN     PB3

//*************************now_just_test_***********************
#define BTN_EN1                     PB10    // 31
#define BTN_EN2                     PB3    // 33
#define BTN_ENC                     PB4  
