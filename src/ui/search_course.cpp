#include"search_course.h"
#include"DBConnector.h"
#include<iostream>

using namespace Progrado;
using namespace Progrado::UI;

search_course::~search_course() {}

void search_course::print_instructions()const 
{
    std::cout <<
    "Enter search term: ";
}

void search_course::execute()const
{
    std::string term;
    std::getline(std::cin, term);
    std::cout << "*************************************\n";
    std::cout << "*   SEARCH RESULTS                  *\n";
    std::cout << "*                                   *\n";
    DB::DBConnector::searchCourse(term).printCourse();
    std::cout << "*                                   *\n";
    std::cout << "*                                   *\n";
    std::cout << "*************************************\n";
}