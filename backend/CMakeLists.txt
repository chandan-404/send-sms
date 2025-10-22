# backend program

cmake_minimum_required(VERSION 3.31.6)
project(sms_backend LANGUAGE CXX)

find_package(CURL REQUIRED_FILES)

add_executable(sms_backend src/main.cpp)
target_include_directories(sms_backend PRIVATE ${CURL_INCLUDE_DIRS})
target_compile_options(sms_backend PRIVATE -Wall -Wextra -Wpedantic)
