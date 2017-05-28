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

#include "tests/binary_counter/led_display/led_display.h"

#include "tests/binary_counter/convert/convert.h"

#else // NATIVE_BUILD

#include <Led_display.h>

#include <Convert.h>

#endif // NATIVE_BUILD

using arduino::ArduinoInterface;
using binary_counter::DecimalToBinary;

namespace binary_counter {

LedPins::LedPins(int led_0, int led_1, int led_2, int led_3, int led_4)
    : led_0(led_0), led_1(led_1), led_2(led_2), led_3(led_3), led_4(led_4) {}

LedDisplay::LedDisplay(const ArduinoInterface &ino, const LedPins &led_pins)
    : ino_(&ino) {
  led_pins_[0] = led_pins.led_0;
  led_pins_[1] = led_pins.led_1;
  led_pins_[2] = led_pins.led_2;
  led_pins_[3] = led_pins.led_3;
  led_pins_[4] = led_pins.led_4;
}

LedDisplay::~LedDisplay() {}

void LedDisplay::DisplayDecimal(int number) const {
  number %= kMaximumDecimal + 1;
  int binary = DecimalToBinary(number);

  for (int i = 0; i < kLedCount; i++) {
    if (binary == 0) {
      ino_->DigitalWrite(led_pins_[i], kLedOff);
      continue;
    }

    if (binary % 10 == 1) {
      ino_->DigitalWrite(led_pins_[i], kLedOn);
    } else {
      ino_->DigitalWrite(led_pins_[i], kLedOff);
    }
    binary /= 10;
  }
}

} // namespace binary_counter
