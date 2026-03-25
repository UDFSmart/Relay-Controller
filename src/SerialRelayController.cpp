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

#include "SerialRelayController.h"
#include "Stream.h"

SerialRelayController::SerialRelayController(Stream& serial, const uint8_t channelsCount)
  : RelayController(channelsCount), _serial(serial) {
}

void SerialRelayController::begin() {
  // None
}

void SerialRelayController::setOn(const uint8_t channel) {
  setRelayState(channel, true);
  delay(350);
}

void SerialRelayController::setOff(const uint8_t channel) {
  setRelayState(channel, false);
  delay(350);
}

void SerialRelayController::setRelayState(const uint8_t relay, bool state) {

  if (relay >= _channelsCount) return;

  uint8_t hwRelay = relay + 1;

  byte cmd[4];

  cmd[0] = 0xA0;
  cmd[1] = hwRelay;
  cmd[2] = state ? 0x01 : 0x00;
  cmd[3] = cmd[0] + cmd[1] + cmd[2];

  _serial.write(cmd, 4);

  _states[relay] = state;
}
