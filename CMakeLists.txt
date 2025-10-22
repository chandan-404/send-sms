
cmake_minimum_required(VERSION 3.31.6)
project(SMS_APP LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 21)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subprojects
add_subdirectory(backend)
add_subdirectory(api)
add_subdirectory(gui)