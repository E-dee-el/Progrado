/*
**************************************
*************PROGRADO*****************
**************************************
AddCourseScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"AddCourseScreen.h"
<<<<<<< HEAD
#include "Progrado.h"
=======
#include"Progrado.h"
>>>>>>> 739bf89f7601565aafb6da478f4b77737491cae9
#include"Course.h"
#include<iostream>


Ui::AddCourseScreen::AddCourseScreen()
{
    //default constructor
}

Ui::AddCourseScreen::~AddCourseScreen()
{
    //destructor
}

void Ui::AddCourseScreen::display()
{
    std::cout << "****************\nADD COURSE SCREEN\n*******************";
    std::cout << "Add a course to the Database here\n";
}

Progrado::Course Ui::AddCourseScreen::getInput()
{   
    std::string name,id,sem,year,type;
    int credits;

    std::cout << "Please Enter the following information to add a new course:\n";
    std::cout << "Course Name: "; std::getline(std::cin, name);
    std::cout << "Course ID: "; std::getline(std::cin, id);
    std::cout << "Semester: "; std::getline(std::cin,sem);
    std::cout << "Year (e.g. Sophomore): "; std::getline(std::cin, year);
    std::cout << "Course type (Major, Minor, Elective, Core): "; std::getline(std::cin, type);
    std::cout << "Course credits: "; std::cin >> credits; 
    std::cin.ignore();

    return Progrado::Course(name,id,type, sem, year, credits);


}