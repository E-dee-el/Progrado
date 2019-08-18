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

Ui::AddCourseScreen::AddCourseScreen()
{
    //default constructor
}

Ui::AddCourseScreen::~AddCourseScreen()
{
    //destructor
}

void Ui::AddCourseScreen::display()
{
    std::unique_ptr<Progrado::Course> m_ptr_accessCourse (new Progrado::Course);

    m_ptr_accessCourse->setUpCourse();

    std::unique_ptr<Progrado::Course> m_ptr_accessCourse1 (new Progrado::Course (m_ptr_accessCourse->m_course_name, m_ptr_accessCourse->m_semesterOffered,
                                                                                  m_ptr_accessCourse->m_yearOffered, m_ptr_accessCourse->m_courseID,
                                                                                  m_ptr_accessCourse->m_course_type,m_ptr_accessCourse->m_credits));

    
    std::unique_ptr<DB::DBConnector> m_ptr_DataBase (new DB::DBConnector);


   int m_verify =  m_ptr_DataBase->addCourse(*m_ptr_accessCourse1);


   if (m_verify == Progrado::SUCCESS)
        {
            std::cout << "Successfully added course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;
        }
 
    else
        {
            std::cout << "Failed to add course with course ID: " << m_ptr_accessCourse->m_courseID << std::endl;
        }

    std::unique_ptr<Progrado::UserInterface> m_ptr_access_toAccessInstantiate (new Progrado::UserInterface());
    m_ptr_access_toAccessInstantiate->instantiateScreen(m_ptr_access_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu);

    

}