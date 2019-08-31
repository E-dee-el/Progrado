#ifndef DELETE_ACCT_H
#define DELETE_ACCT_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class delete_acct : public screen{
            public:
                delete_acct();
                ~delete_acct();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif