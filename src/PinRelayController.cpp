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

#include "PinRelayController.h"

PinRelayController::PinRelayController(const uint8_t* pins, const uint8_t count)
  : RelayController(count) {

  _pins = new uint8_t[_channelsCount];

  for (uint8_t i = 0; i < _channelsCount; i++) {
    _pins[i] = pins[i];
  }
}

PinRelayController::PinRelayController(const uint8_t* pins, const uint8_t count, RelayCallback onCustomOn, RelayCallback onCustomOff)
  : PinRelayController(pins, count) {

  onRelayFunction = onCustomOn;
  offRelayFunction = onCustomOff;
}

void PinRelayController::begin() {
  for (uint8_t i = 0; i < _channelsCount; i++) {
    pinMode(_pins[i], OUTPUT);
    setOffRelay(_pins[i]);
  }
}

void PinRelayController::setOn(const uint8_t channel) {
  if (channel >= _channelsCount) return;

  setOnRelay(_pins[channel]);
  _states[channel] = true;
}

void PinRelayController::setOff(const uint8_t channel) {
  if (channel >= _channelsCount) return;

  setOffRelay(_pins[channel]);
  _states[channel] = false;
}

void PinRelayController::setOnRelay(const uint8_t pin) {
  if (onRelayFunction == nullptr) {
    digitalWrite(pin, LOW);
  } else {
    onRelayFunction(pin);
  }
}
void PinRelayController::setOffRelay(const uint8_t pin) {
  if (offRelayFunction == nullptr) {
    digitalWrite(pin, HIGH);
  } else {
    offRelayFunction(pin);
  }
}

PinRelayController::~PinRelayController() {
  delete[] _pins;
}
