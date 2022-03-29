# Set the project name
project(cpu)

# Add a library with the above sources
add_library(${PROJECT_NAME} src/cpu.cpp)
add_library(sub::cpu ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)