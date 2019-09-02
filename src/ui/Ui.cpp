
#include"Ui.h"
#include"DBConnector.h"

using namespace Progrado;
using DB::DBConnector;

Ui::Ui(): m_ptr_db(nullptr), m_ptr_home(nullptr), m_ptr_init(nullptr) {};
Ui::~Ui() {};

void Ui::setup()
{ 
    print_welcome_message();
    m_ptr_db = std::make_unique<DBConnector>(); /*connection should be established automatically*/
}

void Ui::run()

{   m_ptr_init = std::make_unique<init>();
    m_ptr_init->execute();

    m_ptr_home = std::make_unique<home>();
    m_ptr_home->execute(); /*transfer control to class home*/

}
