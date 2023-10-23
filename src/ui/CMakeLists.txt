add_subdirectory(plot)

file(GLOB LIBRARY_SOURCES  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB LIBRARY_HEADERS  "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(ui STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

target_link_libraries(ui PRIVATE ${OPENGL_LIBRARIES}
										${wxWidgets_LIBRARIES}
										plot
										calc)

target_include_directories (ui PUBLIC ${CMAKE_CURRENT_BINARY_DIR})