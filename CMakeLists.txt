cmake_minimum_required(VERSION 3.10)

# Set project name and C++ language
project(Monsters LANGUAGES CXX)

# Specify the C++ compiler
set(CMAKE_CXX_COMPILER g++) # Change this to your preferred compiler (e.g., clang++)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add header files (not necessary for compilation, but useful for clarity)
set(HEADER_FILES
    headers/creature.h
    headers/monster.h
    headers/player.h
    headers/myRandom.h
    headers/dungeon.h
    headers/input.h
    headers/json.h
)

# Add source files
set(SOURCE_FILES
    src/creature.cpp
    src/monster.cpp
    src/player.cpp
    src/main.cpp
    src/dungeon.cpp
    src/input.cpp
)

# Create the executable
add_executable(Monsters ${SOURCE_FILES})

# Include directories for headers
find_library(CPP-JSON_LIB NAMES libCPP-JSON.so PATHS /usr/local/lib REQUIRED)
target_include_directories(Monsters PRIVATE ${CMAKE_SOURCE_DIR}/headers)
target_include_directories(Monsters PRIVATE /usr/local/include)
target_link_libraries(Monsters PRIVATE ${CPP-JSON_LIB})
set_target_properties(Monsters PROPERTIES LINK_DIRECTORIES /usr/local/lib)