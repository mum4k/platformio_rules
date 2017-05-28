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
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "arduino_interface",
    hdrs = ["arduino_interface.h"],
)

cc_library(
    name = "arduino_interface_mock",
    hdrs = ["arduino_interface_mock.h"],
    deps = [
        ":arduino_interface",
        "//external:gtest",
    ],
)

platformio_library(
    name = "Arduino_interface",
    hdr = "arduino_interface.h",
)

platformio_library(
    name = "Arduino_impl",
    src = "arduino_impl.cc",
    hdr = "arduino_impl.h",
    deps = [":Arduino_interface"],
)
