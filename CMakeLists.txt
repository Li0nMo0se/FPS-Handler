cmake_minimum_required(VERSION 3.0)

# project name
project(fps-handler)

# creates the variable EXEC
set(EXEC example)

# set the C++20 standard
set(CMAKE_CXX_STANDARD 20)

# puts all .cc files to the SOURCES variable
file(GLOB SOURCES *.cc)


# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})