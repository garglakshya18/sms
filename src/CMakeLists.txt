cmake_minimum_required(VERSION 3.8)
project(SMS)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp core/auth/User.cpp core/auth/User.h database/handler.cpp database/handler.h core/db/base.cpp core/db/base.h core/init.cpp core/init.h)
add_executable(SMS ${SOURCE_FILES})