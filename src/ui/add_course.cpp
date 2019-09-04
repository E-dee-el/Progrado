
#include"add_course.h"
#include"DBConnector.h"
#include"Course.h"
#include<iostream>
#include<cstdlib>
#include<string>

using namespace Progrado::UI;


add_course::~add_course(){}

void add_course::print_instructions()const
{
    std::cout << 
    "ADD COURSE\n"
    "============================\n"
    "Please enter the following details for the course you want to add\n"
    "type \"return\" to go back to home\n";
}

void add_course::execute()const
{   
    std::string response = "yes";

    while(response == "yes" || response == "y")
    {
        std::string course_name, course_id, semester, year, course_type;
        int num_credits;

        std::cout << "Course Name: ";
        std::getline(std::cin, course_name);

        std::cout << "Course ID: ";
        std::getline(std::cin, course_id);

        std::cout << "Semester: ";
        std::getline(std::cin, semester);

        std::cout << "Year: ";
        std::getline(std::cin, year);

        std::cout << "Course Type: ";
        std::getline(std::cin, course_type);

        std::cout << "Credits: ";
        std::cin >> num_credits;
        std::cin.ignore();

        auto course = std::unique_ptr<Course>(new Course(course_name, course_id,
                                        course_type, semester, 
                                        year, num_credits));

        DB::DBConnector::addCourse(*course); /*add a course to the database*/

        std::cout << "Do you want to add another course? [yes/no]\n";
        std::getline(std::cin, response);

    }
                                           
}