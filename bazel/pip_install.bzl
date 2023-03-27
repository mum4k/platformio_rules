load("@py_deps//:requirements.bzl", "install_deps")

# Finally, now that pip_parse() has been executed, install the pip dependencies
def platformio_rules_pip_install_dependencies():
    # Install all pip dependencies
    install_deps()