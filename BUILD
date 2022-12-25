load("@rules_python//python:pip.bzl", "compile_pip_requirements")

exports_files([
    "requirements.in",
    "requirements_lock.txt",
    "requirements_windows.txt",
])

compile_pip_requirements(
    name = "requirements",
    extra_args = ["--allow-unsafe"],
    requirements_in = "requirements.in",
    requirements_txt = "requirements_lock.txt",
    requirements_windows = "requirements_windows.txt",
)
