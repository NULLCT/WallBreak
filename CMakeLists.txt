cmake_minimum_required (VERSION 3.8)
project(WallBreak CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set( wallbreak_src
    src/main.cpp
    src/ball.cpp
    src/paddle.cpp
    src/wall.cpp
   )
add_executable(WallBreak ${wallbreak_src})

set(SFML_DIR "SFML/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics audio REQUIRED)
target_link_libraries(WallBreak sfml-graphics sfml-window sfml-system)
