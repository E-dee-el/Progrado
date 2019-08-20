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

#include"Screen.h"

namespace Ui
{
  class LoginErrorScreen;  
} 

class Ui::LoginErrorScreen : public Ui::Screen{

public:
    LoginErrorScreen();
    virtual ~LoginErrorScreen();
    virtual int display()override;
    virtual int getUserInput()override;
    virtual int exitOrMoveBack()override;
    virtual int checkSuccess()override;
private:
// private members go here




};

#endif