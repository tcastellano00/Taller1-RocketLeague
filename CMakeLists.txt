# =============================================================================
# Trabajo Práctico Final - Taller de Programación I
# =============================================================================

#------------------------------------------------------------------------------
# CONFIGURACION DEL PROYECTO
cmake_minimum_required(VERSION 1.0.0)
project(rocket_league)

#------------------------------------------------------------------------------
# FLAGS DE COMPILACION
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(APPLE)
  message("Estoy en OSX")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include -L/usr/local/lib -lSDL2")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -pedantic-errors")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline")


# Including Box2D
include_directories(./libs/Box2D)
file(GLOB_RECURSE BOX2D_SRCS ./libs/Box2D/*.cpp)
add_library(libbox2d STATIC ${BOX2D_SRCS})

# Agrego la libreria SDL2pp habilitando manejo de imagenes y de letras
SET(SDL2PP_WITH_IMAGE YES)
SET(SDL2PP_WITH_TTF YES)
add_subdirectory(libs/libSDL2pp)


# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_SOURCE_DIR}/libs' como directorio de includes")
include_directories(${PROJECT_SOURCE_DIR}/libs)
include_directories(${SDL2PP_INCLUDE_DIRS})


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
target_link_libraries(rocket_league rocket_league-common ${SDL2PP_LIBRARIES})

# Server
add_executable(rocket_league-server ${server_src})
target_link_libraries(rocket_league-server rocket_league-common libbox2d)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})