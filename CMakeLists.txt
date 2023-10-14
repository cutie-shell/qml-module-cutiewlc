cmake_minimum_required(VERSION 3.16)
project(qmlcutiewlcplugin VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick WaylandClient)

qt_standard_project_setup()

set(plugin_SOURCES
    src/extensions/cutie-shell.cpp src/extensions/cutie-shell.h
    src/plugin.cpp src/plugin.h)

qt6_add_library(qmlcutiewlcplugin
    SHARED
    ${plugin_SOURCES}
)

target_include_directories(qmlcutiewlcplugin PUBLIC
    src
)

qt6_generate_wayland_protocol_client_sources(
    qmlcutiewlcplugin
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/protocols/cutie-shell-private.xml
)

target_link_libraries(qmlcutiewlcplugin PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    Qt::WaylandClient
)

install(TARGETS qmlcutiewlcplugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc"
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/qmldir 
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc")