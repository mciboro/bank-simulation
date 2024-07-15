cmake_minimum_required(VERSION 3.0.0)
project(bank-simulation VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB SOURCES "src/*.cpp")
add_executable(bank-simulation main.cpp ${SOURCES})
target_include_directories(bank-simulation PRIVATE ./include)
