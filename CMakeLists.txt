cmake_minimum_required(VERSION 3.10)

project(snowdrift C)

option(BUILD_CLIENT "Build client" ON)

# set some global dirs like build and src dir
include(cmake/dirs.cmake)

include(cmake/platforms/all.cmake)
include(cmake/libraries/all.cmake)


include(cmake/client.cmake)
# target_compile_definitions(snowdrift PRIVATE DEDICATED)
