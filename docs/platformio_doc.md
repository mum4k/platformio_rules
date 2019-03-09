<a name="#platformio_library"></a>
## platformio_library

<pre>
platformio_library(<a href="#platformio_library-name">name</a>, <a href="#platformio_library-add_hdrs">add_hdrs</a>, <a href="#platformio_library-add_srcs">add_srcs</a>, <a href="#platformio_library-deps">deps</a>, <a href="#platformio_library-hdr">hdr</a>, <a href="#platformio_library-src">src</a>)
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
#include <My_lib.h>  // This is how PlatformIO sees and includes the library.
#else
#include "actual/path/to/my_lib.h" // This is for native C++.
#endif
```

Outputs a single zip file containing the C++ library in the directory structure
expected by PlatformIO.


### Attributes

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="platformio_library-name">
      <td><code>name</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#name">Name</a>; required
        <p>
          A unique name for this target.
        </p>
      </td>
    </tr>
    <tr id="platformio_library-add_hdrs">
      <td><code>add_hdrs</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#labels">List of labels</a>; optional
        <p>
          A list of labels, additional header files to include in the resulting zip file.
        </p>
      </td>
    </tr>
    <tr id="platformio_library-add_srcs">
      <td><code>add_srcs</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#labels">List of labels</a>; optional
        <p>
          A list of labels, additional source files to include in the resulting zip file.
        </p>
      </td>
    </tr>
    <tr id="platformio_library-deps">
      <td><code>deps</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#labels">List of labels</a>; optional
        <p>
          A list of Bazel targets, other platformio_library targets that this one depends on.
        </p>
      </td>
    </tr>
    <tr id="platformio_library-hdr">
      <td><code>hdr</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#labels">Label</a>; required
        <p>
          A string, the name of the C++ header file. This is mandatory.
        </p>
      </td>
    </tr>
    <tr id="platformio_library-src">
      <td><code>src</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#labels">Label</a>; optional
        <p>
          A string, the name of the C++ source file. This is optional.
        </p>
      </td>
    </tr>
  </tbody>
</table>


<a name="#platformio_project"></a>
## platformio_project

<pre>
platformio_project(<a href="#platformio_project-name">name</a>, <a href="#platformio_project-board">board</a>, <a href="#platformio_project-deps">deps</a>, <a href="#platformio_project-environment_kwargs">environment_kwargs</a>, <a href="#platformio_project-framework">framework</a>, <a href="#platformio_project-platform">platform</a>, <a href="#platformio_project-src">src</a>)
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


### Attributes

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="platformio_project-name">
      <td><code>name</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#name">Name</a>; required
        <p>
          A unique name for this target.
        </p>
      </td>
    </tr>
    <tr id="platformio_project-board">
      <td><code>board</code></td>
      <td>
        String; required
        <p>
          A string, name of the Arduino board to build this project for. You can
find the supported boards in the
[PlatformIO Embedded Boards Explorer](http://platformio.org/boards). This is
mandatory.
        </p>
      </td>
    </tr>
    <tr id="platformio_project-deps">
      <td><code>deps</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#labels">List of labels</a>; optional
        <p>
          A list of Bazel targets, the platformio_library targets that this one
depends on.
        </p>
      </td>
    </tr>
    <tr id="platformio_project-environment_kwargs">
      <td><code>environment_kwargs</code></td>
      <td>
        <a href="https://bazel.build/docs/skylark/lib/dict.html">Dictionary: String -> String</a>; optional
        <p>
          A dictionary of strings to strings, any provided keys and
values will directly appear in the generated platformio.ini file under the
env:board section. Refer to the [Project Configuration File manual](
http://docs.platformio.org/en/latest/projectconf.html) for the available
options.
        </p>
      </td>
    </tr>
    <tr id="platformio_project-framework">
      <td><code>framework</code></td>
      <td>
        String; optional
        <p>
          A string, the name of the
[framework](
http://docs.platformio.org/en/latest/frameworks/index.html#frameworks) for
this project.
        </p>
      </td>
    </tr>
    <tr id="platformio_project-platform">
      <td><code>platform</code></td>
      <td>
        String; optional
        <p>
          A string, the name of the
[development platform](
http://docs.platformio.org/en/latest/platforms/index.html#platforms) for
this project.
        </p>
      </td>
    </tr>
    <tr id="platformio_project-src">
      <td><code>src</code></td>
      <td>
        <a href="https://bazel.build/docs/build-ref.html#labels">Label</a>; required
        <p>
          A string, the name of the C++ source file, the main file for 
the project that contains the Arduino setup() and loop() functions. This is mandatory.
        </p>
      </td>
    </tr>
  </tbody>
</table>


## _emit_build_action

<pre>
_emit_build_action(<a href="#_emit_build_action-ctx">ctx</a>, <a href="#_emit_build_action-project_dir">project_dir</a>)
</pre>

Emits a Bazel action that unzips the libraries and builds the project.

### Parameters

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="_emit_build_action-ctx>
      <td><code>ctx</code></td>
      <td>
        required.
        <p>
          The Skylark context.
        </p>
      </td>
    </tr>
    <tr id="_emit_build_action-project_dir>
      <td><code>project_dir</code></td>
      <td>
        required.
        <p>
          A string, the main directory of the PlatformIO project.
  This is where the zip files will be extracted.
        </p>
      </td>
    </tr>
  </tbody>
</table>


## _emit_executable_action

<pre>
_emit_executable_action(<a href="#_emit_executable_action-ctx">ctx</a>)
</pre>

Emits a Bazel action that produces executable script.

When the script is executed, the compiled firmware gets uploaded to the
Arduino device.


### Parameters

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="_emit_executable_action-ctx>
      <td><code>ctx</code></td>
      <td>
        required.
        <p>
          The Skylark context.
        </p>
      </td>
    </tr>
  </tbody>
</table>


## _emit_ini_file_action

<pre>
_emit_ini_file_action(<a href="#_emit_ini_file_action-ctx">ctx</a>)
</pre>

Emits a Bazel action that generates the PlatformIO configuration file.

### Parameters

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="_emit_ini_file_action-ctx>
      <td><code>ctx</code></td>
      <td>
        required.
        <p>
          The Skylark context.
        </p>
      </td>
    </tr>
  </tbody>
</table>


## _emit_main_file_action

<pre>
_emit_main_file_action(<a href="#_emit_main_file_action-ctx">ctx</a>)
</pre>

Emits a Bazel action that outputs the project main C++ file.

### Parameters

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="_emit_main_file_action-ctx>
      <td><code>ctx</code></td>
      <td>
        required.
        <p>
          The Skylark context.
        </p>
      </td>
    </tr>
  </tbody>
</table>


## _platformio_library_impl

<pre>
_platformio_library_impl(<a href="#_platformio_library_impl-ctx">ctx</a>)
</pre>

Collects all transitive dependencies and emits the zip output.

Outputs a zip file containing the library in the directory structure expected
by PlatformIO.


### Parameters

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="_platformio_library_impl-ctx>
      <td><code>ctx</code></td>
      <td>
        required.
        <p>
          The Skylark context.
        </p>
      </td>
    </tr>
  </tbody>
</table>


## _platformio_project_impl

<pre>
_platformio_project_impl(<a href="#_platformio_project_impl-ctx">ctx</a>)
</pre>

Builds and optionally uploads (when executed) a PlatformIO project.

Outputs the C++ source file containing the Arduino setup() and loop()
functions renamed according to PlatformIO needs, a platformio_ini with the
project configuration file for PlatformIO and the firmware. The firmware_elf
is the compiled version of the Arduino firmware for the specified board and
the firmware_hex is the firmware in the hexadecimal format ready for
uploading.


### Parameters

<table class="params-table">
  <colgroup>
    <col class="col-param" />
    <col class="col-description" />
  </colgroup>
  <tbody>
    <tr id="_platformio_project_impl-ctx>
      <td><code>ctx</code></td>
      <td>
        required.
        <p>
          The Skylark context.
        </p>
      </td>
    </tr>
  </tbody>
</table>


