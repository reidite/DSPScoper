cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(PROJECT_NAME "DPSScoper")
project($(PROJECT_NAME) LANGUAGES CXX)

#---------------------------------------------------------------------------
# OS
#---------------------------------------------------------------------------
if(WIN32)
# Windows-specific commands or settings
    set(CMAKE_PREFIX_PATH "F:/Community/vcpkg/installed/x64-windows/share")
    set(CMAKE_TOOLCHAIN_FILE "F:/Community/vcpkg/scripts/buildsystems/vcpkg.cmake")
    
    # file(TO_CMAKE_PATH $ENV{W64DEVKIT_PATH} DW64DEVKIT_PATH)
    # set(TOOLCHAIN_PREFIX "${DW64DEVKIT_PATH}/x86_64-w64-mingw32" )

    # set(CMAKE_ADDR2LINE ${TOOLCHAIN_PREFIX}-addr2line)
    # set(CMAKE_AR ${TOOLCHAIN_PREFIX}-ar)
    # set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++)
    # set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc)
    # set(CMAKE_CXX_COMPILER_AR ${TOOLCHAIN_PREFIX}-gcc-ar)
    # set(CMAKE_CXX_COMPILER_RANLIB ${TOOLCHAIN_PREFIX}-gcc-ranlib)
    # set(CMAKE_DLLTOOL ${TOOLCHAIN_PREFIX}-dlltool)
    # set(CMAKE_LINKER ${TOOLCHAIN_PREFIX}-ld)
    # set(CMAKE_NM ${TOOLCHAIN_PREFIX}-nm)
    # set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}-objcopy)
    # set(CMAKE_OBJDUMP ${TOOLCHAIN_PREFIX}-objdump)
    # set(CMAKE_RANLIB ${TOOLCHAIN_PREFIX}-ranlib)
    # set(CMAKE_RC_COMPILER ${TOOLCHAIN_PREFIX}-windres)
    # set(CMAKE_READELF ${TOOLCHAIN_PREFIX}-readelf)
    # set(CMAKE_STRIP ${TOOLCHAIN_PREFIX}-strip)
endif()
# Linux-specific commands or settings
if(LINUX)

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