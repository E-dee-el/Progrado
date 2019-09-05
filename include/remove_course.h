#ifndef REM_COURSE_H
#define REM_COURSE_H

#include"screen.h"

namespace Progrado {
namespace UI {
class remove_course : public screen {
public:
    virtual ~remove_course();
    virtual void print_instructions()const override;
    virtual void execute()const override;
private:

};

}
}

#endif