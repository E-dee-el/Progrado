
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
        User(const std::string&, const std::string&, const std::string&,
                const std::string&, const std::string&, const std::string&, const std::string&); // 7-arg constructor
        ~User();
          std::string get_lastName()const;
          std::string get_firstName()const;
          std::string get_yearInCollege()const;
          std::string get_userName()const;
          std::string get_password()const;
          std::string get_major()const;
          std::string get_minor()const;

    private:
        std::string m_lastName;
        std::string m_firstName;
        std::string m_yearInCollege;
        std::string m_userName;
        std::string m_password;
        std::string m_major;
        std::string m_minor;
        
};

#endif