cmake_minimum_required(VERSION 3.0.0)

project(codewander VERSION 0.1.0 LANGUAGES C CXX)

include(cmake_util.cmake)

# create a list of src directory
message(STATUS [INFO] " " ${CMAKE_CURRENT_SOURCE_DIR})

listDir(${CMAKE_CURRENT_SOURCE_DIR}/matlab)

# the full path for cmake.exe
message(STATUS [INFO] " " ${CMAKE_COMMAND})

# generate file
# Define the output file to be generated
set(GENERATED_FILE "${CMAKE_BINARY_DIR}/output.txt")

# Custom command and target
add_custom_command(
    OUTPUT ${GENERATED_FILE}
    COMMAND ${CMAKE_COMMAND} -E echo "This is an auto-generated file." > ${GENERATED_FILE}
    COMMENT "Generating output.txt file"
    VERBATIM
)

# if the target doesnt depend on the file, the add_custom_command will not execute
# this will create a target file called GenerateFile
add_custom_target(
    GenerateFile ALL
    DEPENDS ${GENERATED_FILE}
)

extract_basename_from_m_file("D:/codewander/matlab/SraHalInterface.m")

message(STATUS [info] ${CMAKE_CURRENT_SOURCE_DIR}/include/func-inl.hpp)

add_executable(codewander main.cpp)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set the output directories for all configurations (Debug, Release, etc.)
set_target_properties(codewander 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Executable/$<CONFIG>"
)
