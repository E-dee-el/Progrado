
// Progrado "global" constants, functions declared here
//// DO NOT EDIT THE STRINGS DECLARED HERE!
#ifndef PROGRADO
#define PROGRADO

#include<string>
#include<iostream>
#include<chrono>
#include<thread>
namespace Progrado
{

const int FAIL = -1; // return this on any failed procedures
const int SUCCESS = 1;
const int PROG_EXIT = 0;
const bool FALSE = false;
const bool TRUE = true;    // return this on any successful procedures

// PROGRADO GLOBAL ENUMS

enum Term
{
    FRESHMAN_FALL,
    FRESHMAN_JTERM,
    FRESHMAN_SPRING,
    FRESHMAN_SUMMER,
    SOPH_FALL,
    SOPH_JTERM,
    SOPH_SPRING,
    SOPH_SUMMER,
    JUNIOR_FALL,
    JUNIOR_JTERM,
    JUNIOR_SPRING,
    JUNIOR_SUMMER,
    SENIOR_FALL,
    SENIOR_SPRING,
    ALL
};

/*it's important that enum CourseDetails stays here, since more than one .cpp file uses it*/
enum CourseDetails {courseName, courseId, semesterOffered, yearOffered,courseType};

const std::string DB_LOCATION = ".progrado.db";

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

// verify user login details

const std::string VERIFY_USER = "SELECT userName, password FROM user WHERE userName = :userName AND password = :password";


/****** INPUTTING***/
// use this to check if the user hasn't added any courses
const std::string CHECK_IF_COURSE_TABLE_EXISTS = "SELECT * FROM courses";

// use this to create a new course table
const std::string  CREATE_COURSE_TABLE = "CREATE TABLE IF NOT EXISTS courses(courseName TEXT, courseId TEXT PRIMARY KEY, semesterOffered TEXT,"
        "yearOffered TEXT,courseType TEXT, numCredits INTEGER)";

// use this to insert a new course
const std::string INSERT_NEW_COURSE = "INSERT INTO courses (courseName,  courseId, semesterOffered, yearOffered,courseType, numCredits)"
                                      " VALUES(:courseName,  :courseId,  :semesterOffered, :yearOffered, :courseType, :numCredits)";
// use this to update an existing course
const std::string UPDATE_COURSE = "UPDATE courses SET courseName = :courseName, "
                                  " courseId = :courseId, semesterOffered = :semesterOffered,courseType = :courseType,"
                                  " numCredits = :numCredits "
                                  " WHERE courseName = :OldCourseName";

// use this to delete an existing course, HANDLE WITH CARE
const std::string REMOVE_COURSE = "DELETE FROM courses WHERE courseId = :courseId";

// verify if course already exists
const std::string VERIFY_COURSE = "SELECT courseId FROM courses WHERE courseId = :courseId";
const std::string SEARCH_COURSE = "SELECT * FROM courses WHERE courseName LIKE :searchTerm";



/****** OUTPUTTING***/

const std::string GET_ALL_COURSES = "SELECT courseName AS Name, semesterOffered AS TERM, yearOffered AS YEAR, courseId as ID, "
                                    "courseType AS CATEGORY, numCredits AS CREDITS FROM courses";

// Getting full schedule


const std::string GET_FRHMN_FALL_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Fall' OR semesterOffered = 'fall' OR semesterOffered = 'FALL') "
    " AND (yearOffered = 'Freshman' OR yearOffered = 'FRESHMAN' OR yearOffered = 'freshman')";

const std::string GET_FRHMN_JTERM_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'J-term' OR semesterOffered = 'J-Term' OR semesterOffered = 'J-TERM' OR "
    " semesterOffered = 'January Term') AND (yearOffered = 'Freshman' OR yearOffered = 'FRESHMAN' OR yearOffered = 'freshman')";
const std::string GET_FRHMN_SPRG_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Spring' OR semesterOffered = 'spring' OR semesterOffered = 'SPRING') "
    " AND (yearOffered = 'Freshman' OR yearOffered = 'FRESHMAN' OR yearOffered = 'freshman')";

const std::string GET_FRHMN_SUMMER_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'summer' OR semesterOffered = 'Summer' OR semesterOffered = 'SUMMER') "
    " AND (yearOffered = 'Freshman' OR yearOffered = 'FRESHMAN' OR yearOffered = 'freshman')";

const std::string GET_SOPH_FALL_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Fall' OR semesterOffered = 'fall' OR semesterOffered = 'FALL') "
    " AND (yearOffered = 'Sophomore' OR yearOffered = 'SOPHOMORE' OR yearOffered = 'sophomore')";

const std::string GET_SOPH_JTERM_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'J-term' OR semesterOffered = 'J-Term' OR semesterOffered = 'J-TERM' OR "
    " semesterOffered = 'January Term') AND (yearOffered = 'Sophomore' OR yearOffered = 'SOPHOMORE' OR yearOffered = 'sophomore')";

const std::string GET_SOPH_SPRG_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Spring' OR semesterOffered = 'spring' OR semesterOffered = 'SPRING') "
    " AND (yearOffered = 'Sophomore' OR yearOffered = 'SOPHOMORE' OR yearOffered = 'sophomore')";

const std::string GET_SOPH_SUMMER_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'summer' OR semesterOffered = 'Summer' OR semesterOffered = 'SUMMER') "
    " AND (yearOffered = 'Sophomore' OR yearOffered = 'SOPHOMORE' OR yearOffered = 'sophomore')";

const std::string GET_JUN_FALL_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Fall' OR semesterOffered = 'fall' OR semesterOffered = 'FALL') "
    " AND (yearOffered = 'Junior' OR yearOffered = 'JUNIOR' OR yearOffered = 'junior')";

const std::string GET_JUN_JTERM_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'J-term' OR semesterOffered = 'J-Term' OR semesterOffered = 'J-TERM' OR "
    " semesterOffered = 'January Term') AND (yearOffered = 'Junior' OR yearOffered = 'JUNIOR' OR yearOffered = 'junior')";

const std::string GET_JUN_SPRG_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Spring' OR semesterOffered = 'spring' OR semesterOffered = 'SPRING')"
    " AND (yearOffered = 'Junior' OR yearOffered = 'JUNIOR' OR yearOffered = 'junior')";

const std::string GET_JUN_SUMMER_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'summer' OR semesterOffered = 'Summer' OR semesterOffered = 'SUMMER') "
    " AND (yearOffered = 'Junior' OR yearOffered = 'JUNIOR' OR yearOffered = 'junior')";

const std::string GET_SEN_FALL_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Fall' OR semesterOffered = 'fall' OR semesterOffered = 'FALL') "
    " AND (yearOffered = 'Senior' OR yearOffered = 'SENIOR' OR yearOffered = 'senior')";

const std::string GET_SEN_SPRG_COURSES =
    "SELECT * FROM COURSES WHERE (semesterOffered = 'Spring' OR semesterOffered = 'spring' OR semesterOffered = 'SPRING')"
    " AND (yearOffered = 'Senior' OR yearOffered = 'SENIOR' OR yearOffered = 'senior')";
const std::string RETRIEVE_USER = 
    "SELECT * FROM user";

void progrado_loading(int n);

}

#endif
