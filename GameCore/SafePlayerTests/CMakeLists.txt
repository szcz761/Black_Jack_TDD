cmake_minimum_required(VERSION 3.5)

set(APP_NAME SafePlayerTest)

project(${APP_NAME})


include_directories(${gmock_SOURCE_DIR}/include)
include_directories(${gtest_SOURCE_DIR}/include)

include_directories(${DeckLoader_SOURCE_DIR})
include_directories(${GameCoreLib_SOURCE_DIR})

aux_source_directory(. SCR)

add_executable(${APP_NAME} ${SCR})

target_link_libraries(${APP_NAME} gmock gmock_main)
target_link_libraries(${APP_NAME} GameCoreLib)