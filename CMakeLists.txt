cmake_minimum_required(VERSION 3.21)
project(talalpowerwave_project C)

set(CMAKE_C_STANDARD 99)

add_executable(talalpowerwave_project main.c io.c io.h waveform.c waveform.h test.c)
