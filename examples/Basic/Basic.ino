/*
 *    Copyright 2026 UDFOwner
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 *
 *    More details: https://udfsoft.com/
 */

/**
 * Basic.ino - Example for the Relay Controller library.
 * * This example demonstrates how the RelayController abstraction allows you
 * to manage relays identically, whether they are connected directly to 
 * GPIO pins or controlled via a Serial relay module.
 */

#include <Arduino.h>
#include <PinRelayController.h>
#include <SerialRelayController.h>

// Pin definitions for SoftwareSerial (used by SerialRelayController)
#define RELAY_RX 3  // GPIO3 (RX)
#define RELAY_TX 1  // GPIO1 (TX)

// Pointer to the base class - allows working with any controller implementation
RelayController* relay = nullptr;

/**
 * Factory function to create a specific controller instance.
 * @param useSerial If true, creates a SerialRelayController, otherwise a PinRelayController.
 */
RelayController* createRelayController(bool useSerial = false) {
  if (useSerial) {
    // Use static to ensure the SoftwareSerial object persists in memory
    static SoftwareSerial _serial(RELAY_RX, RELAY_TX);
    return new SerialRelayController(_serial, 2); // 2-channel serial relay
  }

  // Define pins for direct GPIO control
  static uint8_t pins[] = { 0, 2 };
  return new PinRelayController(pins, 2); // 2-channel pin relay
}

void setup() {
  // Initialize hardware serial for debug logging
  Serial.begin(115200);
  delay(1000);
  Serial.println(F("Relay Controller System Initializing..."));

  // 1. Initialize the desired controller type.
  // Switch 'false' to 'true' to use the Serial-based relay module instead.
  relay = createRelayController(false);

  // 2. Call begin() to configure pins or serial communication
  relay->begin();

  Serial.println(F("Initialization complete. Starting relay test..."));
}

void loop() {
  // Demonstrate basic relay operations: Toggle each channel in a loop
  for (uint8_t i = 0; i < 2; i++) {
    Serial.print(F("Turning ON channel: "));
    Serial.println(i);
    
    relay->setOn(i);
    delay(1000);

    // Verify current state using the getState() method
    if (relay->getState(i)) {
      Serial.println(F("Status: Channel is ACTIVE"));
    }

    Serial.print(F("Turning OFF channel: "));
    Serial.println(i);
    
    relay->setOff(i);
    delay(1000);
  }

  Serial.println(F("--- Cycle finished ---"));
  delay(2000);
}
