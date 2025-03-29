#include "SensorDataTable.h"
#include <iostream>

int SensorDataTable::create(PGconn* conn) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS sensor_data (
            id SERIAL PRIMARY KEY,
            sensor_id INTEGER NOT NULL,
            timestamp TIMESTAMP DEFAULT NOW(),
            value TEXT NOT NULL,
            FOREIGN KEY (sensor_id) REFERENCES sensors(id) ON DELETE CASCADE
        );
    )";

    PGresult* res = PQexec(conn, sql);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Failed to create sensor_data table: " << PQerrorMessage(conn);
        PQclear(res);
        return 1;
    }

    std::cout << "Sensor data table created successfully.\n";
    PQclear(res);
    return 0;
}
