# PlatformIO Bazel rules

[![Build Status](https://travis-ci.com/mum4k/platformio_rules.svg?branch=master)](https://travis-ci.com/mum4k/platformio_rules)

These are Bazel Starlark rules for building and uploading
[Arduino](https://www.arduino.cc/) programs using the
[PlatformIO](http://platformio.org/) build system.

## Disclaimer

This is not an official Google product.

## Prerequisites

These rules don't execute the compiler directly. Instead they copy the
libraries into a directory structure compatible with the PlatformIO build
system and then execute the build via PlatformIO.

In order to do this, the rules execute couple of commands which must already be
present on the system.  The following commands are required:

*   /bin/cp
*   /usr/bin/zip
*   /usr/bin/unzip
*   /usr/local/bin/platformio

The first three ar usually available on any linux system. The platformio
command is added by [installing
PlatformIO](http://docs.platformio.org/en/latest/installation.html).


## Setup - Bzlmod

In order to use these Bazel rules, you must add this repository as a `bazel_dep` and override it with a
`archive_override` in your `MODULE.bazel` file.

### Modify the MODULE file

See [Releases](https://github.com/mum4k/platformio_rules/releases) for the most up to date version to update sha256.
*Below example targets commit `73bca0dbb0942f8c275721269a9c3c6b581e6868`*
```
bazel_dep(name = "platformio_rules", repo_name = "platformio_rules")
archive_override(
    module_name = "platformio_rules",
    sha256 = "f9cdb89e467d01a30787883c8183d022ba0a63f320ae495db3f9966c6aa23328",
    strip_prefix = "platformio_rules-73bca0dbb0942f8c275721269a9c3c6b581e6868",
    url = "https://github.com/mum4k/platformio_rules/archive/73bca0dbb0942f8c275721269a9c3c6b581e6868.tar.gz",
)
```


## Setup - WORKSPACE

In order to use these Bazel rules, you must add this git repository to your
WORKSPACE file and load the platformio rule definition in every BUILD file
where they are needed.

### Modify the WORKSPACE file

See [Releases](https://github.com/mum4k/platformio_rules/releases) for the most up to date version to substitute for `tag`.

```
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
git_repository(
    name = "platformio_rules",
    remote = "http://github.com/mum4k/platformio_rules.git",
    tag = "v0.0.14",
)

load("@platformio_rules//bazel:deps.bzl", "platformio_rules_dependencies")
platformio_rules_dependencies()

load("@platformio_rules//bazel:transitive.bzl", "platformio_rules_transitive_dependencies")
platformio_rules_transitive_dependencies()

load("@platformio_rules//bazel:pip_parse.bzl", "platformio_rules_pip_parse_dependencies")
platformio_rules_pip_parse_dependencies()

load("@platformio_rules//bazel:pip_install.bzl", "platformio_rules_pip_install_dependencies")
platformio_rules_pip_install_dependencies()
```

### Load the rule definitions in the BUILD file

To load the Starlark definitions in your BUILD file add the following at the top
of the BUILD file.

```
load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_library",
    "platformio_project",
)
```

## Defined rules

The following rules are defined for PlatformIO:

*  platformio_library
*  platformio_project

See the [generated documentation](docs/platformio_doc.md).

## Rules documentation

These rules have standard Starlark documentation inside the platformio_docs
directory.

To rebuild the documentation run:

```
bazel build docs:platformio_docs
```

And then copy the created markdown file:

```
cp $(bazel info bazel-bin)/docs/platformio_doc.md docs/
```

## Examples

See the **tests** subdirectory for a working example.

### Define a PlatformIO library

In the BUILD file:

```
platformio_library(
    name = "Convert",
    hdr = "convert.h",
    src = "convert.cc",
)
```

### Define a PlatformIO project

In the BUILD file:

```
platformio_project(
    name = "binary_counter",
    src = "binary_counter.cc",
    board = "megaatmega2560",
    framework = "arduino",
    platform = "atmelavr",
    deps = [
        ":Convert",
    ],
    # If you need to you can pass multiple string key-value pairs directly
    # to PlatformIO. All of these will appear under the environment section in
    # the generated platformio.ini file. That would be "[env:megaatmega2560]" in
    # this example. For the available options see:
    # http://docs.platformio.org/en/stable/projectconf.html
    environment_kwargs = {
        "board_f_cpu": "16000000L",
    }
)
```

### Building with the rules

To build the library defined above you would run:

```
bazel build :Convert
```

To build the project defined above you would run:

```
bazel build :binary_counter
```

### Uploading with the rules

When you run the project, it will upload the compiled firmware to the connected
Arduino device.

```
bazel run :binary_counter
```
