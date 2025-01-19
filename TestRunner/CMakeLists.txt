cmake_minimum_required(VERSION 3.16)

project(TestRunner LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Pliki źródłowe aplikacji GUI
set(SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Tworzenie pliku wykonywalnego
add_executable(TestRunner ${SOURCES})

# Linkowanie z biblioteką CW7FL i Qt Widgets
target_link_libraries(TestRunner PRIVATE CW7FL Qt6::Widgets)
