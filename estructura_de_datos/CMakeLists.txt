cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(todo)

add_executable(todo func_guardar.c dec_structs.c nombres_constantes.c)
target_include_directories(todo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
