# ----------------------------------------------------------------
# Copyright (c) Coding Nerd
# Licensed under the Apache License, Version 2.0
# See LICENSE in the project root for license information.
# ----------------------------------------------------------------
cmake_minimum_required(VERSION 3.5.1)

project(unify-nmon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
FIND_PACKAGE(Boost 1.78 COMPONENTS program_options thread log log_setup REQUIRED)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

INCLUDE_DIRECTORIES(
  ${Boost_INCLUDE_DIR}
  common/inc
)

add_subdirectory(proto)
add_subdirectory(module)

add_executable(${PROJECT_NAME} common/src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
  inc
)

target_link_libraries(${PROJECT_NAME}
  LINK_PUBLIC ${Boost_LIBRARIES}
  neptune-profiler-proto
)