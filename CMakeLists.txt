cmake_minimum_required(VERSION 3.1)

project(Snake)

file(GLOB RESOURCES "resources/*")
file(COPY ${RESOURCES} DESTINATION .)

set(CPP_FILES src/main.cpp src/snake.cpp)
add_executable(Snake ${CPP_FILES})
target_link_libraries(Snake sfml-graphics sfml-audio sfml-system sfml-window)
