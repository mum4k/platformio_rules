load("@py_deps//:requirements.bzl", "requirement")

package(
    default_visibility = ["//visibility:public"],
)

py_binary(
    name = "template_renderer",
    srcs = ["template_renderer.py"],
    deps = [
        requirement("jinja2"),
    ]
)

filegroup(
    name = "platformio_ini_tmpl",
    srcs = ["platformio.ini.tmpl"],
)

exports_files(["platformio.bzl"])
