cmake_minimum_required(VERSION 3.16)
project(RastrosLI2 C)

set(CMAKE_C_STANDARD 99)
add_executable(RastrosLI2 main.c listas.h listas.c io.c io.h logica.h logica.c dados.c dados.h io_aux.c io_aux.h interface.c interface.h)
target_link_libraries(RastrosLI2 m)
