/*
**************************************
*************PROGRADO*****************
**************************************
UserInterface Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */


#include"UserInterface.h" 
#include<iostream>
#include<stdlib.h>
#include"Progrado.h"

  

//------------------------------------------------------------------------------

Progrado::UserInterface::UserInterface():
m_ptr_addCourseScreen(nullptr),
m_ptr_createAccountScreen(nullptr),
m_ptr_DBConnector(nullptr),
m_ptr_listAllCoursesScreen(nullptr),
m_ptr_loginErrorScreen(nullptr),
m_ptr_mainMenu(nullptr),
m_ptr_loginScreen(nullptr),
m_ptr_RemoveCourseScreen(nullptr),
m_ptr_scheduleSummaryScreen(nullptr),
m_ptr_UpdateCourseScreen(nullptr)
{
    //default constructor
    std::cout << "User Interface instantiated\n"; // for testing purposes only
}

//-------------------------------------------------------------------------------

Progrado::UserInterface::~UserInterface()
{
    //destructor 
    std::cout << "User Interface destroyed\n"; // for testing purposes only
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

void Progrado::UserInterface::setup()
{  
    std::cout << "HELLO, WELCOME TO PROGRADO\n";
    std::cout << "WE BELIEVE YOU ARE HERE TO MAKE YOUR COLLEGE COURSE-MANAGEMENT LIFE AN EVEN MORE CONVENIENT ONE\n";

    std::cout << "Note that you can exit the program at any point by ENTERING 0\n";
    std::cout << "Also, ENTER -1 at any point in the program to go to a previous screen\n";
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

int Progrado::UserInterface::run() 
{
    //run the application/the user interface
    std::cout << "Kindly enter 1 to login, 2 to create an account\n";
    std::cin >> m_selection;
    
    while(m_selection != 1 || m_selection != 2)
    {
        if(m_selection == 0)
        {
            std::cout << "You have exited ProGrado\n";
            return Progrado::EXIT;
        }
        else
        {
            std::cout << "Invalid Entry\n";
            std::cout << "Please enter 1 to go to login screen, 2 to create an account or 0 to exit ProGrado\n";
            std::cin >> m_selection;
        }
        
    }

    if (m_selection == 1)    //Case Login
    {   
        m_ptr_DBConnector.reset(new DB::DBConnector); //reopen existing database
        m_instantiateChecker = instantiateScreen(m_ptr_loginScreen, login);
        
        if (m_instantiateChecker == Progrado::DONE)
        {   
            ///DATABASE REOPENING HERE///*****************************
            m_instantiateChecker = instantiateScreen(m_ptr_mainMenu, main_menu);

            if (m_instantiateChecker == Progrado::EXIT)
            {
                return Progrado::EXIT;
            }
        }
        else if (m_instantiateChecker == Progrado::toCREATEACCT)
        {
            m_instantiateChecker = instantiateScreen(m_ptr_createAccountScreen, create_account);

            if (m_instantiateChecker == Progrado::DONE)
            {
                 m_instantiateChecker = instantiateScreen(m_ptr_mainMenu, main_menu);
                 if (m_instantiateChecker == Progrado::EXIT)
                    {
                        return Progrado::EXIT;
                    }
            }
            else if (m_instantiateChecker == Progrado::EXIT)
            {
                return Progrado::EXIT;
            }
        }
        
    }

    else if  (m_selection == 2) //Case Create new account
    {
        m_instantiateChecker = instantiateScreen(m_ptr_createAccountScreen, create_account);

            if (m_instantiateChecker == Progrado::DONE)
            {   
                //Create Database for the new user
                m_ptr_DBConnector.reset(new DB::DBConnector);

                m_instantiateChecker = instantiateScreen(m_ptr_mainMenu, main_menu);
                if (m_instantiateChecker == Progrado::EXIT)
                {
                    return Progrado::EXIT;
                }
            }
            else if (m_instantiateChecker == Progrado::EXIT)
            {
                return Progrado::EXIT;
            }
    }
}


int Progrado::UserInterface::instantiateScreen(std::unique_ptr<Ui::Screen> & screen_ptr, Progrado::Screen m_screen) 
{ 
   
   switch (m_screen)
    {
        case add_course:
            {
                // AddCourseScreen

                screen_ptr.reset(new Ui::AddCourseScreen);
                //std::unique_ptr<Ui::AddCourseScreen> m_ptr_lsScreen(dynamic_cast<Ui::AddCourseScreen*>(screen_ptr.get()));
                m_displayChecker = screen_ptr->display();
                break;
            }
        
        case remove_course:
            {
                // RemoveCourseScreen
                
                screen_ptr.reset(new Ui::RemoveCourseScreen);
                //std::unique_ptr<Ui::RemoveCourseScreen> m_ptr_lsScreen(dynamic_cast<Ui::RemoveCourseScreen*>(screen_ptr.get()));
                m_displayChecker = screen_ptr->display();
                break;

            }
        
        case update_course:
            {
            // UpdateCourseScreen
            
            screen_ptr.reset(new Ui::UpdateCourseScreen);
            //std::unique_ptr<Ui::UpdateCourseScreen> m_ptr_lsScreen(dynamic_cast<Ui::UpdateCourseScreen*>(screen_ptr.get()));
            m_displayChecker = screen_ptr->display();
            break;
            }

        case list_course:
            {
            // ListAllCoursesScreen

            screen_ptr.reset(new Ui::ListAllCoursesScreen);
            //std::unique_ptr<Ui::ListAllCoursesScreen> m_ptr_lsScreen(dynamic_cast<Ui::ListAllCoursesScreen*>(screen_ptr.get()));
            m_displayChecker = screen_ptr->display();
            break;

            }

        case schedule_summary:
            {
            // ScheduleSummaryScreen

            screen_ptr.reset(new Ui::ScheduleSummaryScreen);
            std::unique_ptr<Ui::ScheduleSummaryScreen> m_ptr_lsScreen(dynamic_cast<Ui::ScheduleSummaryScreen*>(screen_ptr.get()));
            m_displayChecker = screen_ptr->display();
            break;

            } 

        case login:
            {   
                // LoginScreen

                screen_ptr.reset(new Ui::LoginScreen);
                //std::unique_ptr<Ui::LoginScreen> m_ptr_lsScreen(dynamic_cast<Ui::LoginScreen*>(screen_ptr.get()));
                m_displayChecker = screen_ptr->display();
                break;
            }

        case login_error:
            {
                // LoginErrorScreen

                screen_ptr.reset(new Ui::LoginErrorScreen);
                //std::unique_ptr<Ui::LoginErrorScreen> m_ptr_lsScreen(dynamic_cast<Ui::LoginErrorScreen*>(screen_ptr.get()));
                m_displayChecker = screen_ptr->display();
                break;
            }

        case create_account:
            {
                // CreateAccountScreen

                screen_ptr.reset(new Ui::CreateAccountScreen);
                //std::unique_ptr<Ui::CreateAccountScreen> m_ptr_lsScreen(dynamic_cast<Ui::CreateAccountScreen*>(screen_ptr.get()));
                m_displayChecker = screen_ptr->display();
                break;
            }

        case main_menu:
            {
                // MainMenuScreen

                screen_ptr.reset(new Ui::MainMenuScreen);
                //std::unique_ptr<Ui::MainMenuScreen> m_ptr_lsScreen(dynamic_cast<Ui::MainMenuScreen*>(screen_ptr.get()));
                m_displayChecker = screen_ptr->display();
                break;
            }

            
    default:
        break;


    }

    //CHECKER

    if (m_displayChecker == Progrado::DONE)
    {
        return Progrado::DONE;
    }
    else if (m_displayChecker == Progrado::EXIT)
    {
        return Progrado::EXIT;
    }
}