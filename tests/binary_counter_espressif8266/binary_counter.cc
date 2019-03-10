// Copyright 2019 Google Inc.
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

// The binary_counter starts in an intro mode displaying numbers [0, 31] in the
// binary form.  When the button is presses it will exit the intro mode. From
// now on, it will count the number of continuous button presses and display it
// each time the button is pressed.

#include <Arduino.h>
#include <Arduino_impl.h>
#include <Arduino_interface.h>
#include <Button_presses.h>
#include <Led_display.h>

using arduino::ArduinoImpl;
using arduino::ArduinoInterface;
using binary_counter::CountButtonPresses;
using binary_counter::kMaximumDecimal;
using binary_counter::kDefaultDebounceDelayMs;
using binary_counter::kDefaultTimeoutMs;
using binary_counter::LedDisplay;
using binary_counter::LedPins;

// Arduino hardware layer.
const ArduinoImpl ino = ArduinoImpl();

// Pin numbers where the Leds are wired.
const int kRedLedPin = 44;
const int kOrangeLedPin = 46;
const int kGreenLedPin = 48;
const int kBlueLedPin = 50;
const int kYellowLedPin = 52;
const LedPins led_pins(kYellowLedPin, kBlueLedPin, kGreenLedPin, kOrangeLedPin,
                       kRedLedPin);

// Class that can display binary numbers using Leds.
const LedDisplay led = LedDisplay(ino, led_pins);

// Pin where the button is wired.
const int kButtonPin = 2;

// Remains in the intro mode until this gets set to false.
volatile bool intro = true;

// The delay between displaying numbers in the intro mode.
const unsigned long kIntroDelayMs = 500;

// Processes the first button press that ends the intro mode.
void ExitIntroMode() {
  detachInterrupt(digitalPinToInterrupt(kButtonPin));
  intro = false;
}

void setup() {
  // Configure pins where the Leds are connected.
  pinMode(kRedLedPin, OUTPUT);
  pinMode(kOrangeLedPin, OUTPUT);
  pinMode(kGreenLedPin, OUTPUT);
  pinMode(kBlueLedPin, OUTPUT);
  pinMode(kYellowLedPin, OUTPUT);

  // Configure the pin where the button is connected and attach an interrupt.
  pinMode(kButtonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(kButtonPin), ExitIntroMode, CHANGE);
}

int number = 0;
void loop() {
  // The intro mode.
  if (intro) {
    for (int i = 0; i <= kMaximumDecimal; i++) {
      led.DisplayDecimal(i);

      ino.Delay(kIntroDelayMs);
      if (!intro) {
        break;
      }
    }
  }

  // Intro is done, counting button presses.
  if (ino.DigitalRead(kButtonPin)) {
    number = CountButtonPresses(ino, kButtonPin, kDefaultTimeoutMs,
                                kDefaultDebounceDelayMs);
  }
  led.DisplayDecimal(number);
}
