/*
**************************************
*************PROGRADO*****************
**************************************
CreateAccountScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"CreateAccountScreen.h"
#include"Course.h"
#include<iostream>
#include"Progrado.h"
#include"User.h"

Ui::CreateAccountScreen::CreateAccountScreen()
{
    //default constructor
}

Ui::CreateAccountScreen::~CreateAccountScreen()
{
    //destructor
}

void Ui::CreateAccountScreen::display()
{
    std::cout << "Welcome to Progrado!\n Create an account by providing the following Information\n";
}

Progrado::User Ui::CreateAccountScreen::getInput()
{
    std::string last_name, first_name, major, minor, college_yr, username, password;

    std::cout << "Enter Last Name: "; std::getline(std::cin, last_name);
    std::cout << "Enter First Name: "; std::getline(std::cin, first_name);
    std::cout << "Enter  Major: "; std::getline(std::cin, major);
    std::cout << "Enter Minor: "; std::getline(std::cin, minor);
    std::cout << "Enter Year in College: "; std::getline(std::cin, college_yr);
    std::cout << "Choose a username: "; std::getline(std::cin, username);
    std::cout << "Choose a Password: "; std::getline(std::cin, password);

    return Progrado::User(last_name, first_name,college_yr, username, major, minor, password);
    
}