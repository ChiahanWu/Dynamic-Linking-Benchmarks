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
target_link_libraries (modA pthread)

add_library(modB MODULE
  	../modB.cpp
)
target_link_libraries (modB pthread)

#################################
# add executables for operation
#################################

add_executable(main
  	../main.cpp
  )

target_link_libraries(main ${CMAKE_DL_LIBS})

