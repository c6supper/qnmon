# ----------------------------------------------------------------
# Copyright (c) Coding Nerd
# Licensed under the Apache License, Version 2.0
# See LICENSE in the project root for license information.
# ----------------------------------------------------------------
cmake_minimum_required(VERSION 3.5.1)

project(unify-nmon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FIND_PACKAGE(Boost 1.78 COMPONENTS program_options REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  LINK_PUBLIC ${Boost_LIBRARIES}

  # sub::cpu
  # sub::ram
  # sub::io
  # sub::network
)