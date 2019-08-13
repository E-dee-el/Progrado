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
(new Progrado::Course("Computer Programming for Engineers", "ENGR-UH 1000","major","Fall", "Freshman"));

auto new_course_ptr1 = std::unique_ptr<Progrado::Course>
(new Progrado::Course("Computer Programming", "ENGR-UH 1000","Elective","Fall", "Freshman"));

auto new_course_ptr2 = std::unique_ptr<Progrado::Course>
(new Progrado::Course("Introduction to Computer Science", "CS-UH 1000","Minor","Spring", "Sophomore"));

auto new_course_ptr3 = std::unique_ptr<Progrado::Course>
(new Progrado::Course("Justice In Theory and Practice", "CCOL 1001","Colloquium","Spring", "Freshman"));
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
DB_ptr->addCourse(*new_course_ptr2);
DB_ptr->addCourse(*new_course_ptr3);

DB_ptr->updateCourse(*course_ptr, *new_course_ptr1);
//std::cout << DB_ptr->removeCourse(*course_ptr) << std::endl;

// v is a vector of smart pointers to Course objects
std::vector<std::shared_ptr<Progrado::Course> > v;

v = DB_ptr->getAllCourses();

for(int i = 0; i < v.size(); i++)
{
    v[i]->displayCourse();
}

//////////////////////////

return 0;
}