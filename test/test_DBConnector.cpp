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
#include<cstring>


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

    // bind lastname

    // t_user.get_lastName returns a temporary and the results of c_str is
    // only valid throughout the lifetime of the temporary/ 
    // end of the full expression (i.e. semi colon)

    // bind last Name
    std::string str_last_name = t_user.get_lastName();
    const char* last_name = str_last_name.c_str();

    sqlite3_bind_text
    (addUserStmt,
    sqlite3_bind_parameter_index(addUserStmt, ":lastName"),
    last_name,
    -1, 
    SQLITE_STATIC
    );

    // bind first name
    std::string str_first_name = t_user.get_firstName();
    const char* first_name = str_first_name.c_str();

    sqlite3_bind_text
    (addUserStmt,
    sqlite3_bind_parameter_index(addUserStmt, ":firstName"),
    first_name,
    -1,
    SQLITE_STATIC
    );

    // bind year in college
    std::string str_year = t_user.get_yearInCollege();
    const char* year_in_college = str_year.c_str();

    sqlite3_bind_text
    (addUserStmt,
    sqlite3_bind_parameter_index(addUserStmt, ":yearInCollege"),
    year_in_college,
    -1,
    SQLITE_STATIC
    );

    // bind username
    std::string str_user_name = t_user.get_userName();
    const char* user_name = str_user_name.c_str();

    sqlite3_bind_text
    (addUserStmt,
     sqlite3_bind_parameter_index(addUserStmt, ":userName"),
     user_name,
    -1,
    SQLITE_STATIC
    );

    // bind password
    std::string str_pwd = t_user.get_password();
    const char* password = str_pwd.c_str(); 

    sqlite3_bind_text
    (addUserStmt,
    sqlite3_bind_parameter_index(addUserStmt, ":password"),
    password,
    -1,
    SQLITE_STATIC
    );
    // bind major
    std::string str_major = t_user.get_major();
    const char* major = str_major.c_str();

    sqlite3_bind_text
    (addUserStmt,
    sqlite3_bind_parameter_index(addUserStmt, ":major"),
    major,
    -1,
    SQLITE_STATIC);   

    // bind minor
    std::string str_minor = t_user.get_minor();
    const char* minor = str_minor.c_str();

    sqlite3_bind_text
    (addUserStmt,
     sqlite3_bind_parameter_index(addUserStmt, ":minor"),
    minor,
    -1,
    SQLITE_STATIC
    );  


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

    // bind course name
    std::string str_course_name =  t_course.getCourseName();
    const char* course_name = str_course_name.c_str();

    sqlite3_bind_text
    (
    addCourseStmt, 
    sqlite3_bind_parameter_index(addCourseStmt, ":courseName"),
    course_name,
     -1,
    SQLITE_STATIC 
    );
    //bind semester
    std::string str_sem =  t_course.getSemesterOffered();
    const char* semester = str_sem.c_str();

    sqlite3_bind_text
    (
    addCourseStmt, 
    sqlite3_bind_parameter_index(addCourseStmt, ":semesterOffered"),
    semester,
    -1,
    SQLITE_STATIC
    );


    // bind course Id
    std::string str_course_id =  t_course.getCourseId();
    const char* course_id = str_course_id.c_str();

    sqlite3_bind_text
    (
    addCourseStmt, 
    sqlite3_bind_parameter_index(addCourseStmt, ":courseId"),
    course_id,
    -1,
    SQLITE_STATIC
    );                

    //bind course type
    std::string str_course_type =  t_course.getCourseType();
    const char* course_type = str_course_type.c_str();

    sqlite3_bind_text
    (
    addCourseStmt, 
    sqlite3_bind_parameter_index(addCourseStmt, ":courseType"),
    course_type,
    -1,
    SQLITE_STATIC
    );

    // bind num credits
    sqlite3_bind_int
    (
     addCourseStmt,
     sqlite3_bind_parameter_index(addCourseStmt, ":numCredits"),
     t_course.getNumCredits()
    );


    int rc_exec = sqlite3_step(addCourseStmt);

    if(rc_exec != SQLITE_DONE){return Progrado::FAIL;}

    sqlite3_finalize(addCourseStmt);

    return Progrado::SUCCESS;
        
}

/// UPDATE A COURSE : CAUTION CALL WITH CARE
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

    // bind course name
    std::string str_new_course_name = t_newCourse.getCourseName();
    const char* new_course_name = str_new_course_name.c_str();

    sqlite3_bind_text
    (
    updateCourseStmt, 
    sqlite3_bind_parameter_index(updateCourseStmt, ":courseName"),
    new_course_name,
    -1,
    SQLITE_STATIC
    );

    // bind semester
    std::string str_new_sem = t_newCourse.getSemesterOffered();
    const char* new_sem = str_new_sem.c_str();

    sqlite3_bind_text
    (
    updateCourseStmt, 
    sqlite3_bind_parameter_index(updateCourseStmt, ":semesterOffered"),
    new_sem,
    -1,
    SQLITE_STATIC
    );

    // bind course id
    std::string str_new_course_id = t_newCourse.getCourseId();
    const char* new_course_id = str_new_course_id.c_str();
    sqlite3_bind_text
    (
    updateCourseStmt, 
    sqlite3_bind_parameter_index(updateCourseStmt, ":courseId"),
    new_course_id,
    -1,
    SQLITE_STATIC
    );                

    // bind course type
    std::string str_new_course_type = t_newCourse.getCourseType();
    const char* new_course_type = str_new_course_type.c_str();


    sqlite3_bind_text
    (
    updateCourseStmt, 
    sqlite3_bind_parameter_index(updateCourseStmt, ":courseType"),
    new_course_type,
    -1,
    SQLITE_STATIC
    );

    // bind num credits
    sqlite3_bind_int
    (
    updateCourseStmt,
    sqlite3_bind_parameter_index(updateCourseStmt, ":numCredits"),
    t_oldCourse.getNumCredits()
    );                   
    
    // old course for WHERE clause
    std::string str_old_course_id =  t_oldCourse.getCourseId();
    const char* old_course_id = str_old_course_id.c_str();

    sqlite3_bind_text
    (
    updateCourseStmt, 
    sqlite3_bind_parameter_index(updateCourseStmt, ":OldCourseId"),
    old_course_id,
    -1,
    SQLITE_STATIC
    );

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

    // bind courseid for WHERE clause
    std::string str_course_id =  t_course.getCourseId();
    const char* course_id = str_course_id.c_str();

    sqlite3_bind_text
    (
    removeCourseStmt,
    sqlite3_bind_parameter_index(removeCourseStmt, ":courseId"),
    course_id,
    -1,
    SQLITE_STATIC
    );

    // execute
    int rc_exec = sqlite3_step(removeCourseStmt);

    if(rc_exec != SQLITE_DONE) {return Progrado::FAIL;}

    return Progrado::SUCCESS;                 
}