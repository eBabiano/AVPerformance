cmake_minimum_required(VERSION 2.8)
project(TegraK1_Performance)

find_package(Boost REQUIRED COMPONENTS system filesystem thread chrono)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenGL)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_FLAGS "-g -Wall -fPIC -std=c++11")
#SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)


#SET_PROPERTY(TARGET flycapture2 PROPERTY IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/flycpature2/lib/*")
find_library(FLYCAPTURE2LIB NAMES libflycapture2.so flycapture)

message (STATUS -----> ${FLYCAPTURE2LIB})
IF(FLYCAPTURE2LIB)
message(STATUS Flycapture2 finded!!!!!!!!)
ELSE(FLYCAPTURE2LIB)
message(STATUS Flycapture2 not found...)
ENDIF(FLYCAPTURE2LIB)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE sources "src/application/*.cpp"
                          "src/application/*.hpp")

file(GLOB_RECURSE views "src/view/*.cpp"
                        "src/view/*.hpp")
file(GLOB_RECURSE widgets_headers "src/view/gui/*.h*")
file(GLOB_RECURSE widgets_forms "src/view/gui/*.ui")

file(GLOB util "src/util/*.hpp"
               "src/util/*.cpp")

file(GLOB_RECURSE controller "src/controller/*.hpp"
                             "src/controller/*.cpp")

file(GLOB_RECURSE model "src/model/*.hpp"
                        "src/model/*.cpp")

file(GLOB_RECURSE flycapture2_include "lib/flycapture2/include/*.h")

qt5_wrap_ui(FORM_H ${widgets_forms})
qt5_wrap_cpp(HEADER_H ${widgets_headers})

ADD_LIBRARY(TegraK1_Performance_CONFIG ${FORM_H} ${HEADER_H})
QT5_USE_MODULES(TegraK1_Performance_CONFIG Widgets PrintSupport)

add_library(flycapture2 SHARED IMPORTED)

set(MAIN_SRC ${sources}
             ${views}
             ${widgets_headers}
             ${widgets_forms}
             ${util}
             ${controller}
             ${model}
             ${flycapture2_include})

#################### PROJECT DEPENDENCIES #######################################

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(${Qt5OpenGL_INCLUDE_DIRS})
include_directories(${Qt5PrintSupport_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})

#include_directories(${FLYCAPTURE2_LIB})

add_executable(TegraK1_Performance ${MAIN_SRC}
                                ${FORM_H}
                                ${HEADER_H})

QT5_USE_MODULES(TegraK1_Performance Core Gui Widgets OpenGL PrintSupport)

target_link_libraries(TegraK1_Performance  ${Qt5Core}
                                           ${Qt5Widgets}
                                           ${Qt5Gui}
                                           ${Qt5OpenGL}
                                           ${Boost_LIBRARIES}
                                           ${OpenCV_LIBS}
                                           ${Qt5PrintSupport}
                                           ${FLYCAPTURE2LIB})


