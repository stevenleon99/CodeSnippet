cmake_minimum_required(VERSION 3.0.0)

project(sharememory VERSION 0.1.0 LANGUAGES C CXX)

# create a list of src directory
message(STATUS [INFO] " " "this is to test shared memory input output functions")


add_executable(process1 process1.cpp)
add_executable(process2 process2.cpp)

# Include directories for both executables
target_include_directories(process1
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_include_directories(process2
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set the output directories for all configurations (Debug, Release, etc.)
set_target_properties(process1 process2
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Executable/$<CONFIG>"
)
