
#include"Ui.h"
#include"DBConnector.h"
#include"add_course.h"
#include"screen.h"
#include<cstdlib>
#include<string>
#include<chrono>
#include<ctime>

using namespace Progrado;
using namespace Progrado::UI;
using DB::DBConnector;
using std::chrono::system_clock;


Ui::Ui(): m_ptr_init(nullptr), m_ptr_home(nullptr), m_ptr_db(nullptr) {};
Ui::~Ui() {};

void Ui::print_welcome_message()
{
    const std::time_t curr_time = system_clock::to_time_t(system_clock::now());
    std::cout <<"Progrado version 0.1\n"
              << std::ctime(&curr_time)
              << "Enter 'help' for usage hints.\n";


}

void Ui::print_help_info()
{
    std::cout <<"\nusage\n"
              "-- Enter 'help' to display this page\n"
              "-- Enter 'add-course' to add a course\n"
              "-- Enter 'search-course' to search a course\n"
              "-- Enter 'view-courses' to view courses\n"
              "-- Enter 'modify-course' to modify a course\n"
              "-- Enter 'remove-course' to delete a course\n"
              "-- Enter 'exit' to quit the program\n";

}

void Ui::initialize_screen(const std::shared_ptr<screen>& t_scrn)const
{
    t_scrn->print_instructions();
    t_scrn->execute();
}
void Ui::setup()
{
    print_welcome_message();
    m_ptr_db = std::make_unique<DBConnector>(); /*connection should be established automatically*/
}

int Ui::process_input(const std::string& s)
{
    if(s == "exit")
    {
        return PROG_EXIT;
    }
    else if(s == "help")
    {
        print_help_info();
    }
    else if (s == "add-course")
    {
        // transfer control to add-course
        auto add = std::shared_ptr<UI::screen>(new add_course());
        initialize_screen(add);
    }
    else if (s == "search-course")
    {
        auto search = std::shared_ptr<UI::screen>(new search_course());
        initialize_screen(search);
    }
    else if(s == "view-courses")
    {
        auto view = std::shared_ptr<UI::screen>(new view_course());
        initialize_screen(view);
    }
    else if(s == "modify-course")
    {
        auto modify = std::shared_ptr<UI::screen>(new modify_course());
        initialize_screen(modify);        
    }
    else if(s == "remove-course")
    {
        auto remove = std::shared_ptr<UI::screen>(new remove_course());
        initialize_screen(remove);        
    }
    else
    {
        std::cout << "\nInvalid command\n";
        std::cout << "Enter 'help' for usage hints.\n";
    }

    return SUCCESS;
}



void Ui::run()

{   m_ptr_init = std::make_unique<init>();

    if(!m_ptr_init->execute()) return; /*transfer control to init*/

    print_welcome_message();

    // m_ptr_home = std::make_unique<home>();
    //m_ptr_home->execute(); /*transfer control to class home*/

    /*loop and wait for command input*/
    for(std::string input_cmd;
            std::cout << "\nprogrado >>> " && std::getline(std::cin, input_cmd); )
    {
        if(!input_cmd.empty())
        {
            if(process_input(input_cmd) == PROG_EXIT) return;
        }
    }

}
