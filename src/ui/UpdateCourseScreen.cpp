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

Ui::UpdateCourseScreen::UpdateCourseScreen()
{
    //default constructor
}

Ui::UpdateCourseScreen::~UpdateCourseScreen()
{
    //destructor
}

void Ui::UpdateCourseScreen::display()
{
    std::cout << " Please enter the course ID for the course you would like to update\n";
    
    std::unique_ptr<Progrado::Course> m_ptr_accessCourse (new Progrado::Course());

    getline(std::cin, m_ptr_accessCourse->m_courseID); 

    std::unique_ptr<Progrado::Course> m_ptr_oldCourse (new Progrado::Course("Not set","Not set","Not set", m_ptr_accessCourse->m_courseID, "Not set"));


    std::unique_ptr<Progrado::Course> m_ptr_accessCourse1 (new Progrado::Course);

    std::cout << "Please enter the following details for the course you would like to update\n";

    m_ptr_accessCourse1->setUpCourse();

    std::unique_ptr<Progrado::Course> m_ptr_newCourse (new Progrado::Course (m_ptr_accessCourse->m_course_name, m_ptr_accessCourse->m_semesterOffered,
                                                                                  m_ptr_accessCourse->m_yearOffered, m_ptr_accessCourse->m_courseID,
                                                                                  m_ptr_accessCourse->m_course_type,m_ptr_accessCourse->m_credits));

    std::unique_ptr<DB::DBConnector> m_ptr_accessDB (new DB::DBConnector);
    
    int m_verify = m_ptr_accessDB->updateCourse(*m_ptr_oldCourse, *m_ptr_newCourse);


    if (m_verify == Progrado::SUCCESS)
    {
        std::cout << "Successfully updated course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;   
    }
    
    else
    {
        std::cout << "Failed to update course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;
    }

    std::unique_ptr<Progrado::UserInterface> m_ptr_access_toAccessInstantiate (new Progrado::UserInterface());
    m_ptr_access_toAccessInstantiate->instantiateScreen(m_ptr_access_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu); 

}