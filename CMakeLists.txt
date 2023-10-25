# CMakeList.txt : CMake project for DPSScoper, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
#---------------------------------------------------------------------------
# Source
#---------------------------------------------------------------------------
add_subdirectory(src)

#---------------------------------------------------------------------------
# OS
#---------------------------------------------------------------------------
if(WIN32)
set_target_properties(DSPScoper PROPERTIES WIN32_EXECUTABLE TRUE)
endif()