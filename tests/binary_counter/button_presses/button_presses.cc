// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifdef NATIVE_BUILD

#include "tests/binary_counter/button_presses/button_presses.h"

#include "tests/arduino/arduino_interface.h"

#else // NATIVE_BUILD

#include <Button_presses.h>

#include <Arduino_interface.h>

#endif // NATIVE_BUILD

namespace binary_counter {

int CountButtonPresses(const arduino::ArduinoInterface &ino, int button_pin,
                       unsigned long timeout_ms,
                       unsigned long debounce_delay_ms) {
  unsigned long lastPressTime = ino.Millis();
  int oldButtonState = kUnpressed;
  int buttonState = kUnpressed;
  int count = 0;

  while (ino.Millis() - lastPressTime < timeout_ms) {
    buttonState = ino.DigitalRead(button_pin);
    if (oldButtonState == kUnpressed && buttonState == kPressed) {
      // The button was pressed, reset the timeout counter and loop (continue
      // the outer while loop) until the button gets released.
      lastPressTime = ino.Millis();
    } else if (oldButtonState == kPressed && buttonState == kUnpressed) {
      // The button was released, count one press.
      count++;
    }
    oldButtonState = buttonState;
    // Debounce a button press or release.
    ino.Delay(debounce_delay_ms);
  }
  return count;
}

} // namespace binary_counter
