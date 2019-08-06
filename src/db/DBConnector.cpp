/*
**************************************
*************PROGRADO*****************
**************************************
DBConnector Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"DBConnector.h"

DB::DBConnector::DBConnector():
m_ptr_progradoDatabase(NULL) // using NULL here instead of nullptr because we don't know
                            // the possible consequences (we're dealing with C code)
{
    // open DB connection
    sqlite3_initialize();
    int rc = sqlite3_open_v2(Progrado::PROGRADO_DB_LOCATION,
                             &m_ptr_progradoDatabase,
                             SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
                             NULL
                             );

    if(rc != SQLITE_OK)
    {
        //error and exit
        exit(-1);
    }

}

DB::DBConnector::~DBConnector()
{
    sqlite3_close(m_ptr_progradoDatabase);
    sqlite3_shutdown(); // shut down sqlite3 engine
}


void DB::DBConnector::addNewUser(const Progrado::User& t_user)
{   
    sqlite3_stmt *stmt = nullptr;

    // prepare SQL create statement
   int rc_create = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                       Progrado::PROGRADO_NEW_USER_TABLE,
                        -1,
                        &stmt,
                        NULL);

    if(rc_create != SQLITE_OK){/*/ error */ return; }

    
    if(sqlite3_step(stmt) != SQLITE_DONE){/*/ error */ return;}

    // prepare to insert new user details

    stmt = nullptr; // reset stmt to null
    int rc_insert = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                                        Progrado::PROGRADO_INSERT_NEW_USER,
                                        -1,            // negative parameter makes sqlite calculate stmt size automatically
                                        &stmt,
                                        NULL);

     if(rc_insert != SQLITE_OK){/*/ send error */ return; }


    // bind the values here
    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":lastName"),
                        t_user.get_lastName().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":firstName"),
                        t_user.get_firstName().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":yearInCollege"),
                        t_user.get_yearInCollege().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":userName"),
                        t_user.get_userName().c_str(), -1, SQLITE_STATIC);  

    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":password"),
                        t_user.get_password().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":major"),
                        t_user.get_major().c_str(), -1, SQLITE_STATIC);   

    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":minor"),
                        t_user.get_minor().c_str(), -1, SQLITE_STATIC);  

    // execute statement                                   
     if(sqlite3_step(stmt) != SQLITE_DONE){/*/ send error */ return;}

    // finalize statement
     sqlite3_finalize(stmt);
      
}


void DB::DBConnector::addCourse(const Progrado::Course& t_course)
{

}

void DB::DBConnector::updateCourse(const Progrado::Course& t_oldCourse,
                                   const Progrado::Course& t_newCourse)
{

}

void DB::DBConnector::removeCourse(const Progrado::Course& t_course)
{

}