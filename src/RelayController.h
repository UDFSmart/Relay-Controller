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

#pragma once
#include <Arduino.h>
#include <string.h>

class RelayController {
public:

  RelayController(const uint8_t count)
    : _channelsCount(count) {
    _states = new bool[_channelsCount];
    for (uint8_t i = 0; i < _channelsCount; i++) {
      _states[i] = false;
    }
  }

  RelayController(const RelayController&) = delete;

  RelayController& operator=(const RelayController&) = delete;

  virtual ~RelayController() {
    delete[] _states;
  }

  virtual void begin() = 0;
  virtual void setOn(const uint8_t channel) = 0;
  virtual void setOff(const uint8_t channel) = 0;

  virtual bool getState(const uint8_t channel) const {
    if (channel >= _channelsCount) return false;
    return _states[channel];
  }
protected:
  uint8_t _channelsCount;
  bool* _states = nullptr;
};
