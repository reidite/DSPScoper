cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

set(PROJECT_NAME "DPSScoper")
project($(PROJECT_NAME) LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#---------------------------------------------------------------------------
# Environment
#---------------------------------------------------------------------------
if(POLICY CMP0042)
    set(OpenGL_GL_PREFERENCE "GLVND")
    cmake_policy(SET CMP0042 NEW)
endif()
if(POLICY CMP0074)
    set(OpenGL_GL_PREFERENCE "LEGACY")
endif()

set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})

#---------------------------------------------------------------------------
# Build Type
#---------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release")
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

#---------------------------------------------------------------------------
# Debug
#---------------------------------------------------------------------------
set(USE_CCACHE ON CACHE BOOL "Use ccache to accelerate build")
find_program(CCACHE_EXE ccache)
if(USE_CCACHE AND CCACHE_EXE AND NOT MSVC)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_EXE}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_EXE}")
    message(STATUS "ccache: Enabled")
else()
    set(USE_CCACHE OFF)
    message(STATUS "ccache: Disabled")
endif()

set(USE_SANITIZER OFF CACHE BOOL "Enable Address/Memory sanitizer (set env as ASAN_OPTIONS=detect_leaks=1)")
if(USE_SANITIZER AND NOT MSVC)
    add_compile_options(-fno-omit-frame-pointer -fsanitize=address)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
    set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
    message(STATUS "Address/Memory sanitizer: ENABLED")
else()
    message(STATUS "Address/Memory sanitizer: DISABLED")
endif()

#---------------------------------------------------------------------------
# Compiler
#---------------------------------------------------------------------------
if(MSVC)
    # C4251: DLL export, C4244: floating->integer, C4305: double->float, C4267: size_t->any, C4127: constant condition
    add_compile_options(/W4 $<$<CONFIG:Debug>:/MTd>;$<$<CONFIG:Release>:/MT> /source-charset:utf-8 /execution-charset:utf-8 /wd4251 /wd4244 /wd4305 /wd4267 /wd4127)
    add_compile_options("$<$<CONFIG:Debug>:/Zo>;$<$<CONFIG:Release>:/O2>;$<$<CONFIG:None>:/O2>")
else()
    add_compile_options(-Wall -Wextra)
    add_compile_options(
        "$<$<CONFIG:Debug>:-Og>"
        "$<$<CONFIG:Release>:-O3>"
        "$<$<CONFIG:None>:-O3>")
endif()

set(BUILD_WITH_MARCH_NATIVE OFF CACHE BOOL "Enable architecture-aware optimization")
if(BUILD_WITH_MARCH_NATIVE AND NOT MSVC)
    add_compile_options(-mtune=native -march=native)
    message(STATUS "Architecture-aware optimization: ENABLED")
else()
    message(STATUS "Architecture-aware optimization: DISABLED")
endif()

#---------------------------------------------------------------------------
# Subdirectory
#---------------------------------------------------------------------------
add_subdirectory(src)