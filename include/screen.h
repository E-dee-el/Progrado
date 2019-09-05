#ifndef SCREEN_H
#define SCREEN_H

/*screen class from which al screens derive; it simplifies home::execute()*/
namespace Progrado {
namespace UI {
class screen {
public:
    virtual ~screen() = 0;
    virtual void print_instructions()const;
    virtual void execute()const;

};
}
}

#endif