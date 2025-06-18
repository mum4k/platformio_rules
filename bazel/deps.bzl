load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Load the main dependencies from platformio_rules
#
# This cannot load all the dependencies, as some load()s are needed from these,
# which cannot be done in a function, but this is the first step of the process
def platformio_rules_dependencies():
    # Import Stardoc, to write the documentation to our Starlark rules

    http_archive(
        name = "io_bazel_stardoc",
        sha256 = "ca933f39f2a6e0ad392fa91fd662545afcbd36c05c62365538385d35a0323096",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/stardoc/releases/download/0.8.0/stardoc-0.8.0.tar.gz",
            "https://github.com/bazelbuild/stardoc/releases/download/0.8.0/stardoc-0.8.0.tar.gz",
        ],
    )

    # Import python, this is the first step to get pip_parse() dependencies to
    # be corrently imported
    http_archive(
        name = "rules_python",
        sha256 = "2cc26bbd53854ceb76dd42a834b1002cd4ba7f8df35440cf03482e045affc244",
        strip_prefix = "rules_python-1.3.0",
        url = "https://github.com/bazel-contrib/rules_python/releases/download/1.3.0/rules_python-1.3.0.tar.gz",
    )
