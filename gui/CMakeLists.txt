cmake_minimum_required(VERSION 3.15)
project(sms_gui LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

add_executable(sms_gui
  src/main.cpp
  src/MainWindow.cpp
  src/MainWindow.h
  src/MainWindow.ui
)

target_link_libraries(sms_gui PRIVATE Qt5::Widgets Qt5::Network)
