#include "StructureTable.h"
#include <iostream>

int StructureTable::create(sqlite3* db) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS structures (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            building_id INTEGER NOT NULL,
            name TEXT NOT NULL,
            FOREIGN KEY(building_id) REFERENCES buildings(id)
        );
    )";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating structures table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return rc;
}