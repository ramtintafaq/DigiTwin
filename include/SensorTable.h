#ifndef SENSORTABLE_H
#define SENSORTABLE_H

#include <sqlite3.h>

class SensorTable {
public:
    static int create(sqlite3* db);
};

#endif