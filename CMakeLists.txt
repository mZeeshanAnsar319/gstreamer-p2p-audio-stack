cmake_minimum_required(VERSION 3.16)

project(gstreamer-p2p-audio-stack
    VERSION 0.1.0
    DESCRIPTION "Low latency GStreamer P2P audio stack"
    LANGUAGES CXX
)

# --- Build configuration (Debug / Release / RelWithDebInfo) ---

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Build type: Debug, Release, or RelWithDebInfo"
        FORCE
    )
endif()

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    Debug
    Release
    RelWithDebInfo
)

# --- User options ---

option(AUDIO_STACK_BUILD_TESTS
    "Build unit/integration tests"
    OFF
)

option(AUDIO_STACK_BUILD_SHARED
    "Build shared library (OFF = static library)"
    OFF
)

# --- Toolchain defaults ---

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(AUDIO_STACK_BUILD_SHARED)
    set(AUDIO_STACK_LIB_TYPE SHARED)
else()
    set(AUDIO_STACK_LIB_TYPE STATIC)
endif()

# --- External dependencies (shared by library, examples, tests) ---

find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED IMPORTED_TARGET gstreamer-1.0)

# --- Library (include + src), examples, optional tests ---

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(examples)

if(AUDIO_STACK_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
