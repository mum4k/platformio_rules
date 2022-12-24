load("//platformio:platformio.bzl", "platformio_project")

platformio_project(
    name = "blink",
    src = "blink.cc",
    board = "attiny85",
    framework = "arduino",
    platform = "atmelavr",
    build_flags = ["-D TARGET_PIN=4"],
    programmer = "arduino_as_isp",
    port = "/dev/ttyUSB0",
)

