cmake_minimum_required(VERSION 2.8)

project("Rate Monotonic Scheduling")

ADD_DEFINITIONS(-std=c++0x)

# SOURCE FILES
set(RMS_SRC
    src/schedular.cc
)

# HEADER FILES
set(RMS_HDR
    src/header/header.h
    src/header/schedular.h
)

add_executable(schedular src/schedular_main.cpp
                         src/schedular.cc
)
