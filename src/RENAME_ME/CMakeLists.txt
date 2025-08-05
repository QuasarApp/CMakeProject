#
# Copyright (C) 2020-2025 QuasarApp.
# Distributed under the GPLv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.19)

set(CURRENT_PROJECT "${PROJECT_NAME}")
add_definitions(-DRENAME_ME_LIBRARY)

option(QT_QML_GENERATE_QMLLS_INI "Generate QML Language Server Support file" ON)


file(GLOB_RECURSE SOURCE_CPP
    "src/*.cpp"
    "src/*.h"
)

file(GLOB_RECURSE SOURCE_QM
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "languages/*.qm"
)

file(GLOB_RECURSE SOURCE_QML
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "src/RENAME_MEModule/*.qml"
)

file(GLOB_RECURSE SOURCE_ASSETS
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "src/assets/*"
)

set(PUBLIC_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/public")
set(PRIVATE_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/private")

qt_add_library(${CURRENT_PROJECT} ${SOURCE_CPP})

if (RENAME_ME_TESTS)
    target_link_libraries(${CURRENT_PROJECT} PUBLIC ${PROJECT_NAME}testcore )
else()
    target_link_libraries(${CURRENT_PROJECT} PUBLIC Qt${QT_VERSION_MAJOR}::Core )
endif()

qt_add_resources(${CURRENT_PROJECT} "languages"
    PREFIX "/languages"
    FILES ${SOURCE_QM})

qt_add_qml_module(${CURRENT_PROJECT}
    URI RENAME_ME
    VERSION 1.0
    QML_FILES  ${SOURCE_QML}
    RESOURCES ${SOURCE_ASSETS}
    NO_PLUGIN
)

target_include_directories(${CURRENT_PROJECT} PUBLIC ${PUBLIC_INCUDE_DIR})
target_include_directories(${CURRENT_PROJECT} PRIVATE ${PRIVATE_INCUDE_DIR})

set(LANGS ${CMAKE_CURRENT_SOURCE_DIR}/languages/en.ts)


prepareQM(${CURRENT_PROJECT} ${CMAKE_CURRENT_SOURCE_DIR} "${LANGS}")

if (NOT QML_IMPORT_PATH MATCHES "${CMAKE_CURRENT_BINARY_DIR}/..")
    set(QML_IMPORT_PATH ${QML_IMPORT_PATH} "${CMAKE_CURRENT_BINARY_DIR}/.." CACHE STRING "update global variable to access to qml from qt creator." FORCE)
endif()

configure_file_in(${CURRENT_PROJECT} "${CMAKE_CURRENT_SOURCE_DIR}/src/public/RENAME_ME/global.h")
