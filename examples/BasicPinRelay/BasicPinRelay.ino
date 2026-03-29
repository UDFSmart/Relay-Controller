/**
 * BasicPinRelay.ino - Basic GPIO relay control example.
 * * This sketch demonstrates how to toggle a relay connected to a digital pin
 * using the state-checking logic of the UDFSOFT Smart-Relay library.
 * * Hardware Setup:
 * - Relay Signal -> GPIO 0 (or your chosen pin)
 * - Relay VCC    -> 3.3V / 5V
 * - Relay GND    -> GND
 * * Developed by UDFSOFT (https://udfsoft.com/)
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

#include <Arduino.h>
#include <PinRelayController.h>

uint8_t relayPins[] = { 0 };
PinRelayController relay(relayPins, 1);

void setup() {
  Serial.begin(115200);
  relay.begin();
  delay(500);
}

void loop() {
  if (relay.getState(0)) {
    relay.setOff(0);
    Serial.println("Turning OFF...");
  } else {
    relay.setOn(0);
    Serial.println("Turning ON...");
  }
  delay(3000);
}
