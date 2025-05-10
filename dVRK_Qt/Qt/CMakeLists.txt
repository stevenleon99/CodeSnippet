project(roboGUI)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
if(NOT Qt5_FOUND)
    message(FATAL_ERROR "Qt5 not found. Please install Qt5.")
else()
    message(STATUS "Qt5 has been found")
endif(NOT Qt5_FOUND)

set(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME} button.cpp)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)


add_executable("${PROJECT_NAME}Qt" robotGUIQt.cpp)
target_include_directories("${PROJECT_NAME}Qt" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries("${PROJECT_NAME}Qt" Qt5::Widgets Qt5::Core Qt5::Gui)


