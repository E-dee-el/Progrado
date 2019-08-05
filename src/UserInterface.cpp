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
}

Progrado::UserInterface::~UserInterface()
{
    //destructor
}

void Progrado::UserInterface::setup()
{
    // set up application 
}
void Progrado::UserInterface::run()
{
    //run the application/the user interface
}

template<typename T>
void Progrado::UserInterface::instatiateScreen(const T&)
{
    // instantiate screen depending in template argument
    // call T->display
}