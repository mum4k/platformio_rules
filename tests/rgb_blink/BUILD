load("//platformio:platformio.bzl", "platformio_library", "platformio_project")

platformio_library(
    name = "rgb_led",
    src = "rgb_led.cc",
    hdr = "rgb_led.h",
    lib_deps = ["adafruit/Adafruit NeoPixel#1.11.0"],
)

platformio_project(
    name = "rgb_blink",
    src = "rgb_blink.cc",
    board = "esp32-s3-devkitc-1",
    framework = "arduino",
    platform = "espressif32",
    deps = [":rgb_led"],
)