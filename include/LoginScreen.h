/*
**************************************
*************PROGRADO*****************
**************************************
LoginScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef LOGIN_H
#define LOGIN_H

#include"Screen.h"

namespace Ui
{
  class LoginScreen;  
} 

class Ui::LoginScreen : public Ui::Screen
{

public:
    LoginScreen();
    virtual ~LoginScreen();
    virtual int display()override;
    virtual int getUserInput()override;
    virtual int exitOrMoveBack()override;
    virtual int checkSuccess()override;
private:
// private members go here
int m_attempts;
bool m_check_credentials;

std::shared_ptr<DB::DBConnector> m_ptr_toVerify;
std::unique_ptr<Progrado::UserInterface> m_ptr_accessDBptr;

};


#endif