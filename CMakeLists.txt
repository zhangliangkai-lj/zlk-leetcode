cmake_minimum_required(VERSION 3.19)
project(zlk-leetcode)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("deps/googletest")
function(zlk_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
    add_executable("${test_target_name}" ${test_file})
    target_link_libraries("${test_target_name}" gtest_main)
endfunction(zlk_test)
file(GLOB src_files
        "src/*.cpp"
        )
foreach(leetcode_source ${src_files})
    zlk_test(${leetcode_source})
endforeach(leetcode_source)
