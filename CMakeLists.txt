cmake_minimum_required(VERSION 3.20)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)

# Paths
include_directories(libs/SDL2/include)
link_directories(libs/SDL2/lib)

file(GLOB SOURCES "src/*.cpp")

add_executable(Snake ${SOURCES})

target_link_libraries(Snake mingw32 SDL2main SDL2)
