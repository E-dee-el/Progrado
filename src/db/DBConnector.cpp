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
m_ptr_progradoDatabase(nullptr) 
{
    // open DB connection
    sqlite3_initialize();
    int rc = sqlite3_open_v2(Progrado::DB_LOCATION.c_str(),
                             &m_ptr_progradoDatabase,
                             SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
                             NULL
                             );

    if(rc != SQLITE_OK)
    {
        std::cout << "Progrado encountered an error and has to quit: Couldn't open database\n";
        exit(-1);
    }

}

DB::DBConnector::~DBConnector()
{
    sqlite3_close(m_ptr_progradoDatabase);
    sqlite3_shutdown(); // shut down sqlite3 engine
}


int DB::DBConnector::addNewUser(const Progrado::User& t_user)
{   
   sqlite3_stmt *addUserStmt = nullptr;

    // prepare SQL create statement
   int rc_create = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                       Progrado::NEW_USER_TABLE.c_str(),
                        -1,
                        &addUserStmt,
                        nullptr);

    if(rc_create != SQLITE_OK){ return Progrado::FAIL;}

    
    if(sqlite3_step(addUserStmt) != SQLITE_DONE){ return Progrado::FAIL; }

    // prepare to insert new user details

    addUserStmt = nullptr; // reset addUserStmt to null
    int rc_insert = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                                        Progrado::INSERT_NEW_USER.c_str(),
                                        -1,            // negative parameter makes sqlite calculate addUserStmt size automatically
                                        &addUserStmt,
                                        nullptr);

     if(rc_insert != SQLITE_OK){ return Progrado::FAIL; }


    // bind the values here
    sqlite3_bind_text(addUserStmt, sqlite3_bind_parameter_index(addUserStmt, ":lastName"),
                        t_user.get_lastName().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(addUserStmt, sqlite3_bind_parameter_index(addUserStmt, ":firstName"),
                        t_user.get_firstName().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(addUserStmt, sqlite3_bind_parameter_index(addUserStmt, ":yearInCollege"),
                        t_user.get_yearInCollege().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(addUserStmt, sqlite3_bind_parameter_index(addUserStmt, ":userName"),
                        t_user.get_userName().c_str(), -1, SQLITE_STATIC);  

    sqlite3_bind_text(addUserStmt, sqlite3_bind_parameter_index(addUserStmt, ":password"),
                        t_user.get_password().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(addUserStmt, sqlite3_bind_parameter_index(addUserStmt, ":major"),
                        t_user.get_major().c_str(), -1, SQLITE_STATIC);   

    sqlite3_bind_text(addUserStmt, sqlite3_bind_parameter_index(addUserStmt, ":minor"),
                        t_user.get_minor().c_str(), -1, SQLITE_STATIC);  

    // execute statement                                   
     if(sqlite3_step(addUserStmt) != SQLITE_DONE){ return Progrado::FAIL; }

    // finalize statement and release resources
     sqlite3_finalize(addUserStmt);
     
     return Progrado::SUCCESS;
      
}

bool DB::DBConnector::coursesTableExists()
{
    // call this function to check if the courses table is empty

    sqlite3_stmt* coursesExists = nullptr;
    bool exists =  false;

    int rc_exists = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                        Progrado::CHECK_IF_COURSE_TABLE_EXISTS.c_str(),
                        -1,
                        &coursesExists,
                        nullptr);

    // yes, table doesnot exits
    if(rc_exists != SQLITE_OK) {return Progrado::FAIL; }

    int rc_exec = sqlite3_step(coursesExists);

    if(rc_exec != SQLITE_DONE) {exists = false;}
    else {exists = true;}

    sqlite3_finalize(coursesExists);

    return exists;
}

int DB::DBConnector::createCoursesTable()
{
    sqlite3_stmt* createCoursesTable = nullptr;

    int rc_create = sqlite3_prepare_v2(  m_ptr_progradoDatabase,
                                         Progrado::CREATE_COURSE_TABLE.c_str(),
                                         -1,
                                         &createCoursesTable,
                                         nullptr );

    if(rc_create != SQLITE_OK) { return Progrado::FAIL; } 

    int rc_exec = sqlite3_step(createCoursesTable);

    if(rc_exec != SQLITE_DONE) { return Progrado::FAIL; }   

    sqlite3_finalize(createCoursesTable);

    return Progrado::SUCCESS;   

}

int DB::DBConnector::addCourse(const Progrado::Course& t_course)
{
    // must be guaranteed that course table is not empty. Verify from UI class
    sqlite3_stmt* addCourseStmt = nullptr;

    int rc_insert = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                    Progrado::INSERT_NEW_COURSE.c_str(),
                    -1,
                    &addCourseStmt,
                     nullptr);

    if(rc_insert != SQLITE_OK){return Progrado::FAIL;}


    // binding the values

    sqlite3_bind_text(addCourseStmt, 
                    sqlite3_bind_parameter_index(addCourseStmt, ":courseName"),
                    t_course.getCourseName().c_str(), -1, SQLITE_STATIC );


    sqlite3_bind_text(addCourseStmt, 
                    sqlite3_bind_parameter_index(addCourseStmt, ":semesterOffered"),
                    t_course.getSemesterOffered().c_str(), -1, SQLITE_STATIC );

    sqlite3_bind_text(addCourseStmt, 
                    sqlite3_bind_parameter_index(addCourseStmt, ":courseId"),
                    t_course.getCourseId().c_str(), -1, SQLITE_STATIC );                

    sqlite3_bind_text(addCourseStmt, 
                    sqlite3_bind_parameter_index(addCourseStmt, ":courseType"),
                    t_course.getCourseType().c_str(), -1, SQLITE_STATIC );

    sqlite3_bind_int(addCourseStmt,
                    sqlite3_bind_parameter_index(addCourseStmt, ":numCredits"),
                    t_course.getNumCredits());


    int rc_exec = sqlite3_step(addCourseStmt);

    if(rc_exec != SQLITE_DONE){return Progrado::FAIL;}

    sqlite3_finalize(addCourseStmt);

    return Progrado::SUCCESS;
        
}

/// UPDATE A COURSE
int DB::DBConnector::updateCourse(const Progrado::Course& t_oldCourse,
                                   const Progrado::Course& t_newCourse)
{
    sqlite3_stmt* updateCourseStmt = nullptr;

    int rc_update = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                       Progrado::UPDATE_COURSE.c_str(),
                       -1,
                       &updateCourseStmt,    
                        nullptr);

    if(rc_update != SQLITE_OK) {return Progrado::FAIL;}

    //oldcourse
    sqlite3_bind_text(updateCourseStmt, 
                    sqlite3_bind_parameter_index(updateCourseStmt, ":courseName"),
                    t_oldCourse.getCourseName().c_str(), -1, SQLITE_STATIC );


    sqlite3_bind_text(updateCourseStmt, 
                    sqlite3_bind_parameter_index(updateCourseStmt, ":semesterOffered"),
                    t_oldCourse.getSemesterOffered().c_str(), -1, SQLITE_STATIC );

    sqlite3_bind_text(updateCourseStmt, 
                    sqlite3_bind_parameter_index(updateCourseStmt, ":courseId"),
                    t_oldCourse.getCourseId().c_str(), -1, SQLITE_STATIC );                

    sqlite3_bind_text(updateCourseStmt, 
                    sqlite3_bind_parameter_index(updateCourseStmt, ":courseType"),
                    t_oldCourse.getCourseType().c_str(), -1, SQLITE_STATIC );

    sqlite3_bind_int(updateCourseStmt,
                    sqlite3_bind_parameter_index(updateCourseStmt, ":numCredits"),
                    t_oldCourse.getNumCredits());                   
    
    // old course for WHERE clause
    sqlite3_bind_text(updateCourseStmt, 
                    sqlite3_bind_parameter_index(updateCourseStmt, ":oldCourseId"),
                    t_newCourse.getCourseType().c_str(), -1, SQLITE_STATIC );

    //execute
    int rc_exec = sqlite3_step(updateCourseStmt);

    if(rc_exec!= SQLITE_DONE){return Progrado::FAIL;}

    sqlite3_finalize(updateCourseStmt);

    return Progrado::SUCCESS;   
}

//CAUTION: CALL WITH CARE | DELETE A COURSE  
int DB::DBConnector::removeCourse(const Progrado::Course& t_course)
{   
    
    sqlite3_stmt* removeCourseStmt = nullptr;

    int rc_delete = sqlite3_prepare_v2(m_ptr_progradoDatabase,
                       Progrado::REMOVE_COURSE.c_str(),
                       -1,
                       &removeCourseStmt,    
                        nullptr);

    if(rc_delete != SQLITE_OK) {return Progrado::FAIL;}

    // bind
    sqlite3_bind_text(removeCourseStmt,
                     sqlite3_bind_parameter_index(removeCourseStmt, ":courseId"),
                     t_course.getCourseId().c_str(),
                     -1,
                     SQLITE_STATIC);

    // execute
    int rc_exec = sqlite3_step(removeCourseStmt);

    if(rc_exec != SQLITE_DONE) {return Progrado::FAIL;}

    return Progrado::SUCCESS;                 
}