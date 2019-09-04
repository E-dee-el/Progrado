#ifndef VIEW_COURSE_H
#define VIEW_COURSE_H

#include"screen.h"

namespace Progrado{
    namespace UI{
        class view_course :public screen{
            public:
                virtual ~view_course();
                virtual void print_instructions()const override;
                virtual void execute()const override;
            private:

        };

    }
}

#endif