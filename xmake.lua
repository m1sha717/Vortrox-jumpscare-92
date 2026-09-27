add_rules("mode.debug", "mode.release")

includes("@geode")

target("vortrox_92_jumpscare")
    set_kind("shared")
    add_rules("geode.mod")
    add_files("src/main.cpp")
