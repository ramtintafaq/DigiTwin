cmake_minimum_required(VERSION 3.20)
project(Team)

set(CMAKE_CXX_STANDARD 20)

# Add include and source directories
include_directories(include)

# Add source files
set(SOURCES
        main.cpp
        src/BuildingTable.cpp
        include/BuildingTable.h
        include/StructureTable.h
        src/StructureTable.cpp
        include/SensorTable.h
        src/SensorTable.cpp
	include/DataTable.h      
        src/DataTable.cpp         
)

# Create the executable
add_executable(Team ${SOURCES})

# Link SQLite
include_directories(/opt/homebrew/opt/sqlite/include)
link_directories(/opt/homebrew/opt/sqlite/lib)
target_link_libraries(Team PRIVATE sqlite3)