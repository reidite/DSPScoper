#---------------------------------------------------------------------------
# Subdirectory
#---------------------------------------------------------------------------
add_subdirectory(filters)

#---------------------------------------------------------------------------
# Sources
#---------------------------------------------------------------------------

# Add files
file(GLOB SOURCES "*.cpp")

# Add the library
add_library(cacl ${SOURCES})

# Install headers

target_include_directories (cacl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})