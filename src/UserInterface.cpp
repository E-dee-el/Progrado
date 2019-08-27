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
void Progrado::UserInterface::login(int t_selection)
{
    while(t_selection != 1 || t_selection != 2)
    {
    
        std::cout << "Invalid choice\n";
        std::cin >> t_selection;
        std::cin.ignore();

        if(t_selection == 0) return;
    }

        if(t_selection == 1) 
        {
            m_ptr_loginScreen = std::make_unique<Ui::LoginScreen>();
            m_ptr_loginScreen->display();
        
            bool chk = m_ptr_DBConnector->verifyUserCredentials(
                m_ptr_loginScreen->getUserName(),
                m_ptr_loginScreen->getPassword()
                );
            int login_count = 0;
            while(!chk)
            {   

                if(login_count > 3)
                {
                    std::cout << "Too many failed attempts! Closing Progrado\n";
                    return;
                }
                chk = m_ptr_DBConnector->verifyUserCredentials(
                m_ptr_loginScreen->getUserName(),
                m_ptr_loginScreen->getPassword()
                ); 

                login_count++;
            }    
        }

}

void Progrado::UserInterface::setup()
{
    // set up application 

    //print welcome message

    m_ptr_DBConnector = std::make_unique<DB::DBConnector>();
    

}
void Progrado::UserInterface::run()
{
    //run the application/the user interface
try{
    std::cout << "Kindly enter 1 to login, and 2 to create an account\n";
    int l_selection;
    std::cin >> l_selection;
    std::cin.ignore();

    while(l_selection != 1 || l_selection != 2)
    {
    
        std::cout << "Invalid choice\n";
        std::cin >> l_selection;
        std::cin.ignore();

        if(l_selection == 0) return;
    }

        if(l_selection == 1) login(l_selection);
        else if(l_selection == 2)
        {
             m_ptr_createAccountScreen = std::make_unique<Ui::CreateAccountScreen>();
             m_ptr_createAccountScreen->display();
             
            {   
                dynamic_cast<Ui::AddCourseScreen*>(m_ptr_addCourseScreen.get());
                auto l_new_user = 
                std::make_unique<Progrado::User>(new Progrado::User(m_ptr_createAccountScreen->getInput()));
                m_ptr_DBConnector->addNewUser(*l_new_user);
            } // artificial scope to delete l_new_user
            
            // Log the user in here

            login(l_selection);
        }

 
    



} // end try
catch(std::runtime_error err)
{
    std::cerr << err.what() << std::endl;
} // end catch
} // run


void Progrado::UserInterface::executeScreen(std::unique_ptr<Ui::Screen> & screen_ptr,int t_screen) 
{ 
   
   switch (t_screen)
    {   
        case Progrado::add_course:  
            {
                // AddCourseScreen

                screen_ptr.reset(new Ui::AddCourseScreen);

                std::unique_ptr<Ui::AddCourseScreen> l_AddCourseScreen(dynamic_cast<Ui::AddCourseScreen*>(screen_ptr.get())); 

                l_AddCourseScreen->display();
                l_AddCourseScreen->getInput();


                break;
            }
        
        case Progrado::Screen::remove_course:   
            {
                // RemoveCourseScreen
                
                screen_ptr.reset(new Ui::RemoveCourseScreen);
                std::unique_ptr<Ui::RemoveCourseScreen> l_RemoveCourseScreen(dynamic_cast<Ui::RemoveCourseScreen*>(screen_ptr.get()));

                l_RemoveCourseScreen->display();
                l_RemoveCourseScreen->getInput();
                break;
            }
        
        case Progrado::Screen::update_course:
            {
            // UpdateCourseScreen
            
            screen_ptr.reset(new Ui::UpdateCourseScreen);
            std::unique_ptr<Ui::UpdateCourseScreen> l_UpdateCourseScreen(dynamic_cast<Ui::UpdateCourseScreen*>(screen_ptr.get()));
            l_UpdateCourseScreen->display();
            l_UpdateCourseScreen->getOldCourse();
            l_UpdateCourseScreen->getNewCourse();
            break;
            }

        case Progrado::Screen::list_course:
            {
            // ListAllCoursesScreen

            screen_ptr.reset(new Ui::ListAllCoursesScreen);
            std::unique_ptr<Ui::ListAllCoursesScreen> l_ListCourseScreen(dynamic_cast<Ui::ListAllCoursesScreen*>(screen_ptr.get()));
            l_ListCourseScreen->display();
            l_ListCourseScreen->getInput();
            break;

            }

        case Progrado::Screen::schedule_summary:
            {
            // ScheduleSummaryScreen

            screen_ptr.reset(new Ui::ScheduleSummaryScreen);
            std::unique_ptr<Ui::ScheduleSummaryScreen> l_scheduleSummaryScreen(dynamic_cast<Ui::ScheduleSummaryScreen*>(screen_ptr.get()));
            l_scheduleSummaryScreen->display();
            l_scheduleSummaryScreen->getInput();
            break;

            } 

        case login_error:
            {
                // LoginErrorScreen

                screen_ptr.reset(new Ui::LoginErrorScreen);
                std::unique_ptr<Ui::LoginErrorScreen> l_loginErrorScreen(dynamic_cast<Ui::LoginErrorScreen*>(screen_ptr.get()));
                l_loginErrorScreen->display();
                break;
            }

        case create_account:
            {
                // CreateAccountScreen

                screen_ptr.reset(new Ui::CreateAccountScreen);
                std::unique_ptr<Ui::CreateAccountScreen> l_createAccountScreen(dynamic_cast<Ui::CreateAccountScreen*>(screen_ptr.get()));
                l_createAccountScreen->display();
                l_createAccountScreen->getInput();
                break;
            }

        case main_menu:
            {
                // MainMenuScreen

                screen_ptr.reset(new Ui::MainMenuScreen);
                std::unique_ptr<Ui::MainMenuScreen> l_mainMenuScreen(dynamic_cast<Ui::MainMenuScreen*>(screen_ptr.get()));
                l_mainMenuScreen->display();
                l_mainMenuScreen->getSelection();
                break;
            }

            
        default:
        break;


    }
}