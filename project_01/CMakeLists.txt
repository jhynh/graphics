cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/include/SDL2_image-2.6.2/cmake/")


project(project_1 VERSION 0.9)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_subdirectory(include/SDL2_image-2.6.2)

add_executable(project_1 main.cpp ${SRC_FILES})
target_link_libraries(project_1 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_include_directories(project_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(project_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ECS)
target_include_directories(project_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/gui)
#https://trenki2.github.io/blog/2017/07/04/using-sdl2-image-with-cmake/
#https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/