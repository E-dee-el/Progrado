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

Progrado::UserInterface::~UserInterface()
{
    //destructor 
    std::cout << "User Interface destroyed\n"; // for testing purposes only
}

void Progrado::UserInterface::setup()
{
    // set up application 
}
void Progrado::UserInterface::run()
{
    //run the application/the user interface
}


void Progrado::UserInterface::instatiateScreen(const Ui::Screen* screen_ptr)
{
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
            // method is pure virtual and must be overridden


    */

}