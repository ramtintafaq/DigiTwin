#ifndef STRUCTURETABLE_H
#define STRUCTURETABLE_H

#include <libpq-fe.h>

class StructureTable {
public:
    static int create(PGconn* conn);
};

#endif // STRUCTURETABLE_H