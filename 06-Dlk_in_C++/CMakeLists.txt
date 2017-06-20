##########################
# Cmake Basics
##########################

cmake_minimum_required (VERSION 2.8)
include_directories(${CMAKE_SOURCE_DIR})
project (DLK_in_C++)


##########################
# Modules
##########################

add_library(modA MODULE
  	../modA.cpp
)

add_library(modB MODULE
  	../modB.cpp
)

#################################
# add executables for operation
#################################

add_executable(exec
  	../main.cpp
)

target_link_libraries(exec ${CMAKE_DL_LIBS})

