# CMakeList.txt : CMake project for DPSScoper, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


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