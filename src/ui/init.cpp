#include"init.h"
#include"create_account.h"
#include"login.h"
#include<iostream>
#include<fstream>
#include<stdexcept>

using namespace Progrado;
using namespace Progrado::UI;

init::~init() {}
bool init::is_new_user()
{
    std::ifstream infile(".acct_status.txt");
    if(infile.fail())
        throw std::runtime_error("init::is_new_user(): Unable to verify acct status\n");
    int x;
    infile >> x;

    return x == 0;
}
bool init::execute()
{
    if(is_new_user())
    {
        std::cout << "Create an account: enter any key to continue or 0 to exit\n";
        std::string reply;
        std::cin >> reply;
        std::cin.ignore();

        if(reply == "0") return false;
        else
        {
            auto transfer_to_create_acct = std::make_unique<create_account>();
            transfer_to_create_acct->execute();
                /* then login*/
            auto transfer_to_login = std::make_unique<login>();
            transfer_to_login->prompt_user();

            if(!transfer_to_login->execute()) return false;
            
            return true; 
        }
     
    }
    else
    {       std::cout << "LOGIN\n";
            std::cout << "Hit any key and enter to continue, or 0 to exit\n"
            "**************************************\n";
            std::string choice;
            std::cin >> choice;
            std::cin.ignore();

            if(choice == "0") return false;
            else
            {
                auto transfer_to_login = std::make_unique<login>();
                transfer_to_login->prompt_user();
                if(!transfer_to_login->execute()) return false;
                return true;
            }
             
    }
    
}