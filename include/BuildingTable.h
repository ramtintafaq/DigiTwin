#ifndef BUILDINGTABLE_H
#define BUILDINGTABLE_H

#include <libpq-fe.h>

class BuildingTable {
public:
    static int create(PGconn* conn);
};

#endif