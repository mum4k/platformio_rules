# Google testing and mocking framework for C++.
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_googletest",
    sha256 = "24564e3b712d3eb30ac9a85d92f7d720f60cc0173730ac166f27dda7fed76cb2",
    strip_prefix = "googletest-release-1.12.1",
    urls = ["https://github.com/google/googletest/archive/release-1.12.1.zip"],
)

# Stardoc, documentation generator for custom Bazel rules.
http_archive(
    name = "io_bazel_rules_sass",
    sha256 = "05db38271919d3d209a9f58db412a5bf2af2def7d4c1fae17b401dccbad97178",
    strip_prefix = "rules_sass-1.57.0",
    url = "https://github.com/bazelbuild/rules_sass/archive/1.57.0.zip",
)

http_archive(
    name = "io_bazel_skylib",
    sha256 = "4756ab3ec46d94d99e5ed685d2d24aece484015e45af303eb3a11cab3cdc2e71",
    urls = ["https://github.com/bazelbuild/bazel-skylib/archive/1.3.0.zip"],
)

load("//bazel:deps.bzl", "platformio_rules_dependencies")

platformio_rules_dependencies()

######################## Additional Rules Setup ########################
load("@rules_python//python:repositories.bzl", "py_repositories")

py_repositories()

load("@io_bazel_stardoc//:setup.bzl", "stardoc_repositories")

stardoc_repositories()

load("@rules_java//java:rules_java_deps.bzl", "rules_java_dependencies")

rules_java_dependencies()

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

load("@rules_jvm_external//:repositories.bzl", "rules_jvm_external_deps")

rules_jvm_external_deps()

load("@rules_jvm_external//:setup.bzl", "rules_jvm_external_setup")

rules_jvm_external_setup()

load("@io_bazel_stardoc//:deps.bzl", "stardoc_external_deps")

stardoc_external_deps()

load("@stardoc_maven//:defs.bzl", stardoc_pinned_maven_install = "pinned_maven_install")

stardoc_pinned_maven_install()

########################################################################
load("//bazel:transitive.bzl", "platformio_rules_transitive_dependencies")

platformio_rules_transitive_dependencies()

load("@rules_python//python:pip.bzl", "pip_parse")

pip_parse(
    name = "py_deps",
    python_interpreter_target = "@python_3_12_host//:python",
    requirements_lock = "//:requirements_lock.txt",
)

load("//bazel:pip_install.bzl", "platformio_rules_pip_install_dependencies")

platformio_rules_pip_install_dependencies()
