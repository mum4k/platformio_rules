# Copyright 2017 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("//platformio:platformio.bzl", "platformio_library")

package(
    default_visibility = [
        "//tests/binary_counter:__subpackages__",
    ],
)

cc_library(
    name = "button_presses",
    srcs = ["button_presses.cc"],
    hdrs = ["button_presses.h"],
    defines = ["NATIVE_BUILD"],
    deps = [
        "//tests/arduino:arduino_interface",
    ],
)

cc_test(
    name = "button_presses_test",
    srcs = ["button_presses_test.cc"],
    deps = [
        ":button_presses",
        "//external:gtest_main",
        "//tests/arduino:arduino_interface_mock",
    ],
)

platformio_library(
    name = "Button_presses",
    src = "button_presses.cc",
    hdr = "button_presses.h",
    deps = [
        "//tests/arduino:Arduino_interface",
    ],
)
