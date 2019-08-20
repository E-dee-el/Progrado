/*
**************************************
*************PROGRADO*****************
**************************************
ScheduleSummaryScreen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef SCHEDULE_SUMMARY_H
#define SCHEDULE_SUMMARY_H

#include"UserInterface.h" 

namespace Ui
{
  class ScheduleSummaryScreen;  
} 

class Ui::ScheduleSummaryScreen : public Ui::Screen{

public:
    ScheduleSummaryScreen();
    virtual ~ScheduleSummaryScreen();
    virtual int display()override;
    virtual int getUserInput()override;
    virtual int exitOrMoveBack()override;
    virtual int checkSuccess()override;
    

private:
// private members go here
int m_choice;
int m_choice2;
int m_checkExitOrMoveBack;

std::unique_ptr<Progrado::UserInterface> m_ptr_accessDBptr;
std::shared_ptr<DB::DBConnector> m_ptr_toDBconnector; 



};

#endif