cmake_minimum_required(VERSION 3.25)
project(RayChess C)

set(CMAKE_C_STANDARD 11)

include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)
CPMAddPackage(
        NAME raylib
        GITHUB_REPOSITORY raysan5/raylib
        GIT_TAG 5.0
)

add_executable(${PROJECT_NAME}
        src/main.c
        src/board.c
        src/board.h

)

target_link_libraries(${PROJECT_NAME} raylib)
