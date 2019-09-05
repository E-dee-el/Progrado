#ifndef ADD_COURSE_H
#define ADD_COURSE_H

#include"screen.h"

namespace Progrado {
namespace UI {
class add_course : public screen {
public:
    virtual ~add_course();
    virtual void print_instructions()const override;
    virtual void execute()const override;
private:

};

}
}

#endif