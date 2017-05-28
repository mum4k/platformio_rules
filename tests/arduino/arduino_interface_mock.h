/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// A mock of the ArduinoInterface.
#ifndef TESTS_ARDUINO_ARDUINO_INTERFACE_MOCK_H
#define TESTS_ARDUINO_ARDUINO_INTERFACE_MOCK_H

#include <stdint.h>

#include "gmock/gmock.h"
#include "tests/arduino/arduino_interface.h"

namespace arduino {

class MockArduinoInterface : public ArduinoInterface {
public:
  MOCK_CONST_METHOD1(DigitalRead, int(uint8_t pin));
  MOCK_CONST_METHOD2(DigitalWrite, void(uint8_t pin, uint8_t value));
  MOCK_CONST_METHOD0(Millis, unsigned long());
  MOCK_CONST_METHOD1(Delay, void(unsigned long ms));
};

} // namespace arduino

#endif // TESTS_ARDUINO_ARDUINO_INTERFACE_MOCK_H
