#---------------------------------------------------------------------------
# Subdirectory
#---------------------------------------------------------------------------
add_subdirectory(plot)

#---------------------------------------------------------------------------
# Sources
#---------------------------------------------------------------------------

# Add files
file(GLOB SOURCES "*.cpp")

# Add the library
add_library(ui ${SOURCES})

# Install headers
target_link_libraries(ui PUBLIC plot)
target_link_libraries(ui PRIVATE ${wxWidgets_LIBRARIES} kernel32)
target_include_directories (cacl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/plot)