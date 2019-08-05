/*
**************************************
*************PROGRADO*****************
**************************************
UserInterface header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */


#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include"LoginScreen.h"
#include"CreateAccountScreen.h"
#include"LoginErrorScreen.h"
#include"MainMenuScreen.h"
#include"ListAllCoursesScreen.h"
#include"AddCourseScreen.h"
#include"ScheduleSummaryScreen.h"
#include"UpdateCourseScreen.h"
#include"RemoveCourseScreen.h"
#include"DBConnector.h"
#include<memory>
namespace Progrado
{
  class UserInterface;  
} 


class Progrado::UserInterface{

public:

    UserInterface();
    ~UserInterface();
    void setup();
    void run();
    int connectToDatabase();
    int disconnectFromDatabase();
    template<typename T>
    void instatiateScreen(const T&); // instantiate all the different screens using
                                     // template function 

private:

    Ui::MainMenuScreen           *m_ptr_mainMenu;
    Ui::LoginScreen              *m_ptr_loginScreen;
    Ui::CreateAccountScreen      *m_ptr_createAccountScreen;
    Ui::LoginErrorScreen         *m_ptr_loginErrorScreen;
    Ui::ListAllCoursesScreen     *m_ptr_listAllCoursesScreen;
    Ui::AddCourseScreen          *m_ptr_addCourseScreen;
    Ui::ScheduleSummaryScreen    *m_ptr_scheduleSummaryScreen;
    Ui::UpdateCourseScreen       *m_ptr_UpdateCourseScreen;
    Ui::RemoveCourseScreen       *m_ptr_RemoveCourseScreen;
    DB::DBConnector              *m_ptr_DBConnector;

};

#endif // endif