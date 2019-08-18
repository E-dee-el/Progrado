/*
**************************************
*************PROGRADO*****************
**************************************
CreateAccountScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"UserInterface.h" 



Ui::CreateAccountScreen::CreateAccountScreen()
{
    //default constructor
}

Ui::CreateAccountScreen::~CreateAccountScreen()
{
    //destructor
}

void Ui::CreateAccountScreen::display()
{
        //class CreateAccountScreen is a Friend of Class User and Class UserInterface
    std::unique_ptr<Progrado::UserInterface> m_ptr_access_toAccessInstantiate (new Progrado::UserInterface()); //pointer of class UserInterfacefor accessing DBConnector public functions
    std::unique_ptr<Progrado::User> m_ptr_access_User (new Progrado::User()); //pointer of class User for accessing User public functions
    std::unique_ptr<DB::DBConnector> m_ptr_access_toAccessDatabase(new DB::DBConnector());

    std::cout << "In order to create a ProGrado account, the followin information are required: \n";
    std::cout << "      user's last name\n";
    std::cout << "      user's first name\n";
    std::cout << "      user's year in college\n";
    std::cout << "      user's major/anticipated major\n";
    std::cout << "      user's minor/anticipated minor\n";
    std::cout << "      a username\n";
    std::cout << "      a password\n";

    int m_verify;
    int m_verify1;

    m_verify = m_ptr_access_User->setUp_account();

    if(m_verify == 1)
    {
        m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_lastName);
        m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_firstName);
        m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_yearInCollege);
        m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_username);
        m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_major);
        m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_minor);
        m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_password);

        //create object with default constructor (that uses a vector)
        std::unique_ptr<Progrado::User> m_ptr_access_User1 (new Progrado::User(m_ptr_access_User->m_userData));

    //----------------------------------------------------------------------------------------

    m_verify1 =  m_ptr_access_toAccessDatabase->addNewUser(*m_ptr_access_User1); 
    }

    if (m_verify1 == Progrado::SUCCESS)
    {   
        std::unique_ptr<DB::DBConnector> m_ptr_DB( new DB::DBConnector);
        m_ptr_DB->createUserTable();

        std::cout << "You have successfully created a ProGrado account\n"; 

    }
    
    else
    {
        std::cout << "Account creation failed\n";
        std::cout << "ProGrado will be shutting down\n";
        exit(5);
    } 

    std::cout << "########################################################################\n";

    //go to main menu after successfully creating an account
    m_ptr_access_toAccessInstantiate->instantiateScreen(m_ptr_access_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu);

    
}