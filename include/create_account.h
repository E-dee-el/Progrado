
#ifndef CREATE_ACCT_H
#define CREATE_ACCT_H


#include"screen.h"

namespace Progrado{
    namespace UI{
        class create_account : public screen{
            public:
                create_account();
                ~create_account();
                virtual void print_instructions()const;
                virtual void execute()const; 
            private:

    };    

    }


}// namespace progrado

#endif