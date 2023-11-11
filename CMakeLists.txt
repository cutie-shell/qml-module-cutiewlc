cmake_minimum_required(VERSION 3.16)
project(qmlcutiewlcplugin VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui WaylandClient Quick)
pkg_check_modules(CUTIEWLC cutiewlc REQUIRED IMPORTED_TARGET)
pkg_check_modules(FOREIGN_TP_MGMT qt6-foreign-toplevel-management REQUIRED IMPORTED_TARGET)

qt_standard_project_setup()

set(plugin_SOURCES
    src/plugin.cpp src/plugin.h)

qt6_add_library(qmlcutiewlcplugin
    SHARED
    ${plugin_SOURCES}
)

target_include_directories(qmlcutiewlcplugin PUBLIC
    src
)

target_link_libraries(qmlcutiewlcplugin PUBLIC
    Qt::Core
    Qt::Gui
    Qt::WaylandClient
    Qt::Quick
    PkgConfig::CUTIEWLC
    PkgConfig::FOREIGN_TP_MGMT
)

install(TARGETS qmlcutiewlcplugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc"
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/qmldir 
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt${QT_VERSION_MAJOR}/qml/Cutie/Wlc")