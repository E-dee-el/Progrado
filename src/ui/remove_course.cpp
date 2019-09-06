#include "remove_course.h"   
#include "DBConnector.h"
#include <iostream>
#include <string>

using namespace Progrado;
using namespace Progrado::UI;

remove_course::~remove_course() {}

void remove_course::print_instructions()const
{
    std::cout << "\t\tREMOVE COURSE\n"
                 "\t===============\n"
                 "Please enter the name of the course you would like to remove\n\n";
}

void remove_course::execute()const
{
    std::string response = "yes";

    while (response == "yes" || response == "y")
    {
        std::string course_name ;

        std::cout << "course name: \n"; 
        std::getline(std::cin, course_name);

        auto remove_course_object = std::unique_ptr<Course>(new Course(course_name,
                                                                        "","","","") ); 

        DB::DBConnector::removeCourse(*remove_course_object); 

        std::cout << "Do you wish to remove another course? [yes/no]\n";

        std::getline(std::cin, response);
    } 
}