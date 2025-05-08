project(concurrency)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS thread chrono)

add_executable(threaddemo thread_demo.cpp)

add_executable(boostdemo boost_demo.cpp)
target_link_libraries(boostdemo PRIVATE Boost::thread)

add_executable(workerconsumer worker_consumer.cpp)
target_link_libraries(workerconsumer PRIVATE Boost::thread Boost::chrono)

add_executable(interruptdemo interrupt_demo.cpp)
target_link_libraries(interruptdemo PRIVATE Boost::thread Boost::chrono)