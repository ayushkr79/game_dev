cmake_minimum_required(VERSION 3.27)

project(PongGame VERSION 0.1.0 LANGUAGES C CXX)

set(PONG_GAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(PongGame ${PONG_GAME_DIR}/main.cpp 
                        ${PONG_GAME_DIR}/paddle.cpp
                        ${PONG_GAME_DIR}/ball.cpp)

target_link_libraries(PongGame sfml-graphics sfml-window sfml-system)