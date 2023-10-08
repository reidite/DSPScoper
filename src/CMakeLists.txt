
#---------------------------------------------------------------------------
# External Dependencies
#---------------------------------------------------------------------------
find_package(OpenGL REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)

#---------------------------------------------------------------------------
# Linkage
#---------------------------------------------------------------------------
add_executable(DSPScoper main.cpp)


# Dependencies Including
target_include_directories(DSPScoper PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(DSPScoper PRIVATE ${wxWidgets_LIBRARIES})


# Subdirectories Including
add_subdirectory(calc)
add_subdirectory(ui)

target_include_directories (DSPScoper PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR} 
                                                ${CMAKE_CURRENT_SOURCE_DIR}/calc
                                                ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# target_link_libraries (DSPScoper LINK_PUBLIC 
#                                         calc
#                                         ui
# )

set_target_properties(DSPScoper PROPERTIES
                        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}"
                        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}"
                        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}"
)