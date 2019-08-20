/*
**************************************
*************PROGRADO*****************
**************************************
LoginScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"UserInterface.h"


std::string username;
std::string password;


Ui::LoginScreen::LoginScreen()
{
    //default constructor
}

Ui::LoginScreen::~LoginScreen()
{
    //destructor
}



int Ui::LoginScreen::display()
{   
    m_ptr_accessDBptr.reset(new Progrado::UserInterface()); 
    m_ptr_toVerify = m_ptr_accessDBptr->m_ptr_DBConnector;    

    m_attempts = 0;

    std::cout << "Please enter your Username and Password\n";
    std::cout << "Username: "; std::getline(std::cin,username);
    std::cout << "Paswword: "; std::getline(std::cin,password);

    m_check_credentials = m_ptr_toVerify->verifyUserCredentials(username,password); //verify credentials

    while (!m_check_credentials)
    {  
         if(m_attempts >=3)
            {
                std::cout << "You have exceeded the number of allowed fail attempts and ProGrado would be shutting down\n";
                break;  // will implement class LoginError here later instead of ending the program 
            }

        std::cout << "Please re-enter your Username and Password OR create an account if you do not have one\n";
        std::cout << "Enter 0 to go to create account screen\n";

        std::cout << "Username: "; std::getline(std::cin,username);

        if (std::stoi(username) == 0) //check if user wants to create an account
        {
            return Progrado::toCREATEACCT;
        }

        std::cout << "Password: "; std::getline(std::cin,password); 

        if (std::stoi(username) == 0) 
        {
            return Progrado::toCREATEACCT;
        }

        m_attempts++;
    } 

    return Progrado::DONE;
    
}

int Ui::LoginScreen::getUserInput()
{
    return Progrado::SUCCESS;
}

int Ui::LoginScreen::exitOrMoveBack()
{
    return Progrado::SUCCESS;
}

int Ui::LoginScreen::checkSuccess()
{
    return Progrado::SUCCESS;
}