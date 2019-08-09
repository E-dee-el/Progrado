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

Progrado::User::User():
m_lastName("Not set"),
m_firstName("Not set"),
m_yearInCollege("Not set"),
m_userName("Not set"),
m_password("admin"),
m_major("Undecided"),
m_minor("none")
{
    // default constructor
}

Progrado::User::User
(
const std::string& t_lastName,
const std::string& t_firstName,
const std::string& t_yearInCollege,
const std::string& t_userName,
const std::string& t_major,
const std::string& t_minor,
const std::string& t_password
):
m_lastName(t_lastName),
m_firstName(t_firstName),
m_yearInCollege(t_yearInCollege),
m_userName(t_userName),
m_password(t_password),
m_major(t_major),
m_minor(t_minor)


{
    // 7-arg constructor

}

Progrado::User::~User()
{


}

 std::string Progrado::User::get_lastName() const {return m_lastName;}

 std::string Progrado::User::get_firstName() const {return m_firstName;}

 std::string Progrado::User::get_yearInCollege() const { return m_yearInCollege;}

 std::string Progrado::User::get_userName()const {return m_userName;}

 std::string Progrado::User::get_password() const {return m_password;}

 std::string Progrado::User::get_major() const {return m_major;}

 std::string Progrado::User::get_minor() const {return m_minor;}
