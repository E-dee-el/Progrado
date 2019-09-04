#ifndef VW_USER_H
#define VW_USER_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class view_user_details: public screen{
            public:
                virtual ~view_user_details();
                virtual void print_instructions()const override;
                virtual void execute()const override;
            private:

        };

    }
}

#endif