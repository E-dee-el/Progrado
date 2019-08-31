#ifndef RET_USER_H
#define RET_USER_H


#include"screen.h"

namespace Progrado{
    namespace UI{
        class retrieve_user_details : public screen{
            public:
                retrieve_user_details();
                ~retrieve_user_details();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif