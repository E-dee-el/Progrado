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
    void login(int);
    void instantiateScreen(std::unique_ptr<Ui::Screen>&, int); 


private:

    std::unique_ptr<Ui::Screen>        m_ptr_addCourseScreen;
    std::unique_ptr<Ui::Screen>         m_ptr_mainMenu;
    std::unique_ptr<Ui::Screen>            m_ptr_loginScreen;
    std::unique_ptr<Ui::Screen>    m_ptr_createAccountScreen;
    std::unique_ptr<Ui::Screen>       m_ptr_loginErrorScreen;
    std::unique_ptr<Ui::Screen>   m_ptr_listAllCoursesScreen;
    std::unique_ptr<Ui::Screen>  m_ptr_scheduleSummaryScreen;
    std::unique_ptr<Ui::Screen>     m_ptr_UpdateCourseScreen;
    std::unique_ptr<Ui::Screen>     m_ptr_RemoveCourseScreen;
    
    std::unique_ptr<DB::DBConnector>  m_ptr_DBConnector;

};

#endif // endif