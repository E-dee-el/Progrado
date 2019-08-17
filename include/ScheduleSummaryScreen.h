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

#include"Screen.h"

namespace Ui
{
  class ScheduleSummaryScreen;  
} 

class Ui::ScheduleSummaryScreen : public Ui::Screen{

public:
    ScheduleSummaryScreen();
    virtual ~ScheduleSummaryScreen();
    virtual void display()override;

private:
// private members go here




};

#endif