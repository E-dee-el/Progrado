#include"retrieve_user_details.h"
#include <iostream>

using namespace Progrado;
using namespace Progrado::UI;

retrieve_user_details::~retrieve_user_details() {}

void retrieve_user_details::print_instructions()const
{
    std::cout << "\t\tUSER DETAILS\n"
                 "\t===============\n"
                 "Below is your information: enter 1 to go back or 2 to modify your details\n";
}

void retrieve_user_details::execute()const
{
    
}