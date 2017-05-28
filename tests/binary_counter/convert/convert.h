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

// Functions that perform number conversions.
#ifndef TESTS_BINARY_COUNTER_CONVERT_CONVERT_H
#define TESTS_BINARY_COUNTER_CONVERT_CONVERT_H

namespace binary_counter {

// The maximum supported decimal number.
// The int size on Arduino is 16 bits. Maximum decimal value is 2^15-1 (32767).
// This is the maximum binary value that can be encoded in such int.
const int kMaxDecimal = 31;

// Converts a decimal number into a binary representation.
// Example: for a decimal 3 returns binary 11.
// Returns zero for negative numbers and for numbers larger than 32.
int DecimalToBinary(int decimal);

} // namespace binary_counter

#endif // TESTS_BINARY_COUNTER_CONVERT_CONVERT_H
