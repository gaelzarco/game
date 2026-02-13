cmake_minimum_required(VERSION 3.11)

project(game)

add_executable(game game.cxx)

set_source_files_properties(game.cxx PROPERTIES COMPILE_OPTIONS "-std=c++23")
