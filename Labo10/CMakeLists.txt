cmake_minimum_required(VERSION 3.22)
project(Labo10)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp
        ejercicios.cpp
        ejercicios.h
        )

add_executable(Labo10 ${SOURCE_FILES})
