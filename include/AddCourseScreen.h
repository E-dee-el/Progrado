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

#include "Screen.h"

namespace Ui
{
  class AddCourseScreen;  
} 

class Ui::AddCourseScreen : public Ui::Screen{

public:
    AddCourseScreen();
    virtual ~AddCourseScreen();
    virtual int display()override;
    virtual int getUserInput()override;
    virtual int exitOrMoveBack()override;
    virtual int checkSuccess()override;
    

private: 
// private members go here

  int m_verify;
  int m_choice2;
  int m_checkExitOrMoveBack;

  std::unique_ptr<Progrado::Course> m_ptr_accessCourse;
  std::unique_ptr<Progrado::UserInterface> m_ptr_accessDBptr;
  std::shared_ptr<DB::DBConnector> m_ptr_DataBase;

};

#endif