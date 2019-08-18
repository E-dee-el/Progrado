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
    virtual void display()override;

private:
// private members go here




};

#endif