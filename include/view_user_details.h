#ifndef VW_USER_H
#define VW_USER_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class view_user_details: public screen{
            public:
                view_user_details();
                ~view_user_details();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif