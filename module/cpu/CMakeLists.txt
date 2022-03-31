# Set the project name
project(cpu)

# Add a library with the above sources
add_executable(${PROJECT_NAME}
  src/cpu.cpp
  ../../common/src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
  LINK_PUBLIC ${Boost_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}
  PRIVATE ../common/inc
)