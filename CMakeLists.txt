cmake_minimum_required(VERSION 3.12)

project(boardgames)

set (CMAKE_CXX_STANDARD 11)


FILE(GLOB SRCs src/*.cpp)
FILE(GLOB INCLUDES include/*.h)

include_directories(include/)

add_executable(boardgames main.cpp ${SRCs} ${INCLUDES})

