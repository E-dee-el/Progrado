/*
**************************************
*************PROGRADO*****************
**************************************
AddCourseScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef ADD_COURSE_H
#define ADD_COURSE_H

namespace Ui
{
  class AddCourseScreen;  
} 

class Ui::AddCourseScreen : public Ui::Screen{

public:
    AddCourseScreen();
    virtual ~AddCourseScreen();
    virtual void display()override;

private:
// private members go here



};

#endif