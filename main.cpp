#include <iostream>
#include <sqlite3.h>
#include "include/BuildingTable.h"
#include "include/StructureTable.h"
#include "include/SensorTable.h"
#include "include/DataTable.h"

int main() {
    sqlite3* db;

    // Open (or create) the database
    int rc = sqlite3_open("sensor_database.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    } else {
        std::cout << "Database opened successfully.\n";
    }

    // Create tables
    if (BuildingTable::create(db) == SQLITE_OK)
        std::cout << "Buildings table created.\n";

    if (StructureTable::create(db) == SQLITE_OK)
        std::cout << "Structures table created.\n";

    if (SensorTable::create(db) == SQLITE_OK)
        std::cout << "Sensors table created.\n";

    if (DataTable::create(db) == SQLITE_OK)
        std::cout << "Data table created.\n";


    // Close the database
    sqlite3_close(db);
    return 0;
}
