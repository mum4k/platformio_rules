# Google testing and mocking framework for C++.
new_git_repository(
    name = "googletest",
    build_file = "external_deps/gmock.BUILD",
    remote = "https://github.com/google/googletest",
    tag = "release-1.8.0",
)

bind(
    name = "gtest",
    actual = "@googletest//:gtest",
)

bind(
    name = "gtest_main",
    actual = "@googletest//:gtest_main",
)

# Drop-in replacement for deprecated git_repository.
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# Skydoc, documentation generator for custom Bazel rules.
git_repository(
    name = "io_bazel_rules_sass",
    remote = "https://github.com/bazelbuild/rules_sass.git",
    tag = "0.0.3",
)

load("@io_bazel_rules_sass//sass:sass.bzl", "sass_repositories")

sass_repositories()

git_repository(
    name = "bazel_skylib",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
    tag = "0.2.0",
)

git_repository(
    name = "io_bazel_skydoc",
    remote = "https://github.com/bazelbuild/skydoc.git",
    tag = "0.1.4",
)

load("@io_bazel_skydoc//skylark:skylark.bzl", "skydoc_repositories")

skydoc_repositories()
