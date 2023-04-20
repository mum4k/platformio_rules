<!-- Generated with Stardoc: http://skydoc.bazel.build -->

PlatformIO Rules.

These are Bazel Starlark rules for building and uploading
[Arduino](https://www.arduino.cc/) programs using the
[PlatformIO](http://platformio.org/) build system.


<a id="platformio_fs"></a>

## platformio_fs

<pre>
platformio_fs(<a href="#platformio_fs-name">name</a>, <a href="#platformio_fs-board">board</a>, <a href="#platformio_fs-data">data</a>, <a href="#platformio_fs-framework">framework</a>, <a href="#platformio_fs-platform">platform</a>, <a href="#platformio_fs-port">port</a>, <a href="#platformio_fs-programmer">programmer</a>)
</pre>


Defines data that will be uploaded to the microcontroller's filesystem using
PlatformIO.

Creates, configures and runs a PlatformIO project. This is equivalent to running:

```
platformio run
```

This rule is executable and when executed, it will upload the provided data to
the connected Arduino device. This is equivalent to running:

```
platformio run -t uploadfs
```


**ATTRIBUTES**


| Name  | Description | Type | Mandatory | Default |
| :------------- | :------------- | :------------- | :------------- | :------------- |
| <a id="platformio_fs-name"></a>name |  A unique name for this target.   | <a href="https://bazel.build/concepts/labels#target-names">Name</a> | required |  |
| <a id="platformio_fs-board"></a>board |  A string, name of the Arduino board to build this project for. You can find the supported boards in the [PlatformIO Embedded Boards Explorer](http://platformio.org/boards). This is mandatory.   | String | required |  |
| <a id="platformio_fs-data"></a>data |  Filegroup containing files to upload to the device's FS memory.   | <a href="https://bazel.build/concepts/labels">Label</a> | required |  |
| <a id="platformio_fs-framework"></a>framework |  A string, the name of the [framework]( http://docs.platformio.org/en/latest/frameworks/index.html#frameworks) for this project.   | String | optional | <code>"arduino"</code> |
| <a id="platformio_fs-platform"></a>platform |  A string, the name of the [development platform]( http://docs.platformio.org/en/latest/platforms/index.html#platforms) for this project.   | String | optional | <code>"atmelavr"</code> |
| <a id="platformio_fs-port"></a>port |  Port where your microcontroller is connected. This field is mandatory if you are using arduino_as_isp as your programmer.   | String | optional | <code>""</code> |
| <a id="platformio_fs-programmer"></a>programmer |  Type of programmer to use: - direct: Use the USB connection in the microcontroller deveopment board to program it - arduino_as_isp: Use an arduino programmed with the Arduino as ISP code to in-circuit program another microcontroller (see https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoISP for details). - usbtinyisp: Use an USBTinyISP programmer, like https://www.amazon.com/gp/product/B09DG384MK   | String | optional | <code>"direct"</code> |


<a id="platformio_library"></a>

## platformio_library

<pre>
platformio_library(<a href="#platformio_library-name">name</a>, <a href="#platformio_library-add_hdrs">add_hdrs</a>, <a href="#platformio_library-add_srcs">add_srcs</a>, <a href="#platformio_library-deps">deps</a>, <a href="#platformio_library-hdr">hdr</a>, <a href="#platformio_library-lib_deps">lib_deps</a>, <a href="#platformio_library-src">src</a>)
</pre>


Defines a C++ library that can be imported in an PlatformIO project.

The PlatformIO build system requires a set project directory structure. All
libraries must be under the lib directory. Furthermore all libraries can only
consist of a single header and a single source file. The name of the library
must match the names of the header file, the source file and the subdirectory
under the lib directory.

If you have a C++ library with files my_lib.h and my_lib.cc, using this rule:

```
platformio_library(
    # Start with an uppercase letter to keep the Arduino naming style.
    name = "My_lib",
    hdr = "my_lib.h",
    src = "my_lib.cc",
)
```

Will generate a zip file containing the following structure:

```
lib/
  My_lib/
    My_lib.h
    My_lib.cpp
```

In the Arduino code, you should include this as follows. The PLATFORMIO_BUILD
will be set when the library is built by the PlatformIO build system.

```
#ifdef PLATFORMIO_BUILD
#include &lt;My_lib.h&gt;  // This is how PlatformIO sees and includes the library.
#else
#include "actual/path/to/my_lib.h" // This is for native C++.
#endif
```

Outputs a single zip file containing the C++ library in the directory structure
expected by PlatformIO.


**ATTRIBUTES**


| Name  | Description | Type | Mandatory | Default |
| :------------- | :------------- | :------------- | :------------- | :------------- |
| <a id="platformio_library-name"></a>name |  A unique name for this target.   | <a href="https://bazel.build/concepts/labels#target-names">Name</a> | required |  |
| <a id="platformio_library-add_hdrs"></a>add_hdrs |  A list of labels, additional header files to include in the resulting zip file.   | <a href="https://bazel.build/concepts/labels">List of labels</a> | optional | <code>[]</code> |
| <a id="platformio_library-add_srcs"></a>add_srcs |  A list of labels, additional source files to include in the resulting zip file.   | <a href="https://bazel.build/concepts/labels">List of labels</a> | optional | <code>[]</code> |
| <a id="platformio_library-deps"></a>deps |  A list of Bazel targets, other platformio_library targets that this one depends on.   | <a href="https://bazel.build/concepts/labels">List of labels</a> | optional | <code>[]</code> |
| <a id="platformio_library-hdr"></a>hdr |  A string, the name of the C++ header file. This is mandatory.   | <a href="https://bazel.build/concepts/labels">Label</a> | required |  |
| <a id="platformio_library-lib_deps"></a>lib_deps |  A list of external (PlatformIO) libraries that this library depends on. These libraries will be added to any platformio_project() rules that directly or indirectly link this library.   | List of strings | optional | <code>[]</code> |
| <a id="platformio_library-src"></a>src |  A string, the name of the C++ source file. This is optional.   | <a href="https://bazel.build/concepts/labels">Label</a> | optional | <code>None</code> |


<a id="platformio_project"></a>

## platformio_project

<pre>
platformio_project(<a href="#platformio_project-name">name</a>, <a href="#platformio_project-board">board</a>, <a href="#platformio_project-build_flags">build_flags</a>, <a href="#platformio_project-deps">deps</a>, <a href="#platformio_project-environment_kwargs">environment_kwargs</a>, <a href="#platformio_project-framework">framework</a>, <a href="#platformio_project-lib_deps">lib_deps</a>,
                   <a href="#platformio_project-lib_ldf_mode">lib_ldf_mode</a>, <a href="#platformio_project-platform">platform</a>, <a href="#platformio_project-port">port</a>, <a href="#platformio_project-programmer">programmer</a>, <a href="#platformio_project-src">src</a>)
</pre>


Defines a project that will be built and uploaded using PlatformIO.

Creates, configures and runs a PlatformIO project. This is equivalent to running:

```
platformio run
```

This rule is executable and when executed, it will upload the compiled firmware
to the connected Arduino device. This is equivalent to running:
platformio run -t upload


Outputs the C++ source file containing the Arduino setup() and loop()
functions renamed according to PlatformIO needs, a platformio_ini with the
project configuration file for PlatformIO and the firmware. The firmware_elf
is the compiled version of the Arduino firmware for the specified board and
the firmware_hex is the firmware in the hexadecimal format ready for
uploading.


**ATTRIBUTES**


| Name  | Description | Type | Mandatory | Default |
| :------------- | :------------- | :------------- | :------------- | :------------- |
| <a id="platformio_project-name"></a>name |  A unique name for this target.   | <a href="https://bazel.build/concepts/labels#target-names">Name</a> | required |  |
| <a id="platformio_project-board"></a>board |  A string, name of the Arduino board to build this project for. You can find the supported boards in the [PlatformIO Embedded Boards Explorer](http://platformio.org/boards). This is mandatory.   | String | required |  |
| <a id="platformio_project-build_flags"></a>build_flags |  A list of strings, any provided strings will directly appear in the generated platformio.ini file in the build_flags option for the selected env:board section. Refer to the [Project Configuration File manual]( http://docs.platformio.org/en/latest/projectconf.html) for the available options.   | List of strings | optional | <code>[]</code> |
| <a id="platformio_project-deps"></a>deps |  A list of Bazel targets, the platformio_library targets that this one depends on.   | <a href="https://bazel.build/concepts/labels">List of labels</a> | optional | <code>[]</code> |
| <a id="platformio_project-environment_kwargs"></a>environment_kwargs |  A dictionary of strings to strings, any provided keys and values will directly appear in the generated platformio.ini file under the env:board section. Refer to the [Project Configuration File manual]( http://docs.platformio.org/en/latest/projectconf.html) for the available options.   | <a href="https://bazel.build/rules/lib/dict">Dictionary: String -> String</a> | optional | <code>{}</code> |
| <a id="platformio_project-framework"></a>framework |  A string, the name of the [framework]( http://docs.platformio.org/en/latest/frameworks/index.html#frameworks) for this project.   | String | optional | <code>"arduino"</code> |
| <a id="platformio_project-lib_deps"></a>lib_deps |  A list of external (PlatformIO) libraries that this project depends on.   | List of strings | optional | <code>[]</code> |
| <a id="platformio_project-lib_ldf_mode"></a>lib_ldf_mode |  Library dependency finder for PlatformIO (https://docs.platformio.org/en/stable/librarymanager/ldf.html).   | String | optional | <code>"deep+"</code> |
| <a id="platformio_project-platform"></a>platform |  A string, the name of the [development platform]( http://docs.platformio.org/en/latest/platforms/index.html#platforms) for this project.   | String | optional | <code>"atmelavr"</code> |
| <a id="platformio_project-port"></a>port |  Port where your microcontroller is connected. This field is mandatory if you are using arduino_as_isp as your programmer.   | String | optional | <code>""</code> |
| <a id="platformio_project-programmer"></a>programmer |  Type of programmer to use: - direct: Use the USB connection in the microcontroller deveopment board to program it - arduino_as_isp: Use an arduino programmed with the Arduino as ISP code to in-circuit program another microcontroller (see https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoISP for details). - usbtinyisp: Use an USBTinyISP programmer, like https://www.amazon.com/gp/product/B09DG384MK   | String | optional | <code>"direct"</code> |
| <a id="platformio_project-src"></a>src |  A string, the name of the C++ source file, the main file for  the project that contains the Arduino setup() and loop() functions. This is mandatory.   | <a href="https://bazel.build/concepts/labels">Label</a> | required |  |


<a id="PlatformIOLibraryInfo"></a>

## PlatformIOLibraryInfo

<pre>
PlatformIOLibraryInfo(<a href="#PlatformIOLibraryInfo-default_runfiles">default_runfiles</a>, <a href="#PlatformIOLibraryInfo-transitive_libdeps">transitive_libdeps</a>)
</pre>

Information needed to define a PlatformIO library.

**FIELDS**


| Name  | Description |
| :------------- | :------------- |
| <a id="PlatformIOLibraryInfo-default_runfiles"></a>default_runfiles |  Files needed to execute anything depending on this library.    |
| <a id="PlatformIOLibraryInfo-transitive_libdeps"></a>transitive_libdeps |  External platformIO libraries needed by this library.    |


