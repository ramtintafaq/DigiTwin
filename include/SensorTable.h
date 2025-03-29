#ifndef SENSORTABLE_H
#define SENSORTABLE_H

#include <libpq-fe.h>

class SensorTable {
public:
    static int create(PGconn* conn);
};

#endif // SENSORTABLE_H
