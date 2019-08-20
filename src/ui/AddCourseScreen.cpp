/*
**************************************
*************PROGRADO*****************
**************************************
AddCourseScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */
 
#include"UserInterface.h"

//----------------------------------------------------------------------------//

Ui::AddCourseScreen::AddCourseScreen()
{
    //default constructor
}

//---------------------------------------------------------------------------//

Ui::AddCourseScreen::~AddCourseScreen()
{
    //destructor
}

//----------------------------------------------------------------------------//

int Ui::AddCourseScreen::display()
{   
    //allocate memory to all pointers
    m_ptr_accessDBptr.reset(new Progrado::UserInterface);
    m_ptr_accessCourse.reset(new Progrado::Course);
    m_ptr_DataBase = m_ptr_accessDBptr->m_ptr_DBConnector; 

    //get User Input
    this->getUserInput();

    //pointer to object (uses a default constructor)
    std::unique_ptr<Progrado::Course> m_ptr_accessCourse1 
                                        (new Progrado::Course(
                                        m_ptr_accessCourse->m_course_name, m_ptr_accessCourse->m_semesterOffered,
                                        m_ptr_accessCourse->m_yearOffered, m_ptr_accessCourse->m_courseID,
                                        m_ptr_accessCourse->m_course_type,m_ptr_accessCourse->m_credits));

    //add the course to database and check for success
    m_verify =  m_ptr_DataBase->addCourse(*m_ptr_accessCourse1);  

    //check if operation was successful
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

//---------------------------------------------------------------------------//

int Ui::AddCourseScreen::getUserInput()
{
    //get all necessary details for adding a course
    m_ptr_accessCourse->setUpCourse(); 
    return Progrado::SUCCESS; 
}

//----------------------------------------------------------------------------//

int Ui::AddCourseScreen::exitOrMoveBack()
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

//----------------------------------------------------------------------------//

int Ui::AddCourseScreen::checkSuccess()
{   
    if (m_verify == Progrado::SUCCESS)
        {
            std::cout << "Successfully added course with course ID: " 
                      << m_ptr_accessCourse->m_courseID << std::endl;
                      return Progrado::SUCCESS;
        }
 
    else
        {
            std::cout << "Failed to add course with course ID: " 
                      << m_ptr_accessCourse->m_courseID << std::endl;
                      return Progrado::FAIL;
        }
}

//-----------------END----------------------------------------------------------//