cmake_minimum_required(VERSION 3.23)
project(Hwmk101337)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hwmk101337 main.cpp RegularAccount.cpp PremiumAccount.cpp Account.cpp Account.h Date.h PremiumAccount.h RegularAccount.h Date.cpp Common.h)
