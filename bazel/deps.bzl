load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Load the main dependencies from platformio_rules
#
# This cannot load all the dependencies, as some load()s are needed from these,
# which cannot be done in a function, but this is the first step of the process
def platformio_rules_dependencies():
    # Import Stardoc, to write the documentation to our Starlark rules
    git_repository(
        name = "io_bazel_stardoc",
        remote = "https://github.com/bazelbuild/stardoc.git",
        tag = "0.5.3",
    )
    # Import python, this is the first step to get pip_parse() dependencies to
    # be corrently imported
    http_archive(
        name = "rules_python",
        sha256 = "81cbfc16dd1c022c4761267fa8b2feb881aaea9c3e1143f2e64630a1ad18c347",
        strip_prefix = "rules_python-0.16.1",
        url = "https://github.com/bazelbuild/rules_python/archive/0.16.1.zip",
    )
