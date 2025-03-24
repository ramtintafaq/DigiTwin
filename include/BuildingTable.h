//
// Created by Ramtin Tafaghodi on 24/03/25.
//

#ifndef BUILDINGTABLE_H
#define BUILDINGTABLE_H

#include <sqlite3.h>
#include <string>

class BuildingTable {
public:
    static int create (sqlite3* db);
};

#endif