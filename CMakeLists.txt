cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(Headers Filters.h InputOutput.h Image.h Color.h crop_filter.h grayscale_filter.h negative_filter.h controller.h)


add_executable(image_processor ${PROJECT_SOURCE_DIR}/ Image.cpp grayscale_filter.cpp negative_filter.cpp test.cpp Filters.cpp InputOutput.cpp Color.cpp controller.cpp crop_filter.cpp)
