cmake_minimum_required(VERSION 4.0)
project(labs C)

set(CMAKE_C_STANDARD 11)

add_executable(labs
        main.c
        include/lab1.h
        include/lab2.h
        include/lab3.h
        include/lab4.h
        src/lab1.c
        src/lab2.c
        src/lab3.c
        src/lab4.c
        src/lab4_utils.c
        src/lab5.c
        include/lab5.h
        src/lab5_utils.c
        src/lab6.c
        include/lab6.h
        src/lab7.c
        include/lab7.h
        src/lab8.c
        include/lab8.h
        src/lab9.c
        include/lab9.h
        src/lab10.c
        include/lab10.h
        src/lab11.c
        include/lab11.h
        src/lab11_utils.c
)
