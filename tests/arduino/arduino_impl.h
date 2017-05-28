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

// Implementation of the ArduinoInterface that uses the real Arduino hardware.
#ifndef TESTS_ARDUINO_ARDUINO_IMPL_H
#define TESTS_ARDUINO_ARDUINO_IMPL_H

#include <stdint.h>

#include <Arduino_interface.h>

namespace arduino {

// Implements the Arduino interface using the real Arduino hardware layer.
class ArduinoImpl : public ArduinoInterface {
public:
  ~ArduinoImpl() override;

  virtual int DigitalRead(uint8_t pin) const override;
  virtual void DigitalWrite(uint8_t pin, uint8_t value) const override;
  virtual unsigned long Millis(void) const override;
  virtual void Delay(unsigned long ms) const override;
};

} // namespace arduino

#endif // TESTS_ARDUINO_ARDUINO_IMPL_H
