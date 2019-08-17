/*
**************************************
*************PROGRADO*****************
**************************************
ListAllCoursesScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef LIST_ALL_COURSES_H
#define LIST_ALL_COURSES_H

#include"Screen.h"

namespace Ui
{
  class ListAllCoursesScreen;  
} 

class Ui::ListAllCoursesScreen : public Ui::Screen{

public:
    ListAllCoursesScreen();
    virtual ~ListAllCoursesScreen();
    virtual void display()override;

private:
// private members go here




};

#endif