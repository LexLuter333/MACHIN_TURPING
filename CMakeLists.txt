cmake_minimum_required(VERSION 3.30)
project(testMT C)

include_directories(Headers src)

set(CMAKE_C_STANDARD 11)

add_executable(testMT
        Headers/Alg_Tyring.h
        Headers/Cecker.h
        Headers/ErrorHandler.h
        Headers/I_O_File.h
        Headers/memoryUtils.h
        Headers/Structures.h
        Headers/memoryUtils.h
        src/algTyr.c
        src/utils.c
        src/algorithm.c
        src/Checker.c
        src/I_O_File.c
        src/main.c
        src/memoryUtils.c
)
