#ifndef MODIFY_USER_H
#define MODIFY_USER_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class modify_user_details : public screen{
            public:
                virtual ~modify_user_details();
                virtual void print_instructions()const override;
                virtual void execute()const override;
            private:

        };

    }
}

#endif