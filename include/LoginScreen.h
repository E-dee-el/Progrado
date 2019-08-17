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

class Ui::LoginScreen : public Ui::Screen{

public:
    LoginScreen();
    virtual ~LoginScreen();
    virtual void display()override;

private:
// private members go here




};

#endif