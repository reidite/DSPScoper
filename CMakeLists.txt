cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "DPSScoper")
project($(PROJECT_NAME) LANGUAGES CXX)
#---------------------------------------------------------------------------
# OS
#---------------------------------------------------------------------------
if(WIN32)
# Windows-specific commands or settings
    set(CMAKE_PREFIX_PATH "F:/Community/vcpkg/installed/x64-windows/share")
    set(CMAKE_TOOLCHAIN_FILE "F:/Community/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

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


#---------------------------------------------------------------------------
# Subdirectory
#---------------------------------------------------------------------------
add_subdirectory(src)