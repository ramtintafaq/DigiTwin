#include "StructureTable.h"
#include <iostream>

int StructureTable::create(PGconn* conn) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS structures (
            id SERIAL PRIMARY KEY,
            building_id INTEGER NOT NULL,
            name TEXT NOT NULL,
            FOREIGN KEY(building_id) REFERENCES buildings(id) ON DELETE CASCADE
        );
    )";

    PGresult* res = PQexec(conn, sql);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Failed to create structures table: " << PQerrorMessage(conn);
        PQclear(res);
        return 1;
    }

    std::cout << "Structures table created successfully.\n";
    PQclear(res);
    return 0;
}