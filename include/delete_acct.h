#ifndef DELETE_ACCT_H
#define DELETE_ACCT_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class delete_acct : public screen{
            public:
                virtual ~delete_acct();
                virtual void print_instructions()const override;
                virtual void execute()const override;
            private:

        };

    }
}

#endif