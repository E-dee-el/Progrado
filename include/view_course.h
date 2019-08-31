#ifndef VIEW_COURSE_H
#define VIEW_COURSE_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class view_course :public screen{
            public:
                view_course();
                ~view_course();
                virtual void print_instructions()const;
                virtual void execute()const;
            private:

        };

    }
}

#endif