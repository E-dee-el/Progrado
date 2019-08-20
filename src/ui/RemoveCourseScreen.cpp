/*
**************************************
*************PROGRADO*****************
**************************************
RemoveCourseScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"UserInterface.h" 

//-------------------------------------------------------------------------------------------//

Ui::RemoveCourseScreen::RemoveCourseScreen()
{
    //default constructor
}

//-------------------------------------------------------------------------------------------//

Ui::RemoveCourseScreen::~RemoveCourseScreen()
{
    //destructor
}        

//-------------------------------------------------------------------------------------------//

int Ui::RemoveCourseScreen::display()
{   m_ptr_accessCourse.reset(new Progrado::Course());
    m_ptr_DBconnector = m_ptr_accessDBptr->m_ptr_DBConnector;

     //get User Input  
    this->getUserInput();

    m_ptr_accessCourse1.reset(new Progrado::Course("Not set","Not set","Not set",
                                                    m_ptr_accessCourse->m_courseID, "Not set"));
    m_verify = m_ptr_DBconnector->removeCourse(*m_ptr_accessCourse1);

    //check remove course operation report
    this->checkSuccess();

    //allow user to exit program or go back
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

//----------------------------------------------------------------------------------------------//

int Ui::RemoveCourseScreen::getUserInput()
{
    std::cout << "Please provide the course ID for the course you would like to remove\n";
    std::getline(std::cin, m_ptr_accessCourse->m_courseID);  
    return Progrado::SUCCESS; 
}

//----------------------------------------------------------------------------------------------//

int Ui::RemoveCourseScreen::exitOrMoveBack() 
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

//----------------------------------------------------------------------------------------------//

int Ui::RemoveCourseScreen::checkSuccess()
{
    if (m_verify == Progrado::SUCCESS)
    {
        std::cout << "Successfully removed course with course ID: " 
                  << m_ptr_accessCourse->m_courseID << std::endl;
                  return Progrado::SUCCESS; 
    }
    else
    {
        std::cout << "Failed to remove course with course ID: " 
                  << m_ptr_accessCourse->m_courseID << std::endl;
                  return Progrado::FAIL;
    }

}

//-------------------------------------------------END------------------------------------------//