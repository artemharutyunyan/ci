# Minimum required version of cmake 
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Build type 
SET(CMAKE_BUILD_TYPE "Debug")

# Output directory 
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

SUBDIRS(src)
