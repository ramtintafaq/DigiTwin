#include "../include/BuildingTable.h"
#include <iostream>
#include <sqlite3.h>

int BuildingTable::create(sqlite3* db) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS buildings (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL
        );
    )";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating buildings table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return rc;
}