# ----------------------------------------------------------------
# Copyright (c) Coding Nerd
# Licensed under the Apache License, Version 2.0
# See LICENSE in the project root for license information.
# ----------------------------------------------------------------
cmake_minimum_required(VERSION 3.20.2)

project(unify-nmon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
FIND_PACKAGE(Boost 1.78 COMPONENTS program_options thread log log_setup REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

INCLUDE_DIRECTORIES(
  ${Boost_INCLUDE_DIR}
  common/inc
  proto/cpp
)

add_subdirectory(proto)
add_subdirectory(module)

add_executable(${PROJECT_NAME}
  common/src/main.cpp
  common/src/property_manager.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
  inc
)

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
  target_link_libraries(${PROJECT_NAME}
    LINK_PUBLIC ${Boost_LIBRARIES}
    neptune-profiler-proto
    gRPC::grpc++
    -lsocket
  )
elseif()
  target_link_libraries(${PROJECT_NAME}
    LINK_PUBLIC ${Boost_LIBRARIES}
    neptune-profiler-proto
    gRPC::grpc++
  )
endif()
