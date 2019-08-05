/*
**************************************
*************PROGRADO*****************
**************************************
DBConnector header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */
#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include"Course.h"

namespace DB{
    class DBConnector;
}

class DB::DBConnector{

public:
    DBConnector();
    ~DBConnector();
    void addCourse(const Progrado::Course&);
    void updateCourse(const Progrado::Course&, const Progrado::Course&);
    void removeCourse(const Progrado::Course&);


private:
// Database connection handler from SQLite C API goes here



};


#endif //endif