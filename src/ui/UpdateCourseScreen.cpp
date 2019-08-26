/*
**************************************
*************PROGRADO*****************
**************************************
UpdateCourseScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"UpdateCourseScreen.h"
#include "Progrado.h"
#include"Course.h"
#include<iostream>  
#include <memory>


Ui::UpdateCourseScreen::UpdateCourseScreen()
{
    //default constructor
}

Ui::UpdateCourseScreen::~UpdateCourseScreen()
{
    //destructor
}

void Ui::UpdateCourseScreen::display()
{

}

Progrado::Course Ui::UpdateCourseScreen::getOldCourse()
{   std::string m_courseID;

    std::cout << " Please enter the course ID for the course you would like to update\n";
    std::getline(std::cin,m_courseID);

    Progrado::Course oldCourse("Not set","Not set","Not set",
            m_courseID, "Not set");

    return oldCourse;

}

Progrado::Course Ui::UpdateCourseScreen::getNewCourse()
{   std::string m_courseID;
    std::string m_course_name;
    std::string m_semesterOffered;
    std::string m_yearOffered;
    std::string m_course_type;
    int m_numCredits;

    std::cout << "Please enter the following details for the course you would like to update\n";
    std::cout << " Please enter the course name (e.g Computer Programming)\n";
    std::getline(std::cin,m_course_name);
    std::cin.ignore();
    std::cout << " Please enter the semester in which you are taking the course (Fall,Spring, or J-Term)\n";
    std::getline(std::cin,m_semesterOffered);
    std::cin.ignore();
    std::cout << " Please enter the yeam_instantiateChecker = this->instantiateScreen(m_ptr_createAccountScreen, create_account);r in which you are taking the course\n";
    std::getline(std::cin,m_yearOffered);
    std::cin.ignore();
    std::cout << " Please enter the course ID (e.g. ENGR 1001)\n";
    std::getline(std::cin,m_courseID);
    std::cin.ignore();
    std::cout << " Please enter the course type (major, minor, general elective, physical education, audit)\n";
    std::getline(std::cin,m_course_type);
    std::cin.ignore();
    std::cout << " Please enter number of course credit (2 or 4)\n";
    std::cin >> m_numCredits;
    std::cin.ignore(); 

    Progrado::Course newCourse(m_course_name,m_semesterOffered,
                                    m_yearOffered,m_courseID,
                                    m_course_type,m_numCredits);

    return newCourse;

}