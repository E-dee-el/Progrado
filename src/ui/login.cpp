#include"login.h"
#include"DBConnector.h"
#include "retrieve_user_details.h"
#include<iostream>
#include<string>
#include<cstring>

using namespace Progrado;
using namespace DB;

login::login() {}
login::~login() {}

void login::prompt_user()const
{
    std::cout <<
              "\tLOGIN\n"
              "**************************************\n"
              "Enter your username and password below to login\n";
}

int login::execute()const
{
    using DB::DBConnector;

    std::string u_name(" "), p_word(" ");

    std::cout << "username: ";
    std::getline(std::cin, u_name);
    std::cout << "password: ";
    std::getline(std::cin, p_word);

    int attempts = 3; 

    while(!DBConnector::verifyUserCredentials(u_name, p_word)
            &&
            attempts > 0) 
    {
        std::cout << "username and/or password wrong. "
                  << --attempts << " attempts left\n";

        
        int rtrv_acct;

        std::cout << "Forgotten password or username? enter 1 to retrieve your account or 0 to retry login in\n";

        std::cin >> rtrv_acct;
        std::cin.ignore();

        if (rtrv_acct == 1)
        {
            return 2; 
        }
        else
        {
            std::cout << "username: ";
            std::getline(std::cin, u_name);
            std::cout << "password: ";
            std::getline(std::cin, p_word); 
        }
        
        
    }

    if (attempts > 0) 
    {
        std::cout << "Login Successful!\n**************************************\n";
        return true;
    }
    else {
        std::cerr << "Login attempts exceeded\n";
        return false;
        };
}