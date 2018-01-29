cmake_minimum_required(VERSION 3.5)

set(LIB_NAME DeckLoader)

set(CMAKE_CXX_STANDARD 14)

project(${LIB_NAME})

add_subdirectory(test)

aux_source_directory(. SCR)

add_library(${LIB_NAME} STATIC ${SCR})

