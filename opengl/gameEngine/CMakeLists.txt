cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)


project(opengl_d1 VERSION 0.5)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(opengl_d1 Application.cpp ${SRC_FILES})
target_link_libraries(opengl_d1 glfw ${OPENGL_LIBRARIES})
target_include_directories(opengl_d1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)