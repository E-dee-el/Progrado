/*
**************************************
*************PROGRADO*****************
**************************************
UpdateCourseScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef UPDATE_COURSE_H
#define UPDATE_COURSE_H

#include"Screen.h"

namespace Ui
{
  class UpdateCourseScreen;  
} 

class Ui::UpdateCourseScreen : public Ui::Screen{

public:
    UpdateCourseScreen();
    virtual ~UpdateCourseScreen();
    virtual void display()override;
    Progrado::Course getInput();

private:
// private members go here




};

#endif