cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -Wall")

project(sdb)

set(SOURCES
    SimpleDatabase.cpp 
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})