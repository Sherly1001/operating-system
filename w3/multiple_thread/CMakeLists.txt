cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(ball_multiple_thread)

include_directories(${PROJECT_SOURCE_DIR}/sdl2/include)
link_directories(${PROJECT_SOURCE_DIR}/sdl2/lib)

set(CMAKE_C_FLAGS "-mwindows -pthread")
set(LINK_LIBS mingw32 sdl2main sdl2)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

FILE (GLOB C_SRCS *.c)

add_executable(${PROJECT_NAME} ${C_SRCS})
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})