cmake_minimum_required(VERSION 3.16)

project(CW7FL VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        Calculator.cpp
        Calculator.h
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# Tworzenie biblioteki
add_library(CW7FL SHARED
    ${PROJECT_SOURCES}
)

target_include_directories(CW7FL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(CW7FL PRIVATE Qt6::Widgets)

# Dodanie opcjonalnych właściwości
set_target_properties(CW7FL PROPERTIES
    MACOSX_BUNDLE TRUE
    OUTPUT_NAME "CW7FL"
)

# Tworzenie pliku wykonywalnego do uruchamiania aplikacji
add_executable(AppRunner main.cpp)

# Linkowanie pliku wykonywalnego z biblioteką
target_link_libraries(AppRunner PRIVATE CW7FL Qt6::Widgets)

# Instalacja biblioteki i pliku wykonywalnego
include(GNUInstallDirs)
install(TARGETS CW7FL AppRunner
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalizacja dla Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_target(CW7FL)
    qt_finalize_target(AppRunner)
endif()


