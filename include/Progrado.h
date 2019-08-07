
// Progrado "global" constants, functions declared here
#ifndef PROGRADO
#define PROGRADO

namespace Progrado
{

    const int FAIL = -1; // return this on any failed procedures
    const int SUCCESS = 0;     // return this on any successful procedures   


    const char* DB_LOCATION = "data/progrado.db"; 
    const char* NEW_USER_TABLE = 
    "CREATE TABLE IF NOT EXISTS user(lastName TEXT,"
                               "firstName TEXT,"
                               "yearInCollege TEXT,"
                               "userName TEXT PRIMARY KEY,"
                               "password TEXT,"
                               "major TEXT,"
                               "minor TEXT)";
    const char* INSERT_NEW_USER = 
    "INSERT INTO user (lastName, firstName, yearInCollege, userName, password, major, minor) "
    " VALUES(:lastName, :firstName, :yearInCollege, :userName, :password, :major, :minor)";                           



    // use this to check if the user hasn't added any courses
    const char* CHECK_IF_COURSE_TABLE_EXISTS = "SELECT * FROM courses";  

    // use this to create a new course table
    const char*  CREATE_COURSE_TABLE = "CREATE TABLE IF NOT EXISTS courses(courseName TEXT, semesterOffered TEXT,"
                                       " courseId TEXT PRIMARY KEY, courseType TEXT, numCredits INTEGER)";   

    const char* INSERT_NEW_COURSE = "INSERT INTO courses" 
                                    " VALUES(:courseName, :semesterOffered, :courseId, :courseType, :numCredits)";
                                    


}

#endif
