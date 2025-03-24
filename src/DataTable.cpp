#include "../include/DataTable.h"
#include <iostream>
#include <sqlite3.h>

int DataTable::create(sqlite3* db) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS data (
            data_id INTEGER PRIMARY KEY AUTOINCREMENT,
            sensor_id INT,
            timestamp TIMESTAMP NOT NULL,
            data_value TEXT NOT NULL,
            FOREIGN KEY (sensor_id) REFERENCES SensorTable(id)
        );
    )";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating data table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return rc;
}
