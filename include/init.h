#ifndef INIT_H
#define INIT_H

#include<memory>
#include<string>
#include<stdexcept>
#include"create_account.h"
#include"login.h"

namespace Progrado{

/*class init handles login & acct creation for 1st-timers*/
    class init{
        public:
            init();
            ~init();
            void execute();
        private:
            std::unique_ptr<create_account> m_ptr_create_acct;  /*handler to create acct screen*/
            std::unique_ptr<login> m_ptr_login;                 /*handler to login screen*/
            

                


    };
}
#endif