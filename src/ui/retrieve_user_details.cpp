#include"retrieve_user_details.h"
#include <iostream>
#include <fstream>
#include"DBConnector.h"


using namespace Progrado;
using namespace Progrado::UI;

retrieve_user_details::~retrieve_user_details() {}

void retrieve_user_details::print_instructions()const
{
    std::cout << "\t\tRETRIEVE DETAILS\n"
                 "\n"
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

    int attempts  = 0;
    while (user_response != answer)
    {   
        std::cout << "wrong answer, kindly provide the correct answer\n";
        std::cout << "In what city were you born\n";
        std::getline(std::cin, user_response); 
        if (++attempts == 3)
            break;
    }

    if (user_response == answer)
    {
        auto user_details = DB::DBConnector::retrieveUserDetails();
        std::cout << "retrieving";
        Progrado::progrado_loading(3);
        std::cout << "Your username is: " << user_details[3] << std::endl;
        std::cout << "Your password is: " << user_details[4] << std::endl; 
        std::cout << "Press any key and then enter to continue\n";
        std::cin.get();
    }
    else
    {
        std::cout << "exceeded number of allowed attempts for details recovery\n";
    }  
}