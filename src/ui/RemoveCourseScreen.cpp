/*
**************************************
*************PROGRADO*****************
**************************************
RemoveCourseScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"RemoveCourseScreen.h"
#include "Progrado.h"
#include"Course.h"
#include<iostream>
#include<memory>

Ui::RemoveCourseScreen::RemoveCourseScreen()
{
    //default constructor
}

Ui::RemoveCourseScreen::~RemoveCourseScreen()
{
    //destructor
}

void Ui::RemoveCourseScreen::display()
{
   std::cout << "Please provide the course ID for the course you would like to remove\n";
                            
}

Progrado::Course Ui::RemoveCourseScreen::getInput()
{   std::string m_courseID;
    
    std::getline(std::cin,m_courseID);
    
    Progrado::Course courseToRemove("Not set","Not set","Not set",
            m_courseID, "Not set");
    
    return courseToRemove;
}