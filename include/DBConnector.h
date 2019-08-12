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
#include"Progrado.h"
#include"User.h"
#include"sqlite3.h"
#include<iostream>
#include<memory>
#include<iomanip>

namespace DB{
    class DBConnector;
}

class DB::DBConnector{

public:
    DBConnector();
    ~DBConnector();

    bool userTableExists();
    bool coursesTableExists();
    int createUserTable();
    int addNewUser(const Progrado::User&);
    int modifyUserDetails(const Progrado::User&); 
    int createCoursesTable();
    int addCourse(const Progrado::Course&);
    int updateCourse(const Progrado::Course&, const Progrado::Course&);
    int removeCourse(const Progrado::Course&);

    std::vector< std::shared_ptr<Progrado::Course> >
    getAllCourses();



private: 

sqlite3* m_ptr_progradoDatabase; // sqlite3 DB connection handler

};


#endif //endif