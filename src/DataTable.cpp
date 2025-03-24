#include "../include/DataTable.h"
#include <iostream>
#include <sqlite3.h>

int DataTable::create(sqlite3* db) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS data (
            data_id INT PRIMARY KEY AUTO_INCREMENT,
            id INT,
            timestamp TIMESTAMP NOT NULL,
            data_value DOUBLE NOT NULL,
            FOREIGN KEY (id) REFERENCES SensorTable(id),
            INDEX(timestamp)
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
