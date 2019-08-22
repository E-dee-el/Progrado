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
#include<iostream>



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

try{
// create DBConn with smart pointer
auto DB_ptr = std::unique_ptr<DB::DBConnector>(new DB::DBConnector());

DB_ptr->createCoursesTable();

DB_ptr->addNewUser(*user_ptr);

//login:
std::string uname;
std::string pword;

    std::cout << "Enter username: ";
    std::getline(std::cin, uname);
    std::cout << "Enter password: ";
    std::getline(std::cin, pword);

while (!DB_ptr->verifyUserCredentials(uname, pword))
{

    std::cout << "Username and/or password incorrect\n";
    std::cout << "Enter username: ";
    std::getline(std::cin, uname);
    std::cout << "Enter password: ";
    std::getline(std::cin, pword);

    


}


//std::cout << DB_ptr->removeCourse(*course_ptr) << std::endl;

std::string ansr = "yes";

while (ansr == "yes")
{
    std::vector<std::string> add_course_vector(5);
    int l_credits = 0;


    using namespace Progrado;
    std::cout << "Enter course details for course you want to add\n";
    std::cout << "Course Name: ";  std::getline(std::cin, add_course_vector[courseName]);
    std::cout << "Course ID: "; std::getline(std::cin, add_course_vector[courseId]);
    std::cout << "Course Type: "; std::getline(std::cin, add_course_vector[courseType]);
    std::cout << "Semester: "; std::getline(std::cin, add_course_vector[semesterOffered]);
    std::cout << "Year: "; std::getline(std::cin, add_course_vector[yearOffered]);
    std::cout << "Credits: "; std::cin >> l_credits;

    if(l_credits == 0)
    {
         bool k = DB_ptr->addCourse(Progrado::Course(add_course_vector));
         if(!k) 
       {
           std::cout << "Oops! seems the course you want to add already exists. Do you want to try again?[yes/no]\n";
            std::string ans;
            std::cin >> ans;
            std::cin.ignore();
            if(ans == "yes") continue;
            else break;

       }


    }
    else 
    {
       bool z = DB_ptr->addCourse(Progrado::Course(add_course_vector, l_credits));

       if(!z) 
       {
           std::cout << "Oops! seems the course you want to add already exists. Do you want to try again?[yes/no]\n";
            std::string ans;
            std::cin >> ans;
            if(ans == "yes") continue;
            else break;
           
       }

    }   
    
    std::cout << "Add another course? [yes/no] ";
    std::cin >> ansr;
    std::cin.ignore();   
    
}



// v is a vector of smart pointers to Course objects
std::vector<std::shared_ptr<Progrado::Course> > v;

v = DB_ptr->getCoursesMatching(Progrado::SOPH_SPRING);
 
for(int i = 0; i < v.size(); i++)
{
    v[i]->displayCourse();
}
/*
auto _v = DB_ptr->getScheduleSummary();

for(int j = 0; j < _v.size(); j++)
{
    for(int i = 0; i < _v[j].size(); i++)
{
    _v[j][i]->displayCourse();
}
}*/
//////////////////////////
}
catch (std::runtime_error a)
{
    std::cout << a.what() ;
}

return 0;
}