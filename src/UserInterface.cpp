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
    int m_selection;

    std::cout << "HELLO, WELCOME TO PROGRADO\n";
    std::cout << "WE BELIEVE YOU ARE HERE TO MAKE YOUR COLLEGE COURSE-MANAGEMENT LIFE AN EVEN MORE CONVENIENT ONE\n";

    std::cout << "Note that you can exit the program at any point by ENTERING 00\n";
    std::cout << "Also, ENTER 0 at any point in the program to go to a previous screen\n";

    std::cout << "Kindly enter 1 to login, 2 to create an account\n";
    
    

    std::cin >> m_selection;
    
    while(m_selection != 1 || m_selection != 2)
    {
        if(m_selection == 00)
        {
            std::cout << "You have exited ProGrado\n";
            system("pause");
            exit(1);
        }
        else
        {
            std::cout << "Invalid Entry\n";
            std::cout << "Please enter 1 to go to login screen or 00 to exit ProGrado\n";
            std::cin >> m_selection;
        }
        
    }

    if (m_selection == 1)
    {
        PrUs::instantiateScreen(m_ptr_loginScreen, login);
    }

    else
    {
        PrUs::instantiateScreen(m_ptr_createAccountScreen, create_account);
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void Progrado::UserInterface::run()
{
    //run the application/the user interface

    PrUs::instantiateScreen(m_ptr_mainMenu, main_menu);

}


void Progrado::UserInterface::instantiateScreen(std::unique_ptr<Ui::Screen> & screen_ptr, Progrado::Screen m_screen) 
{
   
   switch (m_screen)
    {
        case add_course:
            {
                // AddCourseScreen

                screen_ptr.reset(new Ui::AddCourseScreen);
                std::unique_ptr<Ui::AddCourseScreen> m_ptr_lsScreen(dynamic_cast<Ui::AddCourseScreen*>(screen_ptr.get()));
                screen_ptr->display();
                break;
            }
        
        case remove_course:
            {
                // RemoveCourseScreen
                
                screen_ptr.reset(new Ui::RemoveCourseScreen);
                std::unique_ptr<Ui::RemoveCourseScreen> m_ptr_lsScreen(dynamic_cast<Ui::RemoveCourseScreen*>(screen_ptr.get()));
                screen_ptr->display();
                break;

            }
        
        case update_course:
            {
            // UpdateCourseScreen
            
            screen_ptr.reset(new Ui::UpdateCourseScreen);
            std::unique_ptr<Ui::UpdateCourseScreen> m_ptr_lsScreen(dynamic_cast<Ui::UpdateCourseScreen*>(screen_ptr.get()));
            screen_ptr->display();

            }

        case list_course:
            {
            // ListAllCoursesScreen

            screen_ptr.reset(new Ui::ListAllCoursesScreen);
            std::unique_ptr<Ui::ListAllCoursesScreen> m_ptr_lsScreen(dynamic_cast<Ui::ListAllCoursesScreen*>(screen_ptr.get()));
            screen_ptr->display();

            }

        case schedule_summary:
            {
            // ScheduleSummaryScreen

            screen_ptr.reset(new Ui::ScheduleSummaryScreen);
            std::unique_ptr<Ui::ScheduleSummaryScreen> m_ptr_lsScreen(dynamic_cast<Ui::ScheduleSummaryScreen*>(screen_ptr.get()));
            screen_ptr->display();

            } 

        case login:
            {   
                // LoginScreen

                screen_ptr.reset(new Ui::LoginScreen);
                std::unique_ptr<Ui::LoginScreen> m_ptr_lsScreen(dynamic_cast<Ui::LoginScreen*>(screen_ptr.get()));
                screen_ptr->display();
            }

        case login_error:
            {
                // LoginErrorScreen

                screen_ptr.reset(new Ui::LoginErrorScreen);
                std::unique_ptr<Ui::LoginErrorScreen> m_ptr_lsScreen(dynamic_cast<Ui::LoginErrorScreen*>(screen_ptr.get()));
                screen_ptr->display();
            }

        case create_account:
            {
                // CreateAccountScreen

                screen_ptr.reset(new Ui::CreateAccountScreen);
                std::unique_ptr<Ui::CreateAccountScreen> m_ptr_lsScreen(dynamic_cast<Ui::CreateAccountScreen*>(screen_ptr.get()));
                screen_ptr->display();
            }

        case main_menu:
            {
                // MainMenuScreen

                screen_ptr.reset(new Ui::MainMenuScreen);
                std::unique_ptr<Ui::MainMenuScreen> m_ptr_lsScreen(dynamic_cast<Ui::MainMenuScreen*>(screen_ptr.get()));
                screen_ptr->display();
            }

            
    default:
        break;
    }


   
    /*  instantiate an appropriate screen using only this one function
        make sure to call new to make the pointer point to an appropraite screen
        before passing it to this function. For example, in the main app event loop,
        if we want to instantiate addCourse screen. do:

            m_ptr_addCourseScreen = new addCourseScreen();

             // this is OK, since addCourseScreen derives from Screen
               // then pass m_ptr_addCourseScreen to this function like so:

            app->instantiateScreen(m_ptr_addCourseScreen);

            // since this will display the screen, the display() method
            // of addCourseScreen will be called (recall that the Screen display()
            // method is pure virtual and must be overridden)
            
            // from here on, if you need to use any specific methods of addCourseScreen,
            you must use dynamic cast to cast the pointer from type Ui::Screen* to 
            Ui::addCourseScreen*


    */

}