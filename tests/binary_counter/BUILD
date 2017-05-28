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

load("//platformio:platformio.bzl", "platformio_project")

platformio_project(
    name = "binary_counter",
    src = "binary_counter.cc",
    board = "megaatmega2560",
    framework = "arduino",
    platform = "atmelavr",
    deps = [
        "//tests/arduino:Arduino_impl",
        "//tests/arduino:Arduino_interface",
        "//tests/binary_counter/button_presses:Button_presses",
        "//tests/binary_counter/led_display:Led_display",
    ],
)
