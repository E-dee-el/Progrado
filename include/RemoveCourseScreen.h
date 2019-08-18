/*
**************************************
*************PROGRADO*****************
**************************************
RemoveCourseScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef REMOVE_COURSE_H
#define REMOVE_COURSE_H
  
#include"Screen.h"

namespace Ui
{
  class RemoveCourseScreen;  
} 

class Ui::RemoveCourseScreen : public Ui::Screen{

public:
    RemoveCourseScreen();
    virtual ~RemoveCourseScreen();
    virtual void display()override;

private:
// private members go here




};

#endif