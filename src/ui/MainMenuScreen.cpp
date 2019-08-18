/*
**************************************
*************PROGRADO*****************
**************************************
MainMenuScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"UserInterface.h"  


//--------------------------------------------------------------------------------------

Ui::MainMenuScreen::MainMenuScreen()
{
    //default constructor
}

//--------------------------------------------------------------------------------------

Ui::MainMenuScreen::~MainMenuScreen()
{
    //destructor
}

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

void Ui::MainMenuScreen::display()
{   
    int m_choice;

    std::cout << "Welcome to your Progrado Workspace\n";
    std::cout << "Enter: \n";
    std::cout << "  1 --- to add a course\n";
    std::cout << "  2 --- to remove a course\n";
    std::cout << "  3 --- to update a course\n";
    std::cout << "  4 --- to list all your courses\n";
    std::cout << "  5 --- to view your schedule summary\n";
    std::cout << "  00 --- to exit the program\n";

    std::unique_ptr<Progrado::UserInterface> m_ptr_accessUserInterface (new Progrado::UserInterface()); 


    std::cin >> m_choice;

    switch (m_choice)
    {
    case 1:
        PrUs::instantiateScreen(m_ptr_accessUserInterface->m_ptr_addCourseScreen, Progrado::Screen::add_course);
        break;
    
    case 2:
        PrUs::instantiateScreen(m_ptr_accessUserInterface->m_ptr_RemoveCourseScreen, Progrado::Screen::add_course);
        break;

    case 3:
        PrUs::instantiateScreen(m_ptr_accessUserInterface->m_ptr_UpdateCourseScreen, Progrado::Screen::add_course);
        break;

    case 4:
        PrUs::instantiateScreen(m_ptr_accessUserInterface->m_ptr_listAllCoursesScreen, Progrado::Screen::add_course);
        break;

    case 5:
        PrUs::instantiateScreen(m_ptr_accessUserInterface->m_ptr_scheduleSummaryScreen, Progrado::Screen::add_course);
        break;

    case 00:
        exit(2);
    
    default:
        {
            std::cout << "Invalid choice entered\n";
            std::unique_ptr<Progrado::UserInterface> m_ptr_toAccessInstantiate (new Progrado::UserInterface()); //pointer of class DBconnector for accessing DBConnector public functions
            m_ptr_toAccessInstantiate->instantiateScreen(m_ptr_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu);
            break;
        }
       
    }


}