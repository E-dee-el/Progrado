#include"modify_course.h"
#include"Course.h"
#include"DBConnector.h"
#include<iostream>

using namespace Progrado::UI;

modify_course::~modify_course() {};

void modify_course::print_instructions()const
{
    std::cout <<
              "===================\n"
              "=   MODIFY COURSE =\n"
              "===================\n"
              "Enter the name of the course you want to modify\n";
}

void modify_course::execute()const
{
    std::string response = "yes";

    while(response == "yes" || response == "y")
    {
        std::string course_name, course_id, semester, year, course_type, old_course_name;;
        int num_credits;

        std::getline(std::cin, old_course_name);

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

        DB::DBConnector::updateCourse(old_course_name, *course);

        std::cout << "Do you want to modify another course? [yes/no]\n";
        std::getline(std::cin, response);

    }
}