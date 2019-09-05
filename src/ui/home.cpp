#include"home.h"

using namespace Progrado;
using namespace Progrado::UI;


home::home() {};
home::~home() {};

void home::initialize_screen(const UI::screen& t_scrn)const
{
    t_scrn.print_instructions();
    t_scrn.execute();
}

void home::display_home_options()
{
    /*needs fixing*/
    std::cout <<
              "Options: \n"
              "0. Add Course\n"
              "1. Modify Course\n"
              "2. View Courses\n"
              "3. Search Course\n"
              "4. Delete Course\n"
              "5. Retrieve your details\n"
              "6. Modify your details\n";
}
void home::execute()
{
    display_home_options();

    int choice;
    do {

        std::cin >> choice;
        std::cin.ignore();

        /*initiallize the appropriate screen depending on user input*/
        /*Note: artificial scopes are within this switch statements!*/
        /*without these braces, the code will not compile!*/
        switch(choice)
        {
        case add_course_screen:

        {
            auto add_crs_scrn = std::unique_ptr<UI::screen>(new add_course());
            initialize_screen(*add_crs_scrn);
        }
        break;

        case modify_course_screen:
        {
            auto modify_crs_scrn = std::unique_ptr<UI::screen>(new modify_course());
            initialize_screen(*modify_crs_scrn);
        }
        break;

        case view_course_screen:
        {
            auto view_crs_scrn = std::unique_ptr<UI::screen>(new view_course());
            initialize_screen(*view_crs_scrn);
        }
        break;

        case search_course_screen:
        {
            auto search_crs_scrn = std::unique_ptr<UI::screen>(new search_course());
            initialize_screen(*search_crs_scrn);
        }
        break;

        case remove_course_screen:
        {
            auto remove_crs_scrn = std::unique_ptr<UI::screen>(new remove_course());
            initialize_screen(*remove_crs_scrn);
        }
        break;

        case retrieve_user_details_screen:
        {
            auto retrieve_user_scrn = std::unique_ptr<UI::screen>(new retrieve_user_details());
            initialize_screen(*retrieve_user_scrn);
        }
        break;

        case modify_user_screen:
        {
            auto modify_usr_scrn = std::unique_ptr<UI::screen>(new modify_user_details());
            initialize_screen(*modify_usr_scrn);
        }
        break;


        default:
            return;
        }// switch(choice)

        display_home_options();
        std::cout << "selection: ";
        std::cin >> choice;

    } while(choice != -1); // end do-while


}