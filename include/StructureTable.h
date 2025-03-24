#ifndef STRUCTURETABLE_H
#define STRUCTURETABLE_H

#include <sqlite3.h>

class StructureTable {
public:
    static int create(sqlite3* db);
};

#endif