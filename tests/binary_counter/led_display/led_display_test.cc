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

#include "tests/binary_counter/led_display/led_display.h"

#include "gmock/gmock.h"
#include "tests/arduino/arduino_interface_mock.h"
#include "gtest/gtest.h"

namespace binary_counter {
namespace {

// Stub Led pins used in these tests.
const int kLed0Pin = 0;
const int kLed1Pin = 1;
const int kLed2Pin = 2;
const int kLed3Pin = 3;
const int kLed4Pin = 4;

using ::testing::InSequence;
using arduino::MockArduinoInterface;

class LedDisplayTest : public ::testing::Test {
protected:
  LedDisplayTest()
      : mock_arduino_interface_(),
        led_pins_(kLed0Pin, kLed1Pin, kLed2Pin, kLed3Pin, kLed4Pin),
        led_display_(mock_arduino_interface_, led_pins_) {}

  const MockArduinoInterface mock_arduino_interface_;
  const LedPins led_pins_;
  const LedDisplay led_display_;
};

TEST_F(LedDisplayTest, DisplaysZero) {
  InSequence s;

  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed0Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed1Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed2Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed3Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed4Pin, kLedOff));
  led_display_.DisplayDecimal(0);
}

TEST_F(LedDisplayTest, DisplaysOne) {
  InSequence s;

  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed0Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed1Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed2Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed3Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed4Pin, kLedOff));
  led_display_.DisplayDecimal(1);
}

TEST_F(LedDisplayTest, DisplaysTen) {
  InSequence s;

  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed0Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed1Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed2Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed3Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed4Pin, kLedOff));
  led_display_.DisplayDecimal(10);
}

TEST_F(LedDisplayTest, DisplaysTwentyOne) {
  InSequence s;

  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed0Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed1Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed2Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed3Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed4Pin, kLedOn));
  led_display_.DisplayDecimal(21);
}

TEST_F(LedDisplayTest, DisplaysMax) {
  InSequence s;

  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed0Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed1Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed2Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed3Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed4Pin, kLedOn));
  led_display_.DisplayDecimal(kMaximumDecimal);
}

TEST_F(LedDisplayTest, WrapsAtMax) {
  InSequence s;

  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed0Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed1Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed2Pin, kLedOn));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed3Pin, kLedOff));
  EXPECT_CALL(mock_arduino_interface_, DigitalWrite(kLed4Pin, kLedOff));
  led_display_.DisplayDecimal(kMaximumDecimal + 1 + 5);
}

} // namespace
} // namespace binary_counter
