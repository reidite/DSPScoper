#---------------------------------------------------------------------------
# External Dependencies
#---------------------------------------------------------------------------
find_package(OpenGL REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)

#---------------------------------------------------------------------------
# Sources
#---------------------------------------------------------------------------

# Add files
file(GLOB SOURCES "*.cpp")

# Add the library
add_library(plot ${SOURCES})

# Install headers
target_link_libraries(plot PRIVATE ${wxWidgets_LIBRARIES})
target_include_directories (plot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})