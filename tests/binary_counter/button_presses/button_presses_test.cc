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

#include "tests/binary_counter/button_presses/button_presses.h"

#include "gmock/gmock.h"
#include "tests/arduino/arduino_interface_mock.h"
#include "gtest/gtest.h"

namespace binary_counter {
namespace {

// Stub button pin used in these tests.
const int kButtonPin = 0;

using ::testing::InvokeWithoutArgs;
using ::testing::NiceMock;
using ::testing::Return;

using arduino::MockArduinoInterface;

// Used to simulate clock on an Arduino device.
class FakeClock {
public:
  // Advances the fake clock by one ms and returns the pre-increment value.
  unsigned long Tick() { return millis_++; }

private:
  // Fake internal clock. Every call to Millis() returns and post-increments.
  unsigned long millis_ = 0;
};

class CountButtonPressesTest : public ::testing::Test {
protected:
  CountButtonPressesTest() : mock_arduino_interface_() {
    ON_CALL(mock_arduino_interface_, Delay(kDefaultDebounceDelayMs))
        .WillByDefault(Return());
    EXPECT_CALL(mock_arduino_interface_, Millis())
        .WillRepeatedly(InvokeWithoutArgs(&timer_, &FakeClock::Tick));
  }

  const NiceMock<MockArduinoInterface> mock_arduino_interface_;
  FakeClock timer_;
};

TEST_F(CountButtonPressesTest, ZeroWhenNoPresses) {
  EXPECT_CALL(mock_arduino_interface_, DigitalRead(kButtonPin))
      .Times(2)
      .WillOnce(Return(kUnpressed))
      .WillOnce(Return(kUnpressed));
  EXPECT_EQ(0, CountButtonPresses(mock_arduino_interface_, kButtonPin, 3,
                                  kDefaultDebounceDelayMs));
}

TEST_F(CountButtonPressesTest, CountsSinglePress) {
  EXPECT_CALL(mock_arduino_interface_, DigitalRead(kButtonPin))
      .Times(3)
      .WillOnce(Return(kPressed))
      .WillOnce(Return(kUnpressed))
      .WillOnce(Return(kUnpressed));
  EXPECT_EQ(1, CountButtonPresses(mock_arduino_interface_, kButtonPin, 3,
                                  kDefaultDebounceDelayMs));
}

TEST_F(CountButtonPressesTest, CountsMultiplePresses) {
  EXPECT_CALL(mock_arduino_interface_, DigitalRead(kButtonPin))
      .Times(5)
      .WillOnce(Return(kPressed))
      .WillOnce(Return(kUnpressed))
      .WillOnce(Return(kPressed))
      .WillOnce(Return(kUnpressed))
      .WillOnce(Return(kUnpressed));
  EXPECT_EQ(2, CountButtonPresses(mock_arduino_interface_, kButtonPin, 3,
                                  kDefaultDebounceDelayMs));
}

} // namespace
} // namespace binary_counter
