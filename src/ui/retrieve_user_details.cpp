#include"retrieve_user_details.h"
#include <iostream>
#include <fstream>

using namespace Progrado;
using namespace Progrado::UI;

retrieve_user_details::~retrieve_user_details() {}

void retrieve_user_details::print_instructions()const
{
    std::cout << "\t\tRETRIEVE DETAILS\n"
                 "\t===============\n"
                 "kindly provide answer to the security question below\n"; 
}

void retrieve_user_details::execute()const
{
    std::cout << "In what city were you born\n";
    std::string user_response;
    std::getline(std::cin, user_response);

    std::ifstream sec_question(".security_question.txt");
    std::string answer;
    std::getline(sec_question, answer);

    while (user_response != answer)
    {   
        std::cout << "wrong password, kindly reenter the answer to the question below\n";
        std::cout << "In what city were you born\n";
        std::getline(std::cin, user_response); 
    }

    //retrieve user details from database and print to user
}