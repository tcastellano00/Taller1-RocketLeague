# =============================================================================
# Trabajo Práctico Final - Taller de Programación I
# =============================================================================

#------------------------------------------------------------------------------
# CONFIGURACION DEL PROYECTO
cmake_minimum_required(VERSION 1.0.0)
project(rocket_league)

#------------------------------------------------------------------------------
# FLAGS DE COMPILACION
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -pedantic-errors")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline")

#------------------------------------------------------------------------------
# ARCHIVOS FUENTE
FILE(GLOB_RECURSE common_src "Common/*.cpp")
FILE(GLOB_RECURSE client_src "Client/*.cpp")
FILE(GLOB_RECURSE server_src "Server/*.cpp")

#------------------------------------------------------------------------------
# TARGETS
# Common
add_library(rocket_league-common SHARED ${common_src})

# Client
add_executable(rocket_league ${client_src})
target_link_libraries(rocket_league rocket_league-common SDL2 SDL2_image SDL2_ttf SDL2_mixer)

# Server
add_executable(rocket_league-server ${server_src})
target_link_libraries(rocket_league-server rocket_league-common)