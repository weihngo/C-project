cmake_minimum_required(VERSION 3.17)
project(worker_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(worker_system main.cpp Person.h workManager.cpp workManager.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)