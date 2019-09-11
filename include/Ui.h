
#ifndef UI_H
#define UI_H

#include<memory>
#include"home.h"
#include"init.h"
#include"DBConnector.h"
#include"screen.h"

/*namespace Progrado contains all progrado-specific classes*/
namespace Progrado {
/*class Ui manages the entire application; it is the main app object*/
class Ui {
public:
    Ui();
    ~Ui();
    void setup();                         /*pass control to class init*/
    void run();                           /*run main application logic*/
    void print_welcome_message();         /*prints welcome or help message*/
    int process_input(const std::string& s);
    void print_help_info();
    void initialize_screen(const std::shared_ptr<UI::screen>& t_scrn)const; 



private:

    std::unique_ptr<init> m_ptr_init;    /*smart pointer to an init instance*/
    std::unique_ptr<home> m_ptr_home;    /*smart pointer to a home instance*/
    std::unique_ptr<DB::DBConnector> m_ptr_db; /*database connection handler*/


}; // class Ui

}// namespace Progrado

#endif

