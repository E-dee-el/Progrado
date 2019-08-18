/*
**************************************
*************PROGRADO*****************
**************************************
CreateAccountScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef CREATE_ACCT_H
#define CREATE_ACCT_H

#include"Screen.h"

namespace Ui
{
  class CreateAccountScreen;  
} 

class Ui::CreateAccountScreen : public Ui::Screen{

public:
    CreateAccountScreen();
    virtual ~CreateAccountScreen();
    virtual void display()override;

private:
// private members go here
Progrado::User *m_user;


};

#endif