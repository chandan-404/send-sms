cmake_minimum_required(VERSION 3.15)
project(sms_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)
include(FetchContent)

FetchContent_Declare(
  crow
  GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
  GIT_TAG master
)
FetchContent_MakeAvailable(crow)

add_executable(sms_api src/main.cpp)
target_include_directories(sms_api PRIVATE ${crow_SOURCE_DIR}/include ${CURL_INCLUDE_DIRS})
target_link_libraries(sms_api PRIVATE ${CURL_LIBRARIES})
target_compile_options(sms_api PRIVATE -Wall -Wextra)
