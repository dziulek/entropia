project(Entropy)

cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 14)

file(GLOB HEADERS *.hpp)
file(GLOB SOURCE *.cpp)

message("${HEADERS}")

add_executable("${PROJECT_NAME}" ${SOURCE} ${HEADERS})

target_link_libraries(Entropy -lsfml-graphics -lsfml-window -lsfml-system)
