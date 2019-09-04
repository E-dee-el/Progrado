#include"init.h"
#include"create_account.h"
#include"login.h"
#include<iostream>

using namespace Progrado;
using namespace Progrado::UI;

init::~init(){}
bool init::execute()
{   
    int response = 0;
    std::cout << 
    "Type 1 to login\n"
    "New user? Type 2 to create an account\n"
    "Type 0 to exit\n";

    std::cin >> response;
    std::cin.ignore();
    while(response != 0)
    {
        if(response == 1)
        {
            auto transfer_to_login = std::make_unique<login>();
            transfer_to_login->prompt_user();
            transfer_to_login->execute(); 
            return true;
        }
        else if (response == 2)
        {
            auto transfer_to_create_acct = std::make_unique<create_account>();
            transfer_to_create_acct->execute(); 
            /* then login*/
            auto transfer_to_login = std::make_unique<login>();
            transfer_to_login->prompt_user();
            transfer_to_login->execute();
            return true;
        }
        else if(response == 0)
            return false;
        else
        {
                std::cerr << "Invalid response. Try again or enter 0 to exit\n";
                return false;
        }
            
    }

    
}