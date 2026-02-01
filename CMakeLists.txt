cmake_minimum_required(VERSION 3.16)

project(linux_cml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(linux_cml
    src/main.cpp
)
