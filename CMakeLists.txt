cmake_minimum_required(VERSION 3.26)
project(lab8)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab8 main.cpp
        Person.cpp
        Person.h
        Container.h
        Sorter.h
        IPrintable.h
        Logger.h)