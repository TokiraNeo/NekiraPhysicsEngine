<h1 style="text-align: center">Contribute to NekiraPhysicsEngine</h1>

## Thanks

Thank you for thinking about donating to NekiraPhysicsEngine!
I started this project to learn game physics, and there might be some mistakes in the code.
I really appreciate your contributions!

## Prerequisites

- C++20 compatible compiler (GCC 13+, Clang 15+, MSVC 2022)
- CMake 3.20 or later
- Git
- Qt 6.8 or later
- Vcpkg (for managing dependencies)

## Setting up the Development Environment

### 1. Clone the repository:

```bash
git clone https://github.com/TokiraNeo/NekiraPhysicsEngine.git
cd NekiraPhysicsEngine
```

### 2. Modify the CMakeUserPresets.json

Create a file named `CMakeUserPresets.json` in the root directory with the following content:

```json
{
  "version": 6,
  "configurePresets": [
    {
      "name": "MyPreset",
      "inherits": "vcpkg",
      "hidden": false,
      "generator": "Ninja",
      "environment": {
        "VCPKG_ROOT": "<path_to_vcpkg>"
      },
      "cacheVariables": {
        "QT_CMAKE_PATH": "<path_to_qt_package>/lib/cmake"
      }
    }
  ]
}
```

This Preset should inherit from the "vcpkg" preset.
Modify it to match your environment if necessary. Extremely the `QT_CMAKE_PATH`, `VCPKG_ROOT` variables.

### 3. Build

Use above preset to configure and build the project:

```bash
cmake -B build -S . --preset MyPreset
cmake --build build --preset MyPreset
```

## Code Style

This project uses clang-format for consistent code formatting.