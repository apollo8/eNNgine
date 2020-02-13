cmake_minimum_required(VERSION 3.1)

project(enngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")

# headers

include_directories("include")

# executable

file(GLOB_RECURSE SRC_ENNGINE "src/*cpp")
add_executable(enngine ${SRC_ENNGINE})
