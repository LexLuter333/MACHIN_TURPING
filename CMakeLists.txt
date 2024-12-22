cmake_minimum_required(VERSION 3.22.1)
project(MACHIN_TURPING C)

set(CMAKE_C_STANDARD 11)

include_directories(Headers)

add_executable(MACHIN_TURPING
    Headers/Alg_Tyring.h
    Headers/Cecker.h
    Headers/ErrorHandler.h
    Headers/I_O_File.h
    Headers/memoryUtils.h
    Headers/Structures.h
    src/algorithm.c
    src/Checker.c
    src/I_O_File.c
    src/main.c)
