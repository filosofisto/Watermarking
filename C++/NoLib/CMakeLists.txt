cmake_minimum_required(VERSION 3.31)
project(Watermark_NoLib)

set(CMAKE_CXX_STANDARD 23)

add_executable(NoLib main.cpp steganography.cpp
        steganography.cpp
        steganography.h)
