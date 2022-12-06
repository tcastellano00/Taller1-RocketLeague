# =============================================================================
# Trabajo Práctico Final - Taller de Programación I
# =============================================================================

#------------------------------------------------------------------------------
# CONFIGURACION DEL PROYECTO
cmake_minimum_required(VERSION 1.0.0)
project(rocket_league)

#------------------------------------------------------------------------------
# FLAGS DE COMPILACION
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread --coverage")
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(APPLE)
  message("Estoy en OSX")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include -L/usr/local/lib -lSDL2")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -pedantic-errors")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline")

#Including QT5
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core)

qt5_wrap_ui(UIS_HEADERS
  UI/dialogcreategame.ui
  UI/dialogjoingame.ui
  UI/dialoglistgames.ui
  UI/lobbyform.ui
)

# Instruct CMake to run moc automatically when neededcd
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTORCC ON)

message("Headers generados: ${UIS_HEADERS}")

# Including Box2D
include_directories(./libs/Box2D)
file(GLOB_RECURSE BOX2D_SRCS ./libs/Box2D/*.cpp)
add_library(libbox2d STATIC ${BOX2D_SRCS})

#Including yaml
find_package(yaml-cpp REQUIRED)

# Agrego la libreria SDL2pp habilitando manejo de imagenes y de letras
SET(SDL2PP_WITH_IMAGE YES)
SET(SDL2PP_WITH_MIXER YES)
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
FILE(GLOB_RECURSE tests_src "Tests/*.cpp")

#------------------------------------------------------------------------------
# TARGETS
# Common
add_library(rocket_league-common SHARED ${common_src})
target_link_libraries(rocket_league-common yaml-cpp)

# Client
add_executable(rocket_league ${client_src} ${UIS_HEADERS})
target_link_libraries(rocket_league rocket_league-common Qt5::Core Qt5::Widgets ${SDL2PP_LIBRARIES})

# Server
add_executable(rocket_league-server ${server_src})
target_link_libraries(rocket_league-server rocket_league-common libbox2d)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY config DESTINATION ${CMAKE_BINARY_DIR})
file(COPY music DESTINATION ${CMAKE_BINARY_DIR})


#------------------------------------------------------------------------------
# TESTS
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(rocket_league-serverlib SHARED ${server_src})
add_executable(
  tests ${tests_src}
)
target_link_libraries(tests rocket_league-serverlib rocket_league-common libbox2d GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)


#------------------------------------------------------------------------------
# INSTALL
set(BINARIES_DIRPATH "/usr/local/bin")
#set(SHAREDLIBS_DIRPATH "/usr/local/lib")

# Common
install(TARGETS rocket_league-common DESTINATION ${BINARIES_DIRPATH} PERMISSIONS WORLD_READ WORLD_WRITE WORLD_EXECUTE)

# Cliente
install(TARGETS rocket_league DESTINATION ${BINARIES_DIRPATH} PERMISSIONS WORLD_READ WORLD_WRITE WORLD_EXECUTE WORLD_EXECUTE)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${BINARIES_DIRPATH} FILE_PERMISSIONS WORLD_READ WORLD_WRITE)

# Server
install(TARGETS rocket_league-server DESTINATION ${BINARIES_DIRPATH} PERMISSIONS WORLD_READ WORLD_WRITE WORLD_EXECUTE)