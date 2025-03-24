#include "SensorTable.h"
#include <iostream>

int SensorTable::create(sqlite3* db) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS sensors (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            type TEXT NOT NULL,
            structure_id INTEGER NOT NULL,
            installation_date TEXT,
            FOREIGN KEY(structure_id) REFERENCES structures(id)
        );
    )";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating sensors table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return rc;
}