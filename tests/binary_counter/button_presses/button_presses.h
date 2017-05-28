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

// Library that counts the number of times a button connected to a digital pin
// is pressed.
#ifndef TESTS_BINARY_COUNTER_BUTTON_PRESSES_BUTTON_PRESSES_H
#define TESTS_BINARY_COUNTER_BUTTON_PRESSES_BUTTON_PRESSES_H

#ifdef NATIVE_BUILD

#include "tests/arduino/arduino_interface.h"

#else // NATIVE_BUILD

#include <Arduino_interface.h>

#endif // NATIVE_BUILD

namespace binary_counter {

// Value read on the digital pin when the button isn't pressed.
const int kUnpressed = 0;

// Value read on the digital pin when the button is pressed.
const int kPressed = 1;

// The recommended default value for the timeout when counting button presses.
const unsigned long kDefaultTimeoutMs = 1000;

// The recommended default value for the debounce delay when counting button
// presses.
const unsigned long kDefaultDebounceDelayMs = 50;

// Returns the number of times a digital button connected to the specified pin
// was pressed.  Keeps counting button presses until no button press occurs for
// at least the specified timeout.  Stops reading the digital pin status for
// the specified debounce delay after every button press.
int CountButtonPresses(const arduino::ArduinoInterface &ino, int pin,
                       unsigned long timeout_ms,
                       unsigned long debounce_delay_ms);

} // namespace binary_counter

#endif // TESTS_BINARY_COUNTER_BUTTON_PRESSES_BUTTON_PRESSES_H
