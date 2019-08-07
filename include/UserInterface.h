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

#include"Screen.h"
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
    void instatiateScreen(const Ui::Screen*); 

private:

    Ui::Screen       *m_ptr_addCourseScreen;
    Ui::Screen       *m_ptr_mainMenu;
    Ui::Screen       *m_ptr_loginScreen;
    Ui::Screen       *m_ptr_createAccountScreen;
    Ui::Screen       *m_ptr_loginErrorScreen;
    Ui::Screen       *m_ptr_listAllCoursesScreen;
    Ui::Screen       *m_ptr_scheduleSummaryScreen;
    Ui::Screen       *m_ptr_UpdateCourseScreen;
    Ui::Screen       *m_ptr_RemoveCourseScreen;
    
    DB::DBConnector  *m_ptr_DBConnector;

};

#endif // endif