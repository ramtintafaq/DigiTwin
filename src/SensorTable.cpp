#include "SensorTable.h"
#include <iostream>

int SensorTable::create(PGconn* conn) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS sensors (
            id SERIAL PRIMARY KEY,
            name TEXT NOT NULL,
            type TEXT NOT NULL,
            building_id INTEGER NOT NULL,
            structure_id INTEGER NOT NULL,
            tags TEXT[],
            FOREIGN KEY (building_id) REFERENCES buildings(id) ON DELETE CASCADE,
            FOREIGN KEY (structure_id) REFERENCES structures(id) ON DELETE CASCADE
        );
    )";

    PGresult* res = PQexec(conn, sql);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Failed to create sensors table: " << PQerrorMessage(conn);
        PQclear(res);
        return 1;
    }

    std::cout << "Sensors table created successfully.\n";
    PQclear(res);
    return 0;
}
