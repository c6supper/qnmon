# Set the project name
project(cpu)

# Add a library with the above sources
add_executable(${PROJECT_NAME}
  src/cpu.cpp
  ../../common/src/main.cpp
  ../../common/src/property_manager.cpp
)

target_link_libraries(${PROJECT_NAME}
  LINK_PUBLIC ${Boost_LIBRARIES}
  asio-grpc::asio-grpc
  Boost::headers
  -lsocket
)

target_include_directories(${PROJECT_NAME}
  PRIVATE ../common/inc
)