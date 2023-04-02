cmake_minimum_required(VERSION 3.24)
project(untitled)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_PREFIX_PATH /home/nk/Documents/cpp/boost_1_81_0/stage/lib/cmake/)

set(Boost_INCLUDE_DIR /home/nk/Documents/cpp/boost_1_81_0/)
include_directories(${Boost_INCLUDE_DIR})
set(Boost_LIBRARIES_DIR /home/nk/Documents/cpp/boost_1_81_0/stage/lib/)

find_package(Boost REQUIRED)
add_executable(untitled main.cpp)
