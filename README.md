# Dotnet Native Interop

Just messing around with calling native libraries from C#,
in particular SDL.

## Dependencies

* .NET Runtime (tested with .NET 6)
* SDL2
* SDL2_ttf
* SDL2_image
* CMake (_build_)
* C++ Compiler (_build_)
  * On Windows, Visual Studio (possibly 2022) and VCPKG
  * On *nix, GCC/Clang (with C++20 support) and Ninja

## Building

You will need to copy the .dll/.so file in the same folder as the built .NET binary.

### Linux

```
cmake -S native -B build -G Ninja
cmake --build build

dotnet build
```

### Windows

```
vcpkg install sdl2 sdl2-image sdl2-ttf sdl2-image[libjpeg-turbo] --triplet=x64-windows --recurse

cmake -S native -B build -DCMAKE_TOOLCHAIN_FILE=<vcpkg installation path>/scripts/buildsystems/vcpkg.cmake
cmake --build build

dotnet build
```

### Rebuilding and running

Rebuilding the native part:
```
cmake --build build
```
You might need to copy the dll back to the main folder in Windows,
on Linux there's a symlink.

Run:
```
dotnet run
```

