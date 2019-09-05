
#include"create_account.h"
#include"DBConnector.h"
#include"User.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdexcept>

using namespace Progrado::UI;
using namespace DB;

create_account::~create_account() {}

void create_account::print_instructions()const
{
    std::cout <<
              "\t\tCREATE ACCOUNT\n"
              "====================="
              "Enter the following details to create a new Progrado account\n";

}

void create_account::execute()const
{
    std::string last_name, first_name, major, minor, college_yr, username, password;

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);

    std::cout << "Enter First Name: ";
    std::getline(std::cin, first_name);

    std::cout << "Enter Major: ";
    std::getline(std::cin, major);

    std::cout << "Enter Minor: ";
    std::getline(std::cin, minor);

    std::cout << "Enter year in College: ";
    std::getline(std::cin, college_yr);

    std::cout << "Choose a username: ";
    std::getline(std::cin, username);

    std::cout << "Choose a Password: ";
    std::getline(std::cin, password);

    try {
        /*unique ptr to new user object*/
        std::unique_ptr<User> new_user(new User(
                                           last_name,
                                           first_name,
                                           college_yr,
                                           username,
                                           major,
                                           minor,
                                           password
                                       ));
        DBConnector::addNewUser(*new_user);

    }
    catch(std::runtime_error)
    {
        std::cerr << "An account could not be created at this time\n";
        /*rethrow this exception until it reaches main*/
        throw std::runtime_error("Failed to add new User");
    }

}