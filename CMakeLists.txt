cmake_minimum_required(VERSION 3.16)

project(linux_cml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(linux_cml
    src/main.cpp
    src/shell.cpp
    src/commands/changeDirectory.cpp
    src/commands/listDirectory.cpp
    src/commands/printWorkingDirectory.cpp
    src/commands/printHelp.cpp
    src/commands/stateFile.cpp
    src/commands/echo.cpp
    src/commands/mkdir.cpp
)

target_include_directories(linux_cml PRIVATE include)

