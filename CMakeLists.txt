cmake_minimum_required(VERSION 3.16)

project(CalcWIN7forLinux LANGUAGES CXX)

# Dodanie aplikacji głównej
add_subdirectory(CW7FL)

# Dodanie projektu testowego
add_subdirectory(Test)

# Dodanie GUI do zarządzania testami
add_subdirectory(TestRunner)

