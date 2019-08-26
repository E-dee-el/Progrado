/*
**************************************
*************PROGRADO*****************
**************************************
ListAllCoursesScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"ListAllCoursesScreen.h"
#include "Progrado.h"
#include"Course.h"
#include<iostream>

Ui::ListAllCoursesScreen::ListAllCoursesScreen()
{
    //default constructor
}

Ui::ListAllCoursesScreen::~ListAllCoursesScreen()
{
    //destructor
}

void Ui::ListAllCoursesScreen::display()
{
    std::cout << "Please Enter what semester's courses you would like to list\n";
    std::cout << "       Enter 1 for Freshman Fall\n";
    std::cout << "       Enter 2 for Freshman J-Term\n";
    std::cout << "       Enter 3 for Freshman Spring\n";
    std::cout << "       Enter 4 for Freshman Summer\n";
    std::cout << "       Enter 5 for Sophomore Fall\n";
    std::cout << "       Enter 6 for Sophomore J-Term\n";
    std::cout << "       Enter 7 for Sophomore Spring\n";
    std::cout << "       Enter 8 for Sophomore Summer\n";
    std::cout << "       Enter 9 for Junior Fall\n";
    std::cout << "       Enter 10 for Junior J-Terml\n";
    std::cout << "       Enter 11 for Junior Spring\n";
    std::cout << "       Enter 12 for Junior Summer\n";
    std::cout << "       Enter 13 for Senior Fall\n";
    std::cout << "       Enter 14 for Senior Spring\n";
    std::cout << "       Enter 15 to list ALL your courses starting from Freshman Fall\n";
    std::cout << "       -1 to go back, 0 to exit\n";

}
int Ui::ListAllCoursesScreen::getInput()
{
    int m_input;
    std::cin >> m_input;
    std::cin.ignore();

    return m_input;
}