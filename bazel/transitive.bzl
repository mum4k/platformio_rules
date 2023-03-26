load("@io_bazel_stardoc//:setup.bzl", "stardoc_repositories")
load("@rules_python//python:repositories.bzl", "python_register_toolchains")

def platformio_rules_transitive_dependencies():
    stardoc_repositories()
    python_register_toolchains(
        name = "python3_10_8",
        # Available versions are listed in @rules_python//python:versions.bzl.
        # We recommend using the same version your team is already standardized on.
        python_version = "3.10.8",
    )
