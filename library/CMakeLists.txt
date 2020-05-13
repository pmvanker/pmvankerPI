cmake_minimum_required(VERSION 3.5.1)
project(pmvankerPI)
find_package (Threads)
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

#Only available from version 2.8.9 on
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

#Bring the headers, such as Student.h into the project
include_directories(bus gpio network)

#However, the file(GLOB...) will allow for wildcard additions:
file(GLOB_RECURSE SOURCES "./*.cpp")

#Can build statically to libEBBLibrary.a using the next line
#add_library(pmvankerPI STATIC ${SOURCES})

#Building shared library to libEBBLibrary.so using the next line
add_library(pmvankerPI SHARED ${SOURCES})

target_link_libraries(pmvankerPI ${CMAKE_THREAD_LIBS_INIT})

install (TARGETS pmvankerPI DESTINATION /usr/lib)
