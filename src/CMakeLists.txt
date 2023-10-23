project ("DPSScoper")

add_executable (DSPScoper "main.cpp")
#---------------------------------------------------------------------------
# Source
#---------------------------------------------------------------------------
find_package(OpenGL REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)

add_subdirectory(calc)
add_subdirectory(ui)

target_include_directories(DSPScoper PRIVATE ${wxWidgets_INCLUDE_DIRS}
												${CMAKE_CURRENT_BINARY_DIR}/ui
												${CMAKE_CURRENT_BINARY_DIR}/ui/plot
												${CMAKE_CURRENT_BINARY_DIR}/calc)
target_link_libraries(DSPScoper PRIVATE ${OPENGL_LIBRARIES}
										${wxWidgets_LIBRARIES}
										calc
										ui)


# Copy the res folder to the binary directory
set(RESOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res")
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})