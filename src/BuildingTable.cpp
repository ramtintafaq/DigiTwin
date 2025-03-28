#include "BuildingTable.h"
#include <iostream>
#include <libpq-fe.h>
int BuildingTable::create(PGconn* conn) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS buildings (
            id SERIAL PRIMARY KEY,
            name TEXT NOT NULL
        );
    )";

    PGresult* res = PQexec(conn, sql);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Create table failed: " << PQerrorMessage(conn);
        PQclear(res);
        return 1;
    }

    PQclear(res);
    return 0;
}
