#ifndef SENSORDATATABLE_H
#define SENSORDATATABLE_H

#include <libpq-fe.h>

class SensorDataTable {
public:
    static int create(PGconn* conn);
};

#endif // SENSORDATATABLE_H
