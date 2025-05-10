project(robotGUIQt)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
if(NOT Qt5_FOUND)
    message(FATAL_ERROR "Qt5 not found. Please install Qt5.")
else()
    message(STATUS "Qt5 found: ${Qt5Widgets_INCLUDE_DIRS}")
endif(NOT Qt5_FOUND)

set(CMAKE_AUTOMOC ON)
set(INCLUDE_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME}
    "${INCLUDE_DIR}/robotMainWindowQt.h"
    "${INCLUDE_DIR}/armAssemblyWidgetQt.h"
    robotMainWindowQt.cpp
    armAssemblyWidgetQt.cpp
    main.cpp
)
target_include_directories(${PROJECT_NAME}
    PRIVATE ${INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)
