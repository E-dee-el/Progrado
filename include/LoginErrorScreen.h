/*
**************************************
*************PROGRADO*****************
**************************************
LoginErrorScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef LOGIN_ERROR_H
#define LOGIN_ERROR_H

namespace Ui
{
  class LoginErrorScreen;  
} 

class Ui::LoginErrorScreen : public Ui::Screen{

public:
    LoginErrorScreen();
    virtual ~LoginErrorScreen();
    virtual void display()override;

private:
// private members go here




};

#endif