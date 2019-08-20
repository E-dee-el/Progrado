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
    virtual int display()override;
    virtual int getUserInput()override;
    virtual int exitOrMoveBack()override;
    virtual int checkSuccess()override;


private:
// private members go here
int m_verify;
int m_verify1;
int m_choice2;
int m_checkExitOrMoveBack;

std::unique_ptr<Progrado::UserInterface> m_ptr_accessDBptr;
std::unique_ptr<Progrado::User> m_ptr_access_User;
std::shared_ptr<DB::DBConnector> m_ptr_access_toAccessDatabase;


};

#endif