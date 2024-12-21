# Plumbing Cap - Drainage Blockage Alert System

![Project Image](https://drive.google.com/uc?export=view&id=) 

## Overview
The Plumbing Cap with Blockage Detection is a state-of-the-art drainage solution designed to monitor and detect pipe blockages, providing real-time alerts for efficient maintenance. With two variants 2-inch for industrial applications and 4-inch for domestic use, this device offers seamless integration with AWS, enabling remote monitoring and management. The product is part of the Aquazen brand, which provides a range of plumbing solutions, all of which are integrated into a comprehensive AWS architecture.

### Key Highlights
- **Two Variants**: The 2-inch model is LoRaWAN-based, ideal for industrial applications and large fleets, while the 4-inch model is WiFi-based, offering easy installation and configuration for domestic use.
- **Seamless AWS Integration**: Data from both variants is sent to AWS, where it is processed and monitored, ensuring real-time alerts and insights.
- **Battery & Blockage Alerts**: Users receive timely notifications on battery status, blockages, and their duration via the complementary web and mobile apps.
- **Fleet Management**: A powerful web app and mobile app allow building owners and users to manage product registration, accounts, device fleets, and alerts efficiently.

## Features

- **Blockage Detection**: The device detects pipe blockages by shorting terminals when water flows through, sending immediate alerts to AWS.
- **Power Management**: The device wakes up every 30 minutes to check for blockages. If a blockage is detected, the wake-up interval is reduced to 10 minutes to ensure timely monitoring.
- **Easy Setup (4-Inch WiFi Variant)**: The 4-inch variant offers a simple setup page to configure WiFi credentials, making it ideal for domestic users who require a straightforward installation process.
- **Industrial-Grade LoRaWAN (2-Inch Variant)**: The 2-inch variant uses LoRaWAN for communication, connecting through a LoRaWAN router and TTN to send data to AWS, suitable for large-scale industrial deployments.

## Technical Specifications

- **2-Inch LoRaWAN-Based Model**
  - **Sensor Module**: Dragino Contact Sensor Module
  - **Connectivity**: LoRaWAN (connects to LoRaWAN router, TTN, and AWS)
  - **Power Consumption**: Low-power with sleep mode and periodic wake-ups
  - **Target Use**: Industrial applications, large fleets, and environments requiring extensive network coverage
  - **Size**: 2-inch drainage pipes
  - **Power Source**: Coin-cell battery

- **4-Inch WiFi-Based Model**
  - **Microcontroller**: ESP8266
  - **Sensor Type**: Normal RTC I/O to detect contact
  - **Connectivity**: Direct WiFi connection to AWS
  - **Setup**: Simple WiFi configuration via setup page
  - **Power Consumption**: Low-power with periodic wake-ups and manual checks
  - **Target Use**: Domestic use, offering an easy setup process for residential installations
  - **Size**: 4-inch drainage pipes
  - **Power Source**: 9V battery

## Key Functions

1. **Real-Time Blockage Monitoring**
   - Detects and alerts users when a blockage occurs, sending data to AWS for processing.
   - Continuous monitoring ensures that blockages are reported promptly to prevent potential issues.

2. **Low-Power Operation**
   - The device operates in a low-power sleep mode, waking up every 30 minutes to check for blockages. In case of a blockage, the wake-up frequency is reduced to 10 minutes for more frequent monitoring.

3. **AWS Cloud Integration**
   - All data collected by the device is sent to AWS, where it is processed and managed. AWS handles the storage, alerting, and further analysis.
   - Users can receive real-time alerts for blockages and battery status via the complementary web and mobile apps.

4. **App-Based Alerts**
   - Users are notified via mobile app and email about critical alerts, including blockages and battery status, allowing for proactive maintenance.
   - The app provides a full suite of tools for fleet management, including device registration, user management, and historical data review.

5. **Easy Setup (WiFi Variant)**
   - The 4-inch WiFi model features a simple configuration page for easy WiFi credential input, simplifying installation for residential users.
   - No manual setup or complex configuration is needed for this variant.

## Mechanical Design

- **High-Quality Industrial Design**: The device features an injection-molded, high-smooth plastic enclosure, ensuring durability and strength under tough conditions.
- **Waterproofing**: The enclosure includes proper gasket seals for effective waterproofing, ensuring reliability even in harsh environments.
- **Corrosion-Resistant Terminals**: The contact sensor terminals are made from corrosion-resistant materials to maintain accurate detection over time.
- **Easy Battery Replacement**: The design is user-friendly, making it simple to open and replace the battery when needed.

## Hardware

- **2-Inch LoRaWAN Model**: Uses a standard Dragino Contact Sensor Module, powered by a coin-cell battery, making it compact and efficient for industrial use.
- **4-Inch WiFi Model**: Powered by an ESP8266 microcontroller, which works on a 9V battery, offering a reliable connection to AWS via WiFi.

## Firmware

The firmware is optimized for speed and efficiency, ensuring minimal power consumption while delivering maximum performance. This optimization allows the device to operate for up to 6 to 8 months, depending on the number of blockages detected.

- **Over-the-Air (OTA) Firmware Support**: The device can receive OTA updates from AWS, ensuring the firmware remains up-to-date. It can quickly download updates from AWS S3 buckets and apply them without user intervention.
- **Firmware Recovery**: In case of a failed update, the device is designed to recover gracefully, avoiding any risk of device failure or bricking.

## Installation and Setup

### 2-Inch LoRaWAN Model (Industrial Use)
- **Step 1**: Install the cap on the 2-inch drainage pipe.
- **Step 2**: Connect the Dragino Contact Sensor Module to the LoRaWAN router.
- **Step 3**: Set up the LoRaWAN network through TTN and link the device to AWS for monitoring and data management.
- **Step 4**: The device will begin sending blockage data to AWS based on its wake-up schedule.

### 4-Inch WiFi Model (Domestic Use)
- **Step 1**: Install the cap on the 4-inch drainage pipe.
- **Step 2**: Enter setup mode by pressing the configuration button.
- **Step 3**: Use the setup page to input WiFi credentials.
- **Step 4**: Once connected, the device will automatically sync with AWS and start reporting blockage data.


## AWS Architecture

Both the 2-inch LoRaWAN and 4-inch WiFi models integrate seamlessly into Aquazen's robust AWS architecture. Data from the devices is transmitted to AWS, where it is processed in real-time for monitoring and alerting. The architecture supports a high-end web app and mobile app to manage multiple devices and provide insights into blockages, battery life, and system health.

- **Fleet Management**: The web app and mobile app allow building owners and users to manage device fleets, view alerts, and monitor performance.
- **Real-Time Data Processing**: AWS processes incoming data, generating instant notifications and insights that are sent to the users via the app or email.
- **Scalability**: The solution supports scaling to handle large fleets of devices, particularly for industrial and commercial use.

### AWS Architecture Flow Chart
![Project Image](https://drive.google.com/uc?export=view&id=10PZ9jSwBxgTimsetBjbjmmP1evl4TX_E) 

## Power Management
The device operates with minimal power consumption, utilizing a low-power sleep mode. It wakes up every 30 minutes to check for blockages, and if a blockage is detected, it reduces the wake-up interval to 10 minutes for continuous monitoring. 

## Future Enhancements
- **Advanced Analytics**: Future updates may introduce machine learning algorithms to predict and prevent blockages.
- **Additional Sensor Integrations**: Future versions may include additional sensors for a more comprehensive monitoring solution.
- **Multi-Zone Monitoring**: Adding support for geofencing to monitor blockages in specific areas and alert users when a blockage occurs outside designated zones.

## Licensing
The code provided in this repository is available under the following conditions:

- **Non-Commercial Use**: You may use and distribute the code for non-commercial purposes.
- **Restricted Modification**: You may not reverse-engineer, modify, or distribute any part of the implementation not explicitly provided in this repository.

### Commercial Use
For commercial use, including selling or distributing products based on this project, please contact [hamasaeed@gmail.com](mailto:hamasaeed@gmail.com) for licensing details.