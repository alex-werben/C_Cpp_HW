cmake_minimum_required(VERSION 3.0.0)
project(main)

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(CodeCoverage)
# setup_target_for_coverage(${PROJECT_NAME}_coverage test coverage)
# target_link_libraries(${PROJECT_TEST_NAME} gcov)

add_executable(${PROJECT_NAME} src/main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

add_subdirectory(string_io)
target_include_directories(${PROJECT_NAME} PUBLIC ${STRING_IO_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${STRING_IO_LIBRARIES})

add_subdirectory(view_composition)
target_include_directories(${PROJECT_NAME} PUBLIC ${VIEW_COMPOSITION_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${VIEW_COMPOSITION_LIBRARIES})

add_subdirectory(add_composition)
target_include_directories(${PROJECT_NAME} PUBLIC ${ADD_COMPOSITION_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ADD_COMPOSITION_LIBRARIES})

add_subdirectory(tests)
