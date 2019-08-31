#ifndef LOGIN_H
#define LOGIN_H

namespace Progrado{
    /*class login handles a login session*/
    /*it recieves from and returns control to Ui*/
    class login{
        public:
            login();
            ~login();
            void prompt_user();
            void verify_details();
            void execute();
        private:

    }; //login
} // namespace progrado

#endif

