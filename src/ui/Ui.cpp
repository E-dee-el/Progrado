
#include"Ui.h"
#include"DBConnector.h"
#include<cstdlib>

using namespace Progrado;
using DB::DBConnector;

Ui::Ui(): m_ptr_init(nullptr), m_ptr_home(nullptr), m_ptr_db(nullptr) {};
Ui::~Ui() {};

void Ui::print_welcome_message()
{
    std::cout <<
              "*********************\n"
              "*                   *\n"
              "*WELCOME TO PROGRADO*\n"
              "*                   *\n"              
              "*********************\n"; 


}
void Ui::setup()
{
    print_welcome_message();
    m_ptr_db = std::make_unique<DBConnector>(); /*connection should be established automatically*/
}

void Ui::run()

{   m_ptr_init = std::make_unique<init>();

    if(!m_ptr_init->execute()) return; /*transfer control to init*/

    m_ptr_home = std::make_unique<home>();
    m_ptr_home->execute(); /*transfer control to class home*/

}
