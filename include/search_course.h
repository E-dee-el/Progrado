#ifndef SRCH_COURSE_H
#define SRCH_COURSE_H

#include"screen.h"
namespace Progrado{
    namespace UI{
        class search_course : public screen{
            public:
                search_course();
                ~search_course();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif