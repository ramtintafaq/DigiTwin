#include <iostream>
#include <libpq-fe.h>
#include "BuildingTable.h"
#include "StructureTable.h"

std::string loadConnectionString(const std::string& filename);

int main() {
    std::string connStr = loadConnectionString("db.conf");

    PGconn* conn = PQconnectdb(connStr.c_str());

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