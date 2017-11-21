cmake_minimum_required(VERSION 3.8)
project(SMS)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/core/auth/User.cpp src/core/auth/User.h src/database/handler.cpp src/database/handler.h src/core/db/base.cpp src/core/db/base.h src/core/init.cpp src/core/init.h src/Timetable/TimeTable.cpp src/Timetable/TimeTable.h src/Courses/Courses.cpp src/Courses/Courses.h src/attendance/attendance.h src/attendance/attendance.cpp)
add_executable(SMS ${SOURCE_FILES} src/attendance/attendance.h src/attendance/attendance.cpp)