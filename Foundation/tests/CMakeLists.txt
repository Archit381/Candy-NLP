cmake_minimum_required(VERSION 3.8)

add_executable(tester main.cpp)

target_include_directories(tester PUBLIC "${CMAKE_SOURCE_DIR}/Foundation/include/Foundation/")

target_link_libraries(tester PRIVATE Candy-NLP)

add_test(NAME Candy-NLP.Commands.Sample COMMAND tester sample)