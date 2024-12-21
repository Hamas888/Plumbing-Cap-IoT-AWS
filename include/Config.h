/*
 ====================================================================================================
 * File:        Config.h
 * Author:      Hamas Saeed
 * Version:     Rev_1.0.0
 * Date:        Feb 10 2024
 * Brief:       This file provides Device configurations
 * 
 ====================================================================================================
 * License: 
 * This file is licensed under the GNU Affero General Public License (AGPL) v3.0.
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 * https://www.gnu.org/licenses/agpl-3.0.en.html
 * 
 * Commercial licensing: For commercial use of this software, please contact Hamas Saeed at 
 * hamasaeed@gmail.com.
 * 
 * Distributed under the AGPLv3 License. Software is provided "AS IS," without any warranties 
 * or conditions of any kind, either express or implied.
 *
 =====================================================================================================
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Includes */
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <CertStoreBearSSL.h>
#include "PubSubClient.h"
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include "ArduinoJson.h"
#include "Credentials.h"
#include <EEPROM.h>
#include <Ticker.h>
#include "Debug.h"
#include <time.h>

/* Macros */
#define FIRMWAR_VER        "1.0.0"

#define LED                 15
#define BUTTON_PIN          5                                               // GPIO pin where the button is connected
#define SENSOR_PIN          4                                               // GPIO pin where the SENSOR is connected
#define analogPin           A0                                              // ESP8266 Analog Pin ADC0 = A0 

#define EEPROM_SIZE         150
#define EEPROM_ADDR         0

#define SLEEP_1             14400000000L                                    // 4 Hours 
#define SLEEP_2             1800000000L                                     // 30 Minutes

/* Custom types */
typedef struct {
  bool                      blockageDetected;
  bool                      batteryCalibrated;
  float                     batteryMax;
  float                     batteryMin;
  float                     batteryLastVOL;
  time_t                    blockageTimestamp;
  uint8_t                   batteryLastPER;
  uint16_t                  waterBlockageTimes; 
  uint16_t                  uploadCount;

  std::array<char, 10>      firstBoot;
  std::array<char, 13>      thingName;
  std::array<char, 36>      publishTopic;
  std::array<char, 38>      subscribeTopic;
  std::array<char, 10>      lastBlockageDuration;
 
} DeviceParameters;

/* Global Variables */
extern char                 jsonBuffer[];
extern uint8_t              mode;
extern uint8_t              leakageStatus;
extern unsigned long        startTime;
extern DeviceParameters     param;

/* Function prototypes */
void tick();
void readParam(); 
bool connectAWS();
void NTPConnect();
void checkReply();
void makePacket();
void checkSensor();
void checkBattery();
bool connectToWIFI();
void sleep(uint8_t mode);
bool FirmwareUpdate(String file); 
bool publishMessage(const char* message);
String getValue(String data, String key);
void messageReceived(char *topic, byte *payload, unsigned int length);

#endif // CONFIG