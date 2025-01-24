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
        ../CW7FL/Calculator.cpp
        Cases/Subtraction/Subtraction.cpp
        Cases/Subtraction/Subtraction.h
        Cases/Multiplication/Multiplication.cpp
        Cases/Multiplication/Multiplication.h
        Cases/Division/Division.cpp
        Cases/Division/Division.h
        Cases/Modulo/Modulo_tests.cpp
        Cases/Modulo/Modulo_tests.h
        Cases/and_tests/And_tests.cpp
        Cases/and_tests/And_tests.h
        Cases/or_tests/Or_tests.cpp
        Cases/or_tests/Or_tests.h
        Cases/xor_tests/Xor_tests.cpp
        Cases/xor_tests/Xor_tests.h
        Cases/not_tests/not_tests.cpp
        Cases/not_tests/not_tests.h
)

# Linkuj z bibliotekami
target_link_libraries(Tests PRIVATE GTest::GTest GTest::Main)


