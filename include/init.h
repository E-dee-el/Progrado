#ifndef INIT_H
#define INIT_H

#include<memory>
#include<string>
#include<stdexcept>
#include"create_account.h"
#include"login.h"

namespace Progrado {

/*class init handles login & acct creation for 1st-timers*/
class init {
public:
    ~init();
    bool execute();
    bool is_new_user();
private:






};
}
#endif