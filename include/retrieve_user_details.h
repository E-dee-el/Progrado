#ifndef RET_USER_H
#define RET_USER_H


#include"screen.h"

namespace Progrado{
    namespace UI{
        class retrieve_user_details : public screen{
            public:
                virtual ~retrieve_user_details();
                virtual void print_instructions()const override;
                virtual void execute()const override;
            private:

        };

    }
}

#endif