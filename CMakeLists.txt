cmake_minimum_required(VERSION 3.25)
project(VortroxJumpscare)

find_package(Geode REQUIRED)

add_geode_mod(
    vortrox_jumpscare
    VERSION 1.0.0
)

target_sources(vortrox_jumpscare PRIVATE src/main.cpp)

