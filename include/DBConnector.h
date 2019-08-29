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
    /*change to static methods so an instance is not required*/
    bool courseAlreadyExists(const Progrado::Course&);
    bool verifyUserCredentials(const std::string&, const std::string&);
    bool userTableExists();
    bool coursesTableExists();
    void createUserTable();
    void addNewUser(const Progrado::User&);
    void modifyUserDetails(const Progrado::User&); 
    void createCoursesTable();
    bool addCourse(const Progrado::Course&);
    bool updateCourse(const Progrado::Course&, const Progrado::Course&);
    void removeCourse(const Progrado::Course&);
    std::vector< std::shared_ptr<Progrado::Course> >
    getCoursesMatching(const int); // Argument is a type of Terms, from enum Term in namespace Progrado
    
 // the foll. returns a vector of vectors (i.e. a 2d vector) of smart pointers to course objects
    std::vector < std::vector< std::shared_ptr<Progrado::Course> > >
    getScheduleSummary();

    



private: 

sqlite3* m_ptr_progradoDatabase; // sqlite3 DB connection handler


};


#endif //endif