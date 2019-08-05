
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

class Progrado::User
{
    public:
        User();
        User(const std::string []);
        ~User();

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