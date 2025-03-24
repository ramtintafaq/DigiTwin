#ifndef DATATABLE_H
#define DATATABLE_H

#include <sqlite3.h>
#include <string>

class DataTable {
public:
    static int create (sqlite3* db);
};

#endif
