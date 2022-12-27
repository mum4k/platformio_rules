load("//platformio:platformio.bzl", "platformio_project")

configs = [
    (
        "attiny85",
        "attiny85",
        ["-DTARGET_PIN=4"],
        "arduino_as_isp",
        "/dev/ttyUSB0",
    ),
    (
        "nano",
        "nanoatmega328",
        [],
        "direct",
        "unused",
    ),
]

[platformio_project(
    name = "blink_%s" % config[0],
    src = "blink.cc",
    board = config[1],
    framework = "arduino",
    platform = "atmelavr",
    build_flags = config[2],
    programmer = config[3],
    port = config[4],
    deps = [
        "//tests/arduino:Arduino_impl",
        "//tests/arduino:Arduino_interface",
    ],
) for config in configs]

