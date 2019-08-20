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

int Ui::MainMenuScreen::display() 
{   
    m_ptr_accessUserInterface.reset(new Progrado::UserInterface()); 
    
    m_choice = 1;
    
    while (m_choice != 0)
    {   
        this->getUserInput();

        switch (m_choice)
        {
            case 1:
                m_checkInstantiate =  m_ptr_accessUserInterface->instantiateScreen(
                                      m_ptr_accessUserInterface->m_ptr_addCourseScreen, Progrado::Screen::add_course);
                
                if (m_checkInstantiate == Progrado::DONE)
                {
                    break;
                }
                else if (m_checkInstantiate == Progrado::EXIT)
                {
                    return Progrado::EXIT;
                }
            
            case 2:
                m_checkInstantiate =  m_ptr_accessUserInterface->instantiateScreen(
                                      m_ptr_accessUserInterface->m_ptr_RemoveCourseScreen, Progrado::Screen::add_course);
                if (m_checkInstantiate == Progrado::DONE)
                {
                    break;
                }
                else if (m_checkInstantiate == Progrado::EXIT)
                {
                    return Progrado::EXIT;
                }

            case 3:
                m_checkInstantiate =  m_ptr_accessUserInterface->instantiateScreen(
                                      m_ptr_accessUserInterface->m_ptr_UpdateCourseScreen, Progrado::Screen::add_course);
                if (m_checkInstantiate == Progrado::DONE)
                {
                    break;
                }
                else if (m_checkInstantiate == Progrado::EXIT)
                {
                    return Progrado::EXIT;
                }

            case 4:
                m_checkInstantiate =  m_ptr_accessUserInterface->instantiateScreen(
                                      m_ptr_accessUserInterface->m_ptr_listAllCoursesScreen, Progrado::Screen::add_course);
                if (m_checkInstantiate == Progrado::DONE)
                {
                    break;
                }
                else if (m_checkInstantiate == Progrado::EXIT)
                {
                    return Progrado::EXIT;
                }

            case 5:
                m_checkInstantiate =  m_ptr_accessUserInterface->instantiateScreen(
                                      m_ptr_accessUserInterface->m_ptr_scheduleSummaryScreen, Progrado::Screen::add_course);
                if (m_checkInstantiate == Progrado::DONE)
                {
                    break;
                }
                else if (m_checkInstantiate == Progrado::EXIT)
                {
                    return Progrado::EXIT;
                }

            case 0: 
                return Progrado::EXIT; 
            
            default:
                {
                    std::cout << "Invalid choice entered\n";
                    break;
                }
        }

    }


}

int Ui::MainMenuScreen::getUserInput()
{
    std::cout << "Welcome to your Progrado Workspace\n";
    std::cout << "Enter: \n";
    std::cout << "  1 --- to add a course\n";
    std::cout << "  2 --- to remove a course\n";
    std::cout << "  3 --- to update a course\n";
    std::cout << "  4 --- to list all your courses\n";
    std::cout << "  5 --- to view your schedule summary\n";
    std::cout << "  0 --- to exit the program\n"; 

    std::cin >> m_choice;

    return Progrado::SUCCESS;
}

int Ui::MainMenuScreen::exitOrMoveBack()
{
    return Progrado::SUCCESS;
}

int Ui::MainMenuScreen::checkSuccess()
{
    return Progrado::SUCCESS;
}