cmake_minimum_required(VERSION 3.20)
project(SnakeGame)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(libs/SDL2/include)
link_directories(libs/SDL2/lib)


file(GLOB SOURCES "src/*.cpp")
add_executable(Snake ${SOURCES})


# Link for MinGW
if (MINGW)
target_link_libraries(Snake mingw32 SDL2main SDL2)
else()
target_link_libraries(Snake SDL2)
endif()


# Copy SDL2.dll to output on Windows
if (WIN32)
add_custom_command(TARGET Snake POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/libs/SDL2/bin $<TARGET_FILE_DIR:Snake>)
endif()
