#include"home.h"



using namespace Progrado;

void home::execute()
{
    display_home_options();

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    
   do{   
            int choice;
            std::cin >> choice;
            std::cin.ignore();

        switch(choice)
        {
        case add_course_screen:
            
        case modify_course_screen:
            /*transfer control to modify_course_screen*/
        case view_course_screen: 
            /*transfer control to view_course_screen*/ 
        case search_course_screen:
            /*transfer control to search_course_screen*/
        case remove_course_screen:
            /*transfer control to remove_course_screen*/
        case retrieve_user_details_screen:
            /*transfer control to retrieve_user_details_screen*/
        case modify_user_screen:
            /*transfer control to modify_user_screen*/            
  
        default:
            /* print err msg or just transfer control to view_course_screen */                 
        }// switch(choice)

    }while(choice != -1); // end do-while
    

}