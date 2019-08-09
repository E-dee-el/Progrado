///////
/*
**************************************
*************PROGRADO*****************
**************************************
Testing Class DBConn
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */


#include"Course.h"
#include"User.h"
#include"DBConnector.h"
#include<memory>



int main()
{

// create course object with smart pointer
auto course_ptr = std::unique_ptr<Progrado::Course>
(new Progrado::Course("Computer Programming for Engineers", "ENGR-UH 1000","major","Fall"));

auto new_course_ptr = std::unique_ptr<Progrado::Course>
(new Progrado::Course("Computer Programming", "ENGR-UH 1000","Elective","Fall"));
// create user with smart pointer
auto user_ptr = std::unique_ptr<Progrado::User>
(new Progrado::User("Ibrahim",
"Suleiman", "Sophomore","ibrosule",
"Electrical Engineering", "Computer Science", "admin"));

// create DBConn with smart pointer
auto DB_ptr = std::unique_ptr<DB::DBConnector>(new DB::DBConnector());

DB_ptr->createCoursesTable();

DB_ptr->addNewUser(*user_ptr);
DB_ptr->addCourse(*course_ptr);

DB_ptr->updateCourse(*course_ptr, *new_course_ptr);

//////////////////////////



return 0;
}