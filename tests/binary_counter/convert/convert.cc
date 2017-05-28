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

#include "tests/binary_counter/convert/convert.h"

#else // NATIVE_BUILD

#include <Convert.h>

#endif // NATIVE_BUILD

namespace binary_counter {

int DecimalToBinary(int decimal) {
  if (decimal <= 0 || decimal > kMaxDecimal) {
    return 0;
  }

  int binary = 0;
  int multiplier = 1;
  int remainder = 0;

  while (decimal != 0) {
    remainder = decimal % 2;
    decimal /= 2;
    binary += remainder * multiplier;
    multiplier *= 10;
  }
  return binary;
}

} // namespace binary_counter
