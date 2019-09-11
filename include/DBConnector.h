
#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include"Course.h"
#include"Progrado.h"
#include"User.h"
#include"sqlite3.h"
#include<iostream>
#include<memory>
#include<iomanip>

namespace DB {
class DBConnector;
}

class DB::DBConnector {

public:
    DBConnector();
    ~DBConnector();
    static bool courseAlreadyExists(const Progrado::Course& t_course);
    static bool verifyUserCredentials(const std::string& t_uname, const std::string& t_pword);
    static bool userTableExists();
    static bool coursesTableExists();
    static void createUserTable(); 
    static void addNewUser(const Progrado::User& t_user);
    static void modifyUserDetails(const Progrado::User&);
    static void createCoursesTable();
    static bool addCourse(const Progrado::Course&);
    static bool updateCourse(const std::string& t_OldCourseName, const Progrado::Course& t_newCourse);
    static void removeCourse(const Progrado::Course& t_course);
    static std::vector<std::string> retrieveUserDetails(); 
    static Progrado::Course searchCourse(const std::string& t_search_term);
    static std::vector< std::shared_ptr<Progrado::Course> >
            getCoursesMatching(const int t_flag); // Argument is a type of Terms, from enum Term in namespace Progrado
    static std::vector < std::vector< std::shared_ptr<Progrado::Course> > >
            getScheduleSummary(); /*the foll. returns a vector of vectors (i.e. a 2d vector)
                          of smart pointers to course objects*/

private:
    static sqlite3* m_ptr_progradoDatabase; // sqlite3 DB connection handler
};

#endif //endif