cmake_minimum_required(VERSION 4.0)
project(labs C)

set(CMAKE_C_STANDARD 11)

add_executable(labs
        main.c
        header/lab1.h
        header/lab2.h
        header/lab3.h
        header/lab4.h
        src/lab1.c
        src/lab2.c
        src/lab3.c
        src/lab4.c
        src/lab4_utils.c
        src/lab5.c
        header/lab5.h
        src/lab5_utils.c
        src/lab6.c
        header/lab6.h
        src/lab7.c
        header/lab7.h
)
