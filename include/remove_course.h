#ifndef REM_COURSE_H
#define REM_COURSE_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class remove_course : public screen{
            public:
                remove_course();
                ~remove_course();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif