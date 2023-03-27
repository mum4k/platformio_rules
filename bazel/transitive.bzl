load("@io_bazel_stardoc//:setup.bzl", "stardoc_repositories")
load("@rules_python//python:repositories.bzl", "python_register_toolchains")

# Load the first level of dependencies that are based on the ones imported in
# platformio_rules_dependencies(), as these imports depend on load() commands
# that come from those imports
def platformio_rules_transitive_dependencies():
    # Import all the dependencies for Stardoc, so we can write documentation for
    # our Starlark rules
    stardoc_repositories()

    # Select the Python toolchain that will be used for template rendering. This
    # is required for pip_parse() to be executed
    python_register_toolchains(
        name = "python3_10_8",
        # Available versions are listed in @rules_python//python:versions.bzl.
        # We recommend using the same version your team is already standardized on.
        python_version = "3.10.8",
    )
