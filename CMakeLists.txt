cmake_minimum_required(VERSION 3.15)
project(foodOrdering C)

set(CMAKE_C_STANDARD 99)

add_executable(foodOrdering main.c menu.h menu.c user.h order.h user.c choice.h choice.c order.c dataProcessing.c usersData.h usersData.c)