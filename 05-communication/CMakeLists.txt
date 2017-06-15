##########################
# Cmake Basics
##########################

cmake_minimum_required (VERSION 2.8)
include_directories(${CMAKE_SOURCE_DIR})
project (DLK_Communication)


##########################
# Modules
##########################

add_library(modA MODULE
  	../modA.c
)

add_library(modB MODULE
  	../modB.c
)

#################################
# add executables for operation
#################################

add_executable(main
  	../main.c
  )

target_link_libraries(main ${CMAKE_DL_LIBS})

