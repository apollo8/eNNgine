cmake_minimum_required(VERSION 3.16)

project(eNNgine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")

# headers

include_directories("include")

# executable

file(GLOB_RECURSE SRC_ENNGINE "src/*cpp")
add_executable(enngine ${SRC_ENNGINE})

# cppcheck target

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_custom_target(lint
    cppcheck --enable=all --inconclusive --project=compile_commands.json)
