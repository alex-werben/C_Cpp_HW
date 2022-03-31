cmake_minimum_required(VERSION 3.0.0)
project(main)

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

add_subdirectory(consistent_algorithm)
target_include_directories(${PROJECT_NAME} PUBLIC ${CONSISTENT_ALGORITHM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CONSISTENT_ALGORITHM_LIBRARIES})

add_subdirectory(interface)
target_include_directories(${PROJECT_NAME} PUBLIC ${INTERFACE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${INTERFACE_LIBRARIES})



add_subdirectory(tests)
