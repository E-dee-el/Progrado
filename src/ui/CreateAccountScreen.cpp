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

//-------------------------------------------------------------------------------------//

Ui::CreateAccountScreen::CreateAccountScreen()
{
    //default constructor
}

//-------------------------------------------------------------------------------------//

Ui::CreateAccountScreen::~CreateAccountScreen()
{
    //destructor
}

//-------------------------------------------------------------------------------------//

int Ui::CreateAccountScreen::display()
{
    //class CreateAccountScreen is a Friend of Class User and Class UserInterface
    m_ptr_accessDBptr.reset(new Progrado::UserInterface()); 
    m_ptr_access_User.reset(new Progrado::User()); 
    m_ptr_access_toAccessDatabase =  m_ptr_accessDBptr->m_ptr_DBConnector; 

    // getInput
    this->getUserInput();

    //create object with default constructor (that uses a vector)
    std::unique_ptr<Progrado::User> m_ptr_access_User1 (new Progrado::User(m_ptr_access_User->m_userData));

    //add new user
    m_verify1 =  m_ptr_access_toAccessDatabase->addNewUser(*m_ptr_access_User1); 


    //check account creation 
    this->checkSuccess();

    //Exit/Back
    m_checkExitOrMoveBack = this->exitOrMoveBack();

    //move to MainMenu
    if (m_checkExitOrMoveBack == Progrado::DONE)
    {
        return Progrado::DONE;
    }
    else if (m_checkExitOrMoveBack == Progrado::EXIT)
    {
        return Progrado::EXIT;
    } 
}

//-------------------------------------------------------------------------------------//

int Ui::CreateAccountScreen::getUserInput()
{
    std::cout << "In order to create a ProGrado account, the followin information are required: \n";
    std::cout << "      user's last name\n";
    std::cout << "      user's first name\n";
    std::cout << "      user's year in college\n";
    std::cout << "      user's major/anticipated major\n";
    std::cout << "      user's minor/anticipated minor\n";
    std::cout << "      a username\n";
    std::cout << "      a password\n";

    m_ptr_access_User->setUp_account();

     //verify Input Success
    m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_lastName);
    m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_firstName);
    m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_yearInCollege);
    m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_username);
    m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_major);
    m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_minor);
    m_ptr_access_User->m_userData.push_back(m_ptr_access_User->m_password);

    return Progrado::SUCCESS;
}

//-------------------------------------------------------------------------------------//

int Ui::CreateAccountScreen::exitOrMoveBack()
{
    std::cout << "Enter -1 to go back to Main Menu, 0 to exit ProGrado\n";
    std::cin >> m_choice2;
    
    while (m_choice2 != -1 || m_choice2 != 0)
    {
        std::cout << "Invalid choice\n";
        std::cout << "Enter -1 to go back to Main Menu, 0 to exit ProGrado\n";
        std::cin >> m_choice2; 
    }
    if (m_choice2 == -1)
    {
        return Progrado::DONE;
    }
    else if(m_choice2 == 0)
    {
        std::cout << "You have exited Progrado\n";
        return Progrado::EXIT;
    } 
}

//-------------------------------------------------------------------------------------//

int Ui::CreateAccountScreen::checkSuccess() 
{
    if (m_verify1 == Progrado::SUCCESS)
    {  
        std::cout << "You have successfully created a ProGrado account\n"; 
        return Progrado::SUCCESS;
    }
    
    else
    {
        std::cout << "Account creation failed\n";
        std::cout << "ProGrado will be shutting down\n";
        return Progrado::FAIL; 
    } 
}

//-------------------------------------END--------------------------------------------//