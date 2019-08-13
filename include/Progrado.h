
// Progrado "global" constants, functions declared here
#ifndef PROGRADO
#define PROGRADO

#include<string>
namespace Progrado
{

    const int FAIL = -1; // return this on any failed procedures
    const int SUCCESS = 0;     // return this on any successful procedures   


    // since some of these strings are very long. We dont want to even contemplate stackoverflow, 
    //hence we use const std::string 
    //instead of const char* since it manages its resources on the heap

    const std::string DB_LOCATION = "progrado.db"; 

    const std::string CHECK_IF_USER_TABLE_EXISTS = "SELECT * FROM user"; 
    const std::string NEW_USER_TABLE = 
    "CREATE TABLE IF NOT EXISTS user(lastName TEXT,"
                               "firstName TEXT,"
                               "yearInCollege TEXT,"
                               "userName TEXT PRIMARY KEY,"
                               "password TEXT,"
                               "major TEXT,"
                               "minor TEXT)";
    const std::string INSERT_NEW_USER = 
    "INSERT INTO user (lastName, firstName, yearInCollege, userName, password, major, minor) "
    " VALUES(:lastName, :firstName, :yearInCollege, :userName, :password, :major, :minor)";                           


    /****** INPUTTING***/
    // use this to check if the user hasn't added any courses
    const std::string CHECK_IF_COURSE_TABLE_EXISTS = "SELECT * FROM courses";  

    // use this to create a new course table
    const std::string  CREATE_COURSE_TABLE = "CREATE TABLE IF NOT EXISTS courses(courseName TEXT, semesterOffered TEXT,"
                                       "yearOffered TEXT, courseId TEXT PRIMARY KEY, courseType TEXT, numCredits INTEGER)";   

    // use this to insert a new course
    const std::string INSERT_NEW_COURSE = "INSERT INTO courses (courseName, semesterOffered, yearOffered, courseId, courseType, numCredits)" 
                                    " VALUES(:courseName, :semesterOffered, :yearOffered, :courseId, :courseType, :numCredits)";
    // use this to update an existing course
    const std::string UPDATE_COURSE = "UPDATE courses SET courseName = :courseName, "
                                "semesterOffered = :semesterOffered, courseId = :courseId, courseType = :courseType,"
                                " numCredits = :numCredits "
                                " WHERE courseId = :OldCourseId";  

    // use this to delete an existing course, HANDLE WITH CARE                                                          
    const std::string REMOVE_COURSE = "DELETE FROM courses WHERE courseId = :courseId";


    /****** OUTPUTTING***/

    const std::string GET_ALL_COURSES = "SELECT courseName AS Name, semesterOffered AS TERM, yearOffered AS YEAR, courseId as ID, "
    "courseType AS CATEGORY, numCredits AS CREDITS FROM courses";

}

#endif
