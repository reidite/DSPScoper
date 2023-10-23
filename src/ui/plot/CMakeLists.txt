file(GLOB LIBRARY_SOURCES  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB LIBRARY_HEADERS  "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(plot STATIC  ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_link_libraries(plot PRIVATE ${OPENGL_LIBRARIES}
										${wxWidgets_LIBRARIES})
target_include_directories (plot PUBLIC ${CMAKE_CURRENT_BINARY_DIR})