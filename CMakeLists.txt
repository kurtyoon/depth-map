cmake_minimum_required(VERSION 3.10)
project(StereoDepthMap)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/usecase)
include_directories(${CMAKE_SOURCE_DIR}/infrastructure)

add_executable(StereoDepthMap main.cpp
        core/StereoMatcher.cpp
        usecase/DepthMapCalculator.cpp
        infrastructure/ImageLoader.cpp)

target_link_libraries(StereoDepthMap ${OpenCV_LIBS})
