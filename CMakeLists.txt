#
# Copyright (C) 2020-2020 QuasarApp.
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

find_package(Qt5 COMPONENTS Core Test QUIET)

include(CMake/ccache.cmake)
include(CMake/QuasarAppCITargets.cmake)

# Add sub directories
add_subdirectory(src)
if (EXISTS ${Qt5_DIR})
    add_subdirectory(tests)
endif()



initAll()

addDoc(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)
