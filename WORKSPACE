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

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "io_bazel_stardoc",
    remote = "https://github.com/bazelbuild/stardoc.git",
    tag = "0.5.3",
)

load("@io_bazel_stardoc//:setup.bzl", "stardoc_repositories")
stardoc_repositories()
