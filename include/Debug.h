/*
 ====================================================================================================
 * File:        Debug.h
 * Author:      Hamas Saeed
 * Version:     Rev_1.0.0
 * Date:        Feb 10 2024
 * Brief:       This file provides Serial Debuging
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

#ifndef DEBUG_H
#define DEBUG_H


/* Macros */
#define DEBUG_MODE

#ifdef DEBUG_MODE
  #define DEBUG_PRINT(x)     Serial.print(x)
  #define DEBUG_PRINTLN(x)   Serial.println(x)
  #define DEBUG_PRINTF(x, y) Serial.printf(x, y)
#endif

#endif // DEBUG_H 