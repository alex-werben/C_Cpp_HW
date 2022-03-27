cmake_minimum_required(VERSION 3.0.0)
project(main)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if (DEFINED ENV{GITHUB_ACTIONS})
  if (WIN32)
    link_directories("D:/gtest/lib")
    include_directories("D:/gtest/include")

    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
  elseif (APPLE)
    link_directories("/usr/local/lib")
    include_directories("/usr/local/include")
  endif ()
endif ()

include(CodeCoverage)

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
