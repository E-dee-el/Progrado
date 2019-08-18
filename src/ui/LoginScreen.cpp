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

//class LoginScreen() is a Friend of Class DBConnector and Class UserInterface
std::unique_ptr<DB::DBConnector> m_ptr_toVerify (new DB::DBConnector()); //pointer of class DBconnector for accessing DBConnector public functions
std::unique_ptr<Progrado::UserInterface> m_ptr_toRun (new Progrado::UserInterface()); //pointer of class DBconnector for accessing DBConnector public functions

void Ui::LoginScreen::display()
{  
     int m_attempts(0);

    std::cout << "Please enter your Username and Password\n";

    std::cout << "Username: "; getline(std::cin,username);
    std::cout << "Paswword: "; getline(std::cin,password);

    std::cout << "LoginScreen() called\n";

    bool m_check_credentials = m_ptr_toVerify->verifyUserCredentials(username,password); //verify credentials

    while (!m_check_credentials)
    {  
         if(m_attempts >=3)
            {
                std::cout << "You have exceeded the number of allowed fail attempts and ProGrado would be shutting down\n";
                system("pause");
                exit(2);  // will implement class LoginError here later instead of ending the program 
            }

        std::cout << "Please re-enter your Username and Password OR create an account if you do not have one\n";
        std::cout << "Enter 0 to go to create account screen\n";

        std::cout << "Username: "; getline(std::cin,username);

        if (stoi(username) == 0) //check if user wants to create an account
        {
            m_ptr_toRun->instantiateScreen(m_ptr_toRun->m_ptr_createAccountScreen, Progrado::Screen::create_account); // go to create account screen
            break; //not sure if this should be here
        }

        std::cout << "Paswword: "; getline(std::cin,password);
        if (stoi(username) == 0)
        {
            m_ptr_toRun->instantiateScreen(m_ptr_toRun->m_ptr_createAccountScreen, Progrado::Screen::create_account); // go to create account screen
            break; //not sure if this should be here
        }

        m_attempts++;
    }

    m_ptr_toRun->instantiateScreen(m_ptr_toRun->m_ptr_mainMenu, Progrado::Screen::main_menu); // go to main menu screen if login successful
    
}