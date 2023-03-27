load("//platformio:platformio.bzl", "platformio_project")

filegroup(
    name = "fs_data",
    data = glob(["fs_data/*"]),
)

platformio_project(
    name = "fs",
    src = "fs.cc",
    board = "esp32-s3-devkitc-1",
    framework = "arduino",
    platform = "espressif32",
    upload_fs = ":fs_data",
    deps = [
        "//tests/arduino:Arduino_impl",
        "//tests/arduino:Arduino_interface",
    ],
)
