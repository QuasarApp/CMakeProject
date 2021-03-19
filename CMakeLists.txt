#
# Copyright (C) 2020-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)
project(RENAME_ME)
if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()

set (QT_VERSION_MAJOR OFF)
set (BUILD_SHARED_LIBS ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Test QUIET)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Test QUIET)

include(CMake/ccache.cmake)
include(CMake/QuasarAppCITargets.cmake)

# Add sub directories
add_subdirectory(src)
if (${QT_VERSION_MAJOR})
    add_subdirectory(tests)
endif()


initAll()

addDoc(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)
addDeployFromCustomFile("RENAME_ME" "${CMAKE_CURRENT_SOURCE_DIR}/Deploy/RENAME_ME.json")
