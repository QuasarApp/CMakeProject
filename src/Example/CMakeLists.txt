#
# Copyright (C) 2021-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)

set(CURRENT_PROJECT "${PROJECT_NAME}Eaxample")


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

file(GLOB SOURCE_CPP
    "*.cpp" "*.qrc"
    "src/*.cpp" "src/*.qrc"
    "src/Private/*.cpp" "src/Private/*.qrc"
)

set(PUBLIC_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PUBLIC_INCUDE_DIR ${PUBLIC_INCUDE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(PRIVATE_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/Private")

add_executable(${CURRENT_PROJECT} ${SOURCE_CPP})

if (${QT_VERSION_MAJOR})
    target_link_libraries(${CURRENT_PROJECT} PUBLIC Qt::Core)
endif()
target_link_libraries(${CURRENT_PROJECT} PUBLIC ${PROJECT_NAME})

target_include_directories(${CURRENT_PROJECT} PUBLIC ${PUBLIC_INCUDE_DIR})
target_include_directories(${CURRENT_PROJECT} PRIVATE ${PRIVATE_INCUDE_DIR})


