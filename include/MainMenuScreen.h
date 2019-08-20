/*
**************************************
*************PROGRADO*****************
**************************************
MainMenuScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include"Screen.h"

namespace Ui
{
  class MainMenuScreen;  
} 

class Ui::MainMenuScreen : public Ui::Screen{

public:
    MainMenuScreen();
    virtual ~MainMenuScreen();
    virtual int display()override;
    virtual int getUserInput()override;
    virtual int exitOrMoveBack()override;
    virtual int checkSuccess()override;
    
private:
// private members go here
int m_choice;
int m_checkInstantiate;

std::unique_ptr<Progrado::UserInterface> m_ptr_accessUserInterface;
std::unique_ptr<Progrado::UserInterface> m_ptr_toAccessInstantiate;


};

#endif