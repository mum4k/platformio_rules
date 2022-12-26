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

configs = [
    (
        "mega",
        "megaatmega2560",
        [
            "-DRED_LED_PIN=44",
            "-DORANGE_LED_PIN=46",
            "-DGREEN_LED_PIN=48",
            "-DBLUE_LED_PIN=50",
            "-DYELLOW_LED_PIN=52",
            "-DBUTTON_PIN=2",
        ],
    ),
    (
        "nano",
        "nanoatmega328",
        [
            "-DRED_LED_PIN=3",
            "-DORANGE_LED_PIN=4",
            "-DGREEN_LED_PIN=5",
            "-DBLUE_LED_PIN=6",
            "-DYELLOW_LED_PIN=7",
            "-DBUTTON_PIN=2",
        ],
    ),
]

[platformio_project(
    name = "binary_counter_%s" % config[0],
    src = "binary_counter.cc",
    board = config[1],
    framework = "arduino",
    platform = "atmelavr",
    build_flags = config[2],
    deps = [
        "//tests/arduino:Arduino_impl",
        "//tests/arduino:Arduino_interface",
        "//tests/binary_counter/button_presses:Button_presses",
        "//tests/binary_counter/led_display:Led_display",
    ],
) for config in configs]
