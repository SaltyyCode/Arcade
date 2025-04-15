cmake_minimum_required(VERSION 3.10)
project(Arcade)

# Langage & flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Werror -fno-gnu-unique")

# Répertoires
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_LIB_DIR ${SRC_DIR}/Libraries)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

# Includes globaux
include_directories(${INCLUDE_DIR} ${INCLUDE_DIR}/Shared)

# Executable principal
add_executable(arcade ${SRC_DIR}/main.cpp ${CORE_SRC})

########### Ajout de la bibliothèque SDL2 ###########

# Chercher SDL2 et ses composants (tu peux ajouter SDL2_image si nécessaire)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)

# Ajouter tous les fichiers source SDL2
file(GLOB_RECURSE SDL2_SRC "${SOURCE_LIB_DIR}/SDL2/*.cpp")

# Créer la bibliothèque dynamique SDL2
add_library(arcade_sdl2 SHARED ${SDL2_SRC})

# Ajouter les headers si besoin
target_include_directories(arcade_sdl2 PRIVATE ${SOURCE_LIB_DIR}/SDL2)

# Lier SDL2 et ses composants à la lib partagée
target_link_libraries(arcade_sdl2
    SDL2
    SDL2_ttf
    SDL2_mixer
    SDL2_image
)

# Optionnel définir le dossier de sortie pour la shared lib
set_target_properties(arcade_sdl2 PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR}
    PREFIX "")

target_link_libraries(arcade dl)

# SFML
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
file(GLOB_RECURSE SFML_SRC "${SOURCE_LIB_DIR}/SFML/*.cpp")
include_directories(${SOURCE_LIB_DIR}/SFML)
add_library(arcade_sfml SHARED ${SFML_SRC})
target_link_libraries(arcade_sfml sfml-graphics sfml-window sfml-system sfml-audio)
set_target_properties(arcade_sfml PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR}
    PREFIX "")

# Ncurses
find_package(Curses REQUIRED)
file(GLOB_RECURSE NCURSES_SRC "${SOURCE_LIB_DIR}/Ncurse/*.cpp")
include_directories(
    ${SOURCE_LIB_DIR}/Ncurse
    ${SOURCE_LIB_DIR}/Ncurse/Factories
    ${SOURCE_LIB_DIR}/Ncurse/Models
    ${LIB_DIR}/NcurseLibrary
)
add_library(arcade_ncurses SHARED ${NCURSES_SRC})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})
set_target_properties(arcade_ncurses PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR}
    PREFIX "")

# Snake Game
file(GLOB_RECURSE SNAKE_SRC "${SRC_DIR}/Games/Snake/*.cpp")
include_directories(${SRC_DIR}/Games/Snake)
add_library(arcade_snake SHARED ${SNAKE_SRC})
set_target_properties(arcade_snake PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    PREFIX "")

# Nibbler Game
file(GLOB_RECURSE NIBBLER_SRC "${SRC_DIR}/Games/Nibbler/*.cpp")
include_directories(${SRC_DIR}/Games/Nibbler)
add_library(arcade_nibbler SHARED ${NIBBLER_SRC})
set_target_properties(arcade_nibbler PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    PREFIX "")

# Targets de build perso
add_custom_target(my_all
    COMMAND cmake -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    COMMAND cmake --build build
    COMMENT "Building the project..."
)

add_custom_target(my_clean
    COMMAND ${CMAKE_COMMAND} --build build --target clean
    COMMENT "Cleaning compiled files..."
)

add_custom_target(fclean
    COMMAND rm -rf build
    COMMENT "Full clean: Removing build directory..."
)

add_custom_target(re
    COMMAND ${CMAKE_COMMAND} --build build --target fclean
    COMMAND cmake -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    COMMAND cmake --build build
    COMMENT "Recompiling everything...")
