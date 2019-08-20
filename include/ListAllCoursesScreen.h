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
    virtual int display()override;
    virtual int getUserInput()override;
    virtual int exitOrMoveBack()override;
    virtual int checkSuccess()override;

private:
// private members go here
int m_choice;
int m_choice2;
int m_checkExitOrMoveBack;
 
std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;
std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;
std::shared_ptr<DB::DBConnector> m_ptr_accessListAllCourse;
std::unique_ptr<Progrado::UserInterface> m_ptr_accessDBptr;

};

#endif