package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "platformio_ini_tmpl",
    srcs = ["platformio.ini.tmpl"],
)

load("@io_bazel_skydoc//stardoc:stardoc.bzl", "stardoc")

stardoc(
    name = "platformio_docs",
    input = "platformio.bzl",
    out = "platformio_doc.md",
)
