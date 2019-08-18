/*
**************************************
*************PROGRADO*****************
**************************************
User header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */


#include"User.h"
#include <iostream>

// not safe , doesnt check for size 
// maybe we should be using std::array for this
Progrado::User::User(const std::vector<std::string>& t_user)
{      
    //call the copy constructor for std::vector
    m_userData = t_user;
}

// better use this constructor
Progrado::User::User
(
const std::string& t_lastName,
const std::string& t_firstName,
const std::string& t_yearInCollege,
const std::string& t_userName,
const std::string& t_major,
const std::string& t_minor,
const std::string& t_password
)
: m_userData(7)
{
    // 7-arg constructor
    // order is important!
    m_userData[lastName] = t_lastName;
    m_userData[firstName] = t_firstName;
    m_userData[yearInCollege] = t_yearInCollege;
    m_userData[userName] = t_userName;
    m_userData[major] = t_major;
    m_userData[minor] = t_minor;
    m_userData[password] = t_password;

}

bool Progrado::User::setUp_account()
{
    std::cout << "Please enter your last name\n"; getline(std::cin, m_lastName);
    std::cout << "Please enter your first name\n"; getline(std::cin, m_firstName);
    std::cout << "Please enter your year in college\n"; getline(std::cin, m_yearInCollege);
    std::cout << "Please enter your major/anticipated major\n"; getline(std::cin, m_major);
    std::cout << "Please enter your minor/anticipated minor\n"; getline(std::cin, m_minor);
    std::cout << "Please enter a username\n"; getline(std::cin, m_username);
    std::cout << "Please enter a password\n"; getline(std::cin, m_password);

   //ensure that entered value are stored
    if(std::cin.good())
    {
        return 1;
    }
    return 0;
}

Progrado::User::~User()
{


}

int Progrado::User::get_countUserDetails()const { return m_userData.size();}

const std::string& Progrado::User::operator [] (int t_idx)const {return m_userData[t_idx];}

std::string Progrado::User::get_BindParam(int idx) const {return m_BindParams[idx];}

// these are here a back up, if you will. the overloaded [] operator is preferred
 std::string Progrado::User::get_lastName() const {return m_userData[lastName];}

 std::string Progrado::User::get_firstName() const {return m_userData[firstName];}

 std::string Progrado::User::get_yearInCollege() const { return m_userData[yearInCollege];}

 std::string Progrado::User::get_userName()const {return m_userData[userName];}

 std::string Progrado::User::get_password() const {return m_userData[password];}

 std::string Progrado::User::get_major() const {return m_userData[major];}

 std::string Progrado::User::get_minor() const {return m_userData[minor];}
