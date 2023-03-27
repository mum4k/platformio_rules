load("@python3_10_8//:defs.bzl", "interpreter")
load("@rules_python//python:pip.bzl", "pip_parse")

def platformio_rules_pip_parse_dependencies():
    pip_parse(
        name = "py_deps",
        python_interpreter_target = interpreter,
        requirements_lock = "@platformio_rules//:requirements_lock.txt",
    )