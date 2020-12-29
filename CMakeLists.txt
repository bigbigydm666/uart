cmake_minimum_required(VERSION 3.1)
project(UART)

add_executable(run main.cpp serialPort.cpp)
include_directories(/home/ydm/Codes/UART/uart)
