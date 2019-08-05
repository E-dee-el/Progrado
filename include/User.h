
/*
**************************************
*************PROGRADO*****************
**************************************
User header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef USER_H
#define USER_H

#include<string>

namespace Progrado{
    class User;
}
// store user info in class instead of struct to hide info like password
class Progrado::User
{
    public:
        User();
        User(const std::string []);
        ~User();
        inline std::string get_lastName();
        inline std::string get_firstName();
        inline std::string get_yearInCollege();
        inline std::string get_userName();
        inline std::string get_password();
        inline std::string get_major();
        inline std::string get_minor();

    private:
        std::string m_lastName;
        std::string m_firstName;
        std::string m_yearInCollege;
        std::string m_userName;
        std::string m_password;
        std::string m_major;
        std::string m_minor;
        static const int m_stringArraylength = 7; // this refers to the constructor which accepts an array of 7 strings 
};

#endif