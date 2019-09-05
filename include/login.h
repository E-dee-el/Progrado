#ifndef LOGIN_H
#define LOGIN_H

namespace Progrado {
/*class login handles a login session*/
/*it recieves from and returns control to init*/
class login {
public:
    login();
    ~login();
    void prompt_user()const;
    void execute()const;
private:

}; //login
} // namespace progrado

#endif

