/*
 ====================================================================================================
 * File:        Credentials.h
 * Author:      Hamas Saeed
 * Version:     Rev_1.0.0
 * Date:        Feb 10 2024
 * Brief:       This file provides AWS Credentials
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

#ifndef CREDENTIALS_H
#define CREDENTIALS_H

const char*   otaS3Bucket = "-------------------.s3.eu-west-1.amazonaws.com";
const char*   awsEndpoint = "------------------.iot.eu-west-1.amazonaws.com";

/* Credentials */
static const char AWS_CERT_CA[] PROGMEM = R"EOF(                                             

-----BEGIN CERTIFICATE-----
................................................................
............................
-----END CERTIFICATE-----

)EOF";                                                                        // Root Certificate


static const char AWS_CERT_CRT[] PROGMEM = R"KEY(

-----BEGIN CERTIFICATE-----
................................................................
............................
-----END CERTIFICATE-----

)KEY";                                                                        // Certificate

static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(

-----BEGIN CERTIFICATE-----
................................................................
............................
-----END CERTIFICATE-----

)KEY";                                                                        // Private Key

#endif // CREDENTIALS_H