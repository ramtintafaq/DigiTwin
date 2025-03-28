#include <iostream>
#include <libpq-fe.h>
#include "BuildingTable.h"
#include "StructureTable.h"

int main() {
    PGconn* conn = PQconnectdb("host=localhost dbname=digitwin user=ramtin password=7N@p45678911");

    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection failed: " << PQerrorMessage(conn);
        PQfinish(conn);
        return 1;
    }

    std::cout << "Connected to PostgreSQL successfully!\n";
    BuildingTable::create(conn);
    StructureTable::create(conn);

    PQfinish(conn);
    return 0;
}