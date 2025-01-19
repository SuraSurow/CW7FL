cmake_minimum_required(VERSION 3.16)

project(Tests LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Znajdź Google Test
find_package(GTest REQUIRED)

# Dodaj katalogi z nagłówkami
include_directories(${CMAKE_SOURCE_DIR}/../CW7FL)

# Dodaj pliki źródłowe i nagłówkowe
add_executable(Tests
        main.cpp
        Cases/Addition/Addition.cpp
        /home/bolo/CLionProjects/CW7FL/CW7FL/Calculator.cpp
)

# Linkuj z bibliotekami
target_link_libraries(Tests PRIVATE GTest::GTest GTest::Main)


