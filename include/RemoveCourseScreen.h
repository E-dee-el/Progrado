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
std::unique_ptr<Progrado::Course> m_ptr_accessCourse1;
std::unique_ptr<Progrado::UserInterface> m_ptr_accessDBptr;
std::shared_ptr<DB::DBConnector> m_ptr_DBconnector;


};

#endif