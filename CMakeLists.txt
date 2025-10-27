cmake_minimum_required(VERSION 3.16)
project(week_9_homework_KGhim7)
set(CMAKE_CXX_STANDARD 14)

add_executable(week_9_homework_KGhim7
        main.cpp
        Queue.hpp
        QueueFactory.hpp
        ArrayQueue.hpp
        ArrayQueue.tpp
        LinkedQueue.hpp
        LinkedQueue.tpp
)

target_include_directories(week_9_homework_KGhim7 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})