cmake_minimum_required(VERSION 2.8)
project(UTURN)

#SET(CMAKE_C_COMPILER “/usr/bin/gcc”)
#SET(CMAKE_CXX_COMPILER “/usr/bin/g++”)
add_compile_options(-std=c++11)
message(STATUS "Project directory: ${PROJECT_SOURCE_DIR}")
message(STATUS "please make install library: glog, gtest, gflags")

include_directories(${PROJECT_SOURCE_DIR})
set(SOURCE_FILE_LIST
        point_2d.cpp
        path_point_2d.cpp
        polynomial.cpp
        spline_segment.cpp
        spline_solver.cpp
   )
message(STATUS "files: ${SOURCE_FILE_LIST}")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILE_LIST})
target_link_libraries(${PROJECT_NAME}
        glog gtest gflags pthread)

add_executable(main main.cpp ${SOURCE_FILE_LIST})
target_link_libraries(main
        ${PROJECT_NAME}
        glog gtest gflags pthread)

FILE(GLOB_RECURSE TEST_FILES "unittest/*_test.cpp")
message(STATUS "test files: ${TEST_FILES}")
enable_testing()
foreach(original_test_file ${TEST_FILES})
    get_filename_component(test_file ${original_test_file} NAME)
    get_filename_component(test_name ${original_test_file} NAME_WE)
    set(test_target ${test_name})
    add_executable(${test_target} ${original_test_file})
    target_link_libraries(${test_target}
            ${PROJECT_NAME}
            gtest glog gtest
            pthread
            )
endforeach(original_test_file)
