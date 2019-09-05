
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
#include<vector>

namespace Progrado {
class User;
}
// store user info in class instead of struct to hide info like password
class Progrado::User
{
public:
    User(const std::vector<std::string>&);
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
    std::string get_BindParam(int)const;
    int get_countUserDetails()const;
    const std::string& operator [] (int)const;
    int get_numUserDetails()const;


private:

    enum   // declares these as integral constants, starting from 0
    {
        lastName,
        firstName,
        yearInCollege,
        userName,
        password,
        major,
        minor
    };

    std::vector<std::string> m_userData;
    const std::vector<std::string> m_BindParams = {":lastName", ":firstName", ":yearInCollege",
                                                   ":userName", ":password", ":major", ":minor"
                                                  };


};

#endif