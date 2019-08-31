#ifndef MODIFY_COURSE_H
#define MODIFY_COURSE_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class modify_course : public screen{
            public:
                modify_course();
                ~modify_course();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif