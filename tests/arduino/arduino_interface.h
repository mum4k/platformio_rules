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

// A virtual interface over the functions exposed by Arduino.h.
// This allows for dependancy injection and mocking in the native C++ land.
#ifndef TESTS_ARDUINO_ARDUINO_INTERFACE_H
#define TESTS_ARDUINO_ARDUINO_INTERFACE_H

#include <stdint.h>

namespace arduino {

// Defines a C++ interface for accessing the Arduino hardware layer.
class ArduinoInterface {
public:
  virtual ~ArduinoInterface() {}

  // Reads the value from a specified digital pin, either HIGH or LOW.
  // https://www.arduino.cc/en/Reference/DigitalRead
  virtual int DigitalRead(uint8_t pin) const = 0;

  // Write a HIGH or a LOW value to a digital pin.
  // https://www.arduino.cc/en/Reference/DigitalWrite
  virtual void DigitalWrite(uint8_t pin, uint8_t value) const = 0;

  // Returns the number of milliseconds since the Arduino board began running
  // the current program. This number will overflow (go back to zero), after
  // approximately 50 days.
  // https://www.arduino.cc/en/Reference/Millis
  virtual unsigned long Millis(void) const = 0;

  // Pauses the program for the amount of time (in miliseconds) specified as
  // parameter. (There are 1000 milliseconds in a second.)
  // https://www.arduino.cc/en/Reference/Delay
  virtual void Delay(unsigned long ms) const = 0;
};

} // namespace arduino

#endif // TESTS_ARDUINO_ARDUINO_INTERFACE_H
