#ifndef ADD_COURSE_H
#define ADD_COURSE_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class add_course : public screen{
            public:
                add_course();
                ~add_course();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif