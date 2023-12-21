cmake_minimum_required(VERSION 3.14)

project(TextFileProcessor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(TextFileProcessor
  main.cpp
  TextFileManager.h TextFileManager.cpp
  processorManager.h processorManager.cpp
  ProcessClass/Process.h ProcessClass/Process.cpp
  ProcessClass/DoUpperCase.h ProcessClass/DoUpperCase.cpp
  ProcessClass/DoLowerCase.h ProcessClass/DoLowerCase.cpp
  ProcessClass/SetFirstCharUp.h ProcessClass/SetFirstCharUp.cpp
  utils/ProcessOrder.h
  StringProcessFactory.h StringProcessFactory.cpp
  utils/StrStruct.h
  ProcessClass/BasicStringProcess.h
)
target_link_libraries(TextFileProcessor Qt${QT_VERSION_MAJOR}::Core)
