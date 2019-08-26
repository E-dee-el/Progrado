/*
**************************************
*************PROGRADO*****************
**************************************
LoginScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"LoginScreen.h" 
<<<<<<< HEAD
=======
#include<iostream>
>>>>>>> 739bf89f7601565aafb6da478f4b77737491cae9
#include<string>

Ui::LoginScreen::LoginScreen()
{
    //default constructor
}

Ui::LoginScreen::~LoginScreen()
{
    //destructor
}

void Ui::LoginScreen::display()
{
    std::cout << "*******LOGIN********\n";
}

std::string Ui::LoginScreen::getUserName()
{
    std::string username;
    std::cout << "Enter username to login: "; std::getline(std::cin, username);
    return username;
}

std::string Ui::LoginScreen::getPassword()
{
    std::string password;
    std::cout << "Enter password to login: "; std::getline(std::cin, password);
    return password;
}