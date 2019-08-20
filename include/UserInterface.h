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
  
#include <memory>
#include<string>
#include<cstdlib>
#include<iostream>

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
#include"Progrado.h"



namespace Progrado
{
  class UserInterface;  
} 


typedef Progrado::UserInterface PrUs;  


class Progrado::UserInterface{

public:
 
    UserInterface();
    ~UserInterface();
    void setup();
    int run();
    int connectToDatabase();
    int disconnectFromDatabase();
    int instantiateScreen(std::unique_ptr<Ui::Screen> &, Progrado::Screen); 
    
    friend Ui::MainMenuScreen; 
    friend Ui::LoginScreen;
    friend Ui::CreateAccountScreen;
    friend Ui::AddCourseScreen;
    friend Ui::RemoveCourseScreen;
    friend Ui::UpdateCourseScreen;
    friend Ui::ScheduleSummaryScreen;                       
    friend Ui::ListAllCoursesScreen;
    friend Ui::LoginErrorScreen;    

private: 
    int m_selection;
    int m_displayChecker; 
    int m_instantiateChecker;

    std::unique_ptr<Ui::Screen> m_ptr_addCourseScreen; 
    std::unique_ptr<Ui::Screen> m_ptr_mainMenu;
    std::unique_ptr<Ui::Screen> m_ptr_loginScreen;
    std::unique_ptr<Ui::Screen> m_ptr_createAccountScreen; 
    std::unique_ptr<Ui::Screen> m_ptr_loginErrorScreen;
    std::unique_ptr<Ui::Screen> m_ptr_listAllCoursesScreen;
    std::unique_ptr<Ui::Screen> m_ptr_scheduleSummaryScreen;
    std::unique_ptr<Ui::Screen> m_ptr_UpdateCourseScreen;
    std::unique_ptr<Ui::Screen> m_ptr_RemoveCourseScreen;
    
    std::shared_ptr<DB::DBConnector>  m_ptr_DBConnector;

};

#endif // endif