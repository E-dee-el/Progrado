
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
    static bool courseAlreadyExists(const Progrado::Course&);
    static bool verifyUserCredentials(const std::string&, const std::string&);
    static bool userTableExists();
    static bool coursesTableExists();
    static void createUserTable();
    static void addNewUser(const Progrado::User&);
    static void modifyUserDetails(const Progrado::User&); 
    static void createCoursesTable();
    static bool addCourse(const Progrado::Course&);
    static bool updateCourse(const std::string&, const Progrado::Course&);
    static void removeCourse(const Progrado::Course&);
    static std::vector< std::shared_ptr<Progrado::Course> >
    getCoursesMatching(const int); // Argument is a type of Terms, from enum Term in namespace Progrado
    
 // the foll. returns a vector of vectors (i.e. a 2d vector) of smart pointers to course objects
    static std::vector < std::vector< std::shared_ptr<Progrado::Course> > >
    getScheduleSummary();

    



private: 

sqlite3* m_ptr_progradoDatabase; // sqlite3 DB connection handler


};


#endif //endif