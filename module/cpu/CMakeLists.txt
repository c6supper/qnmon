# Set the project name
project(cpu)

# Add a library with the above sources
add_executable(${PROJECT_NAME}
  src/cpu.cpp
  ../../common/src/main.cpp
  ../../common/src/property_manager.cpp
)

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
  target_link_libraries(${PROJECT_NAME}
    LINK_PUBLIC ${Boost_LIBRARIES}
    -lsocket
  )
elseif()
  target_link_libraries(${PROJECT_NAME}
    LINK_PUBLIC ${Boost_LIBRARIES}
  )
endif()

target_include_directories(${PROJECT_NAME}
  PRIVATE ../common/inc
)
