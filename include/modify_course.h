#ifndef MODIFY_COURSE_H
#define MODIFY_COURSE_H

#include"screen.h"

namespace Progrado {
namespace UI {
class modify_course : public screen {
public:
    virtual ~modify_course();
    virtual void print_instructions()const override;
    virtual void execute()const override;
private:

};

}
}

#endif