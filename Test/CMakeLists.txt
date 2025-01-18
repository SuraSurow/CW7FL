cmake_minimum_required(VERSION 3.16)

project(Tests LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
if (NOT GTest_FOUND)
    message(FATAL_ERROR "No GTest Found")
endif()

# Dodanie ścieżki do katalogu, w którym znajduje się biblioteka CW7FL
link_directories(${CMAKE_SOURCE_DIR}/../CW7FL/build/Desktop_Qt_6_7_2-Debug)

# Tworzenie pliku wykonywalnego dla testów
add_executable(InitTest main.cpp tst_inittest.cpp)

# Linkowanie z biblioteką CW7FL i Google Test
target_link_libraries(InitTest PRIVATE CW7FL GTest::GTest)

# Ustawienie rpath, aby linker znalazł bibliotekę w czasie uruchamiania
set_target_properties(InitTest PROPERTIES INSTALL_RPATH ${CMAKE_SOURCE_DIR}/../CW7FL/build/Desktop_Qt_6_7_2-Debug)

# Dodanie testu do frameworka testowego CTest
add_test(NAME InitTest COMMAND InitTest)

