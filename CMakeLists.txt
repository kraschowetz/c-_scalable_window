cmake_minimum_required(VERSION 3.8)
project(main)

file(GLOB_RECURSE sources
	"${CMAKE_SOURCE_DIR}/src/*.cpp"
	"${CMAKE_SOURCE_DIR}/src/*.hpp"
	"${CMAKE_SOURCE_DIR}/src/*/*.cpp"
	"${CMAKE_SOURCE_DIR}/src/*/*.hpp"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED sdl2_image)

add_executable(main ${sources})

if(TARGET SDL2::SDL2main)
	target_link_libraries(main PRIVATE SDL2::SDL2main SDL2_image)
endif()

add_compile_options(-02)

target_link_libraries(main PRIVATE SDL2::SDL2)

