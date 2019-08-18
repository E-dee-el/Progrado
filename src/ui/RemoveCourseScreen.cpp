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

Ui::RemoveCourseScreen::RemoveCourseScreen()
{
    //default constructor
}

Ui::RemoveCourseScreen::~RemoveCourseScreen()
{
    //destructor
}        


void Ui::RemoveCourseScreen::display()
{
    std::cout << "Please provide the course ID for the course you would like to remove\n";

    std::unique_ptr<Progrado::Course> m_ptr_accessCourse (new Progrado::Course());

    getline(std::cin, m_ptr_accessCourse->m_courseID);      

    std::unique_ptr<Progrado::Course> m_ptr_accessCourse1 (new Progrado::Course("Not set","Not set","Not set", m_ptr_accessCourse->m_courseID, "Not set"));

    std::unique_ptr<DB::DBConnector> m_ptr_DBconnector (new DB::DBConnector);

    int m_verify = m_ptr_DBconnector->removeCourse(*m_ptr_accessCourse1);

    if (m_verify == Progrado::SUCCESS)
    {
        std::cout << "Successfully removed course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;   
    }
    
    else
    {
        std::cout << "Failed to remove course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    
    std::unique_ptr<Progrado::UserInterface> m_ptr_access_toAccessInstantiate (new Progrado::UserInterface());
    m_ptr_access_toAccessInstantiate->instantiateScreen(m_ptr_access_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu); 

}