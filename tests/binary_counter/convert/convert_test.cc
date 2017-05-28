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

#include "tests/binary_counter/convert/convert.h"
#include "gtest/gtest.h"

namespace binary_counter {
namespace {

TEST(DecimalToBinaryTest, ConvertsZero) { EXPECT_EQ(0, DecimalToBinary(0)); }

TEST(DecimalToBinaryTest, NegativeIsZero) { EXPECT_EQ(0, DecimalToBinary(-1)); }

TEST(DecimalToBinaryTest, ConvertsNumbers) {
  EXPECT_EQ(1, DecimalToBinary(1));
  EXPECT_EQ(10, DecimalToBinary(2));
  EXPECT_EQ(11, DecimalToBinary(3));
  EXPECT_EQ(100, DecimalToBinary(4));
  EXPECT_EQ(101, DecimalToBinary(5));
  EXPECT_EQ(110, DecimalToBinary(6));
  EXPECT_EQ(111, DecimalToBinary(7));
  EXPECT_EQ(1000, DecimalToBinary(8));
  EXPECT_EQ(1001, DecimalToBinary(9));
  EXPECT_EQ(1010, DecimalToBinary(10));
  EXPECT_EQ(1011, DecimalToBinary(11));
  EXPECT_EQ(1100, DecimalToBinary(12));
  EXPECT_EQ(1101, DecimalToBinary(13));
  EXPECT_EQ(1110, DecimalToBinary(14));
  EXPECT_EQ(1111, DecimalToBinary(15));
}

TEST(DecimalToBinaryTest, ConvertsMaxArduinoInt) {
  EXPECT_EQ(11111, DecimalToBinary(kMaxDecimal));
}

TEST(DecimalToBinaryTest, MoreThanMaximumIsZero) {
  EXPECT_EQ(0, DecimalToBinary(kMaxDecimal + 1));
}

} // namespace
} // namespace binary_counter
