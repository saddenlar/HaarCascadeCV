cmake_minimum_required(VERSION 3.6)
project(HaarCascade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Current directory as working directory.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_FILES main.cpp)
add_executable(HaarCascade ${SOURCE_FILES})

# OpenCV 3 is required.
find_package(OpenCV REQUIRED)
target_link_libraries(HaarCascade ${OpenCV_LIBS})