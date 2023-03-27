# Google testing and mocking framework for C++.
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "com_google_googletest",
    urls = ["https://github.com/google/googletest/archive/release-1.12.1.zip"],
    strip_prefix = "googletest-release-1.12.1",
    sha256 = "24564e3b712d3eb30ac9a85d92f7d720f60cc0173730ac166f27dda7fed76cb2",
)

# Stardoc, documentation generator for custom Bazel rules.
http_archive(
    name = "io_bazel_rules_sass",
    url = "https://github.com/bazelbuild/rules_sass/archive/1.57.0.zip",
    strip_prefix = "rules_sass-1.57.0",
    sha256 = "05db38271919d3d209a9f58db412a5bf2af2def7d4c1fae17b401dccbad97178",
)

http_archive(
    name = "io_bazel_skylib",
    urls = ["https://github.com/bazelbuild/bazel-skylib/archive/1.3.0.zip"],
    sha256 = "4756ab3ec46d94d99e5ed685d2d24aece484015e45af303eb3a11cab3cdc2e71",
)

load("//bazel:deps.bzl", "platformio_rules_dependencies")
platformio_rules_dependencies()

load("//bazel:transitive.bzl", "platformio_rules_transitive_dependencies")
platformio_rules_transitive_dependencies()

load("@python3_10_8//:defs.bzl", "interpreter")
load("@rules_python//python:pip.bzl", "pip_parse")

pip_parse(
    name = "py_deps",
    python_interpreter_target = interpreter,
    requirements_lock = "//:requirements_lock.txt",
)

load("//bazel:pip_install.bzl", "platformio_rules_pip_install_dependencies")
platformio_rules_pip_install_dependencies()