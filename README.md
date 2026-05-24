# Low latency gstreamer audio stack

## Build

```bash
cmake -B build
cmake --build build
```

| Option | Default | Description |
|--------|---------|-------------|
| `CMAKE_BUILD_TYPE` | `Release` | `Debug`, `Release`, or `RelWithDebInfo` |
| `AUDIO_STACK_BUILD_SHARED` | `OFF` | `ON` for shared library, `OFF` for static |
| `AUDIO_STACK_BUILD_TESTS` | `OFF` | Build and register CTest targets |

Examples:

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DAUDIO_STACK_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build
./build/examples/example_alsa_capture [device_name]
```

New `.cpp` / `.hpp` files under `src/` and `include/` are picked up automatically on the next CMake configure.

## Dependencies

```bash
sudo apt-get update && sudo apt-get install -y \
    libgstreamer1.0-dev \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav \
    gstreamer1.0-tools
```