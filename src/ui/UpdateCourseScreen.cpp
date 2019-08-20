/*
**************************************
*************PROGRADO*****************
**************************************
UpdateCourseScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */ 
 
#include"UserInterface.h" 

//---------------------------------------------------------------------------------//

Ui::UpdateCourseScreen::UpdateCourseScreen()
{
    //default constructor
}

//---------------------------------------------------------------------------------//

Ui::UpdateCourseScreen::~UpdateCourseScreen()
{
    //destructor
}

//--------------------------------DISPLAY-------------------------------------------//

int Ui::UpdateCourseScreen::display()
{   m_ptr_accessDBptr.reset(new Progrado::UserInterface);
    m_ptr_accessDB = m_ptr_accessDBptr->m_ptr_DBConnector;
    m_ptr_accessCourse1.reset(new Progrado::Course);
    m_ptr_accessCourse.reset(new Progrado::Course()); 


    std::cout << " Please enter the course ID for the course you would like to update\n";
    std::getline(std::cin, m_ptr_accessCourse->m_courseID); 

    m_ptr_oldCourse.reset(new Progrado::Course("Not set","Not set","Not set",
                                                m_ptr_accessCourse->m_courseID, "Not set"));

    std::cout << "Please enter the following details for the course you would like to update\n";
    m_ptr_accessCourse1->setUpCourse();
    m_ptr_newCourse.reset(new Progrado::Course (m_ptr_accessCourse->m_course_name, m_ptr_accessCourse->m_semesterOffered,
                                                m_ptr_accessCourse->m_yearOffered, m_ptr_accessCourse->m_courseID,
                                                m_ptr_accessCourse->m_course_type,m_ptr_accessCourse->m_credits));

    m_verify = m_ptr_accessDB->updateCourse(*m_ptr_oldCourse, *m_ptr_newCourse);
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

//-----------------------------INPUT-------------------------------------------//

int Ui::UpdateCourseScreen::getUserInput()
{
    return Progrado::SUCCESS;
}

//---------------------------------------------------------------------------------//

int Ui::UpdateCourseScreen::exitOrMoveBack()
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

//------------------------------SUCCESS?--------------------------------------------//

int Ui::UpdateCourseScreen::checkSuccess()
{
    if (m_verify == Progrado::SUCCESS)
    {
        std::cout << "Successfully updated course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;
        return Progrado::SUCCESS;   
    }
    else
    {
        std::cout << "Failed to update course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;
        return Progrado::SUCCESS;
    }

}

//--------------------------------------END---------------------------------------//