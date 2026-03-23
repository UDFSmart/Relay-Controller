# Relay Controller Library

[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![Framework](https://img.shields.io/badge/Framework-Arduino-orange.svg)](https://www.arduino.cc/)
![Framework](https://img.shields.io/badge/ESP32-green.svg)

A flexible, OOP-based Arduino library for controlling relays. This library provides a clean hardware abstraction layer, allowing you to switch between direct GPIO pin control and Serial-based relay modules without changing your application logic.

## Features

* **Hardware Abstraction:** Unified interface for different relay types.
* **Memory Safe:** Prevents double-free errors and accidental object copying using `delete` operators.
* **Flexible Transport:** `SerialRelayController` uses the `Stream` class, making it compatible with `HardwareSerial`, `SoftwareSerial`, and even USB Serial.
* **State Management:** Built-in tracking of relay states via `getState()`.
* **Production Ready:** Uses `const` parameters and `nullptr` initialization for robustness.

## Supported Architectures

* **ESP8266**
* **ESP32** (using HardwareSerial or SoftwareSerial)
* **AVR** (Arduino Uno, Nano, Mega, etc.)
* **STM32**

## Supported devices

Below is a list of devices on which this lib is tested:

[ESP8266 ESP-01 WIFI Wireless with 2CH Relay Module Board](https://github.com/UDFSmart/Relay-Controller/blob/main/docs/ESP_01_RELAY_X2_README.md)

------

## Installation

1.  Download the repository as a `.zip` file.
2.  In the Arduino IDE, go to **Sketch** -> **Include Library** -> **Add .ZIP Library...**.
3.  Select the downloaded file.

## Quick Start

### Basic GPIO Control
```cpp
#include <PinRelayController.h>

uint8_t pins[] = {D1, D2}; // Relay pins
PinRelayController relay(pins, 2);

void setup() {
  relay.begin();
  relay.setOn(0); // Turn on first relay
}
```

### Serial Relay Control (A0 Protocol)

```cpp
#include <SerialRelayController.h>
#include <SoftwareSerial.h>

SoftwareSerial swSerial(D5, D6);
SerialRelayController relay(swSerial, 2);

void setup() {
  swSerial.begin(115200);
  relay.begin();
  relay.setOff(1); // Turn off second relay
}
```

## Class Architecture

The library is built on a polymorphic base class RelayController.
  * RelayController: Abstract base class.
  * PinRelayController: Implementation for relays connected directly to MCU pins.
  * SerialRelayController: Implementation for serial modules (typically using the 0xA0 command protocol).
  
  
## API Reference

```
void begin()
```
Initializes the hardware (sets pinMode or prepares communication).

```
void setOn(uint8_t channel)
```
Activates the specified relay channel.

```
void setOff(uint8_t channel)
```
Deactivates the specified relay channel.

```
bool getState(uint8_t channel)
```
Returns the current logical state of the relay (true for ON, false for OFF).

## License

```
Copyright © 2026 javavirys (UDFSOFT).

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
```
