
#ifndef CREATE_ACCT_H
#define CREATE_ACCT_H


#include"screen.h"

namespace Progrado {
namespace UI {
class create_account : public screen {
public:
    virtual ~create_account();
    virtual void print_instructions()const override;
    virtual void execute()const override;
private:

};

}


}// namespace progrado

#endif