cmake_minimum_required(VERSION 3.30)
project(TeamP)

set(CMAKE_CXX_STANDARD 20)


include_directories(include)
include_directories(/opt/homebrew/opt/libpq/include)
set(SOURCES
        main.cpp
        src/BuildingTable.cpp
        include/StructureTable.h
        src/StructureTable.cpp
        src/StructureTable.h
)

add_executable(TeamP ${SOURCES})


link_directories(/opt/homebrew/opt/libpq/lib)

target_link_libraries(TeamP PRIVATE /opt/homebrew/opt/libpq/lib/libpq.dylib)