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