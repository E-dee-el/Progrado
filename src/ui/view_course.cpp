#include"view_course.h"
#include"DBConnector.h"
#include<iostream>

using namespace Progrado;
using namespace Progrado::UI;
using namespace DB;


view_course::~view_course() {}

void view_course::print_instructions()const
{
    std::cout <<
    "\t\tVIEW COURSES\n"
    "\n"
    "select which courses you want to view\n"
    "The output will be in a file named 'results.csv' in the current working directory\n"
    "options:\n" 
    "0.  Freshman Fall Courses\n"
    "1.  Freshman J-term Courses\n"
    "2.  Freshman Spring Courses\n"
    "3.  Freshman Summer Courses\n"
    "4.  Sophomore Fall Courses\n"
    "5.  Sophomore  J-term Courses\n"
    "6.  Sophomore  Spring Courses\n"
    "7.  Sophompre Summer Courses\n"
    "8.  Junior Fall Courses\n"
    "9.  Junior J-term Courses\n"
    "10. Junior Spring Courses\n"
    "11. Junior Summer Courses\n"
    "12. Senior Fall Courses\n"
    "13. Senior Spring Courses\n"
    "14. All Courses\n";
    std::cout << "\n";
    std::cout << "> ";
        
}

void view_course::execute()const
{
    int choice;
    std::cin >> choice;
    if(choice == 14)
    {
            auto course_matrix = DBConnector::getScheduleSummary();
            for(auto c_list: course_matrix)
            {
                for(auto crc: c_list)
                {
                    crc->displayCourse();
                }
            }
    }
    else
    {
            auto course_list = DBConnector::getCoursesMatching(choice);

            for(auto _course_: course_list)
            {
                _course_->displayCourse();
            }
                
    }
    
}