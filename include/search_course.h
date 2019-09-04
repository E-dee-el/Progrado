#ifndef SRCH_COURSE_H
#define SRCH_COURSE_H

#include"screen.h"
namespace Progrado{
    namespace UI{
        class search_course : public screen{
            public:
                virtual ~search_course();
                virtual void print_instructions()const override;
                virtual void execute()const override;
            private:

        };

    }
}

#endif