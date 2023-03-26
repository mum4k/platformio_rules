load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def platformio_rules_dependencies():
    git_repository(
        name = "io_bazel_stardoc",
        remote = "https://github.com/bazelbuild/stardoc.git",
        tag = "0.5.3",
    )
    http_archive(
        name = "rules_python",
        sha256 = "81cbfc16dd1c022c4761267fa8b2feb881aaea9c3e1143f2e64630a1ad18c347",
        strip_prefix = "rules_python-0.16.1",
        url = "https://github.com/bazelbuild/rules_python/archive/0.16.1.zip",
    )
