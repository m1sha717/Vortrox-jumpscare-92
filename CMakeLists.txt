cmake_minimum_required(VERSION 3.26)

setting(GEODE_DONT_INSTALL_BINARIES ON)

find_package(Geode REQUIRED CONFIG PATHS /home/vscode/.config/Geode/sdk)

project(vortrox_92_jumpscare VERSION 1.0.0 LANGUAGES CXX)

add_geode_mod(
    CONVENTIONAL
    SOURCES src/main.cpp
)
