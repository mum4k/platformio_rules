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

// Displays numbers in binary format using simple Leds.
#ifndef TESTS_BINARY_COUNTER_LED_DISPLAY_LED_DISPLAY_H
#define TESTS_BINARY_COUNTER_LED_DISPLAY_LED_DISPLAY_H

#ifdef NATIVE_BUILD

#include "tests/arduino/arduino_interface.h"

#else // NATIVE_BUILD

#include <Arduino_interface.h>

#endif // NATIVE_BUILD

namespace binary_counter {

// Value used on the digital pin when turning an Led on.
const int kLedOn = 1;

// Value used on the digital pin when turning an Led off.
const int kLedOff = 0;

// The amount of Leds this library supports.
const int kLedCount = 5;

// The maximum decimal number five Leds can display.
const int kMaximumDecimal = 31;

// Maps each Led to a pin number on the Arduino device.
struct LedPins {
  // Constructs LedPins with the provided Led pins.
  LedPins(int led_0, int led_1, int led_2, int led_3, int led_4);

  // The pin number where the first (least significant bit) Led is connected.
  // This is the Led with weight of 2^0 in binary.
  int led_0 = 0;

  // The pin number of the Led with weight 2^1 in binary.
  int led_1 = 0;

  // The pin number of the Led with weight 2^2 in binary.
  int led_2 = 0;

  // The pin number of the Led with weight 2^3 in binary.
  int led_3 = 0;

  // The pin number of the Led with weight 2^4 in binary.
  int led_4 = 0;
};

// Given a wiring setup (the pin numbers) of five Leds, this class can display
// decimal numbers in the binary form.
class LedDisplay {
public:
  // Constructs the LedDisplay given the Arduino interface and the wiring of
  // the Leds.
  LedDisplay(const arduino::ArduinoInterface &ino, const LedPins &led_pins);
  ~LedDisplay();

  // Given a number in the decimal form, displays the number using five Leds in
  // the binary form.  This can display decimal numbers [0, kMaximumDecimal].
  // Larger numbers will be wrapped modulo kMaximumDecimal+1.
  void DisplayDecimal(int number) const;

private:
  // The wiring of the five Leds as provided at object construction time.
  // Member zero is led_0.
  int led_pins_[kLedCount];

  // The interface used when talking to the Arduino hardware.
  const arduino::ArduinoInterface *ino_;
};

} // namespace binary_counter

#endif // TESTS_BINARY_COUNTER_LED_DISPLAY_LED_DISPLAY_H
