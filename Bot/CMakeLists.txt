cmake_minimum_required(VERSION 3.16)
project(Bot C)

set(CMAKE_C_STANDARD 99)

add_executable(Bot main.c dados.c dados.h io.c io.h io_aux.c io_aux.h listas.c listas.h logica.c logica.h interface.h interface.c)