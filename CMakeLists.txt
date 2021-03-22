project(Entropy)

<<<<<<< HEAD
cmake_minimum_required(VERSION 3.13.4)
=======
cmake_minimum_required(VERSION 3.13)
>>>>>>> 633cdf26ec2f1f8263d306ae547f19215966b3bb

set(CMAKE_CXX_STANDARD 14)

file(GLOB HEADERS *.hpp)
file(GLOB SOURCE *.cpp)

message("${HEADERS}")

add_executable("${PROJECT_NAME}" ${SOURCE} ${HEADERS})

target_link_libraries(Entropy -lsfml-graphics -lsfml-window -lsfml-system)
