/*
**************************************
*************PROGRADO*****************
**************************************
ScheduleSummaryScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"ScheduleSummaryScreen.h"
#include "Progrado.h"
#include"Course.h"
#include<iostream>


Ui::ScheduleSummaryScreen::ScheduleSummaryScreen()
{
    //default constructor
}

Ui::ScheduleSummaryScreen::~ScheduleSummaryScreen()
{
    //destructor
}

void Ui::ScheduleSummaryScreen::display()
{    
    std::cout << "Kindly press 1 to view your schedule summary\n";
    std::cout << "            -1 to go back to main menu\n";
    std::cout << "             0 exit\n";
}

int Ui::ScheduleSummaryScreen::getInput()
{
    int m_input;
    std::cin >> m_input;
    std::cin.ignore();

    return m_input;
}