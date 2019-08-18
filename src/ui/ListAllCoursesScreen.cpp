/*
**************************************
*************PROGRADO*****************
**************************************
ListAllCoursesScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"UserInterface.h"

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
    std::cout << "Please enter what semester's courses you would like to list\n";
    std::cout << "      Enter 1 for Freshman Fall\n";
    std::cout << "      Enter 2 for Freshman J-Term\n";
    std::cout << "      Enter 3 for Freshman Spring\n";
    std::cout << "      Enter 4 for Freshman Summer\n";
    std::cout << "      Enter 5 for Sophomore Fall\n";
    std::cout << "      Enter 6 for Sophomore J-Term\n";
    std::cout << "      Enter 7 for Sophomore Spring\n";
    std::cout << "      Enter 8 for Sophomore Summer\n";
    std::cout << "      Enter 9 for Junior Fall\n";
    std::cout << "      Enter 10 for Junior J-Terml\n";
    std::cout << "      Enter 11 for Junior Spring\n";
    std::cout << "      Enter 12 for Junior Summer\n";
    std::cout << "      Enter 13 for Senior Fall\n";
    std::cout << "      Enter 14 for Senior Spring\n";
    std::cout << "      Enter 15 to list ALL your courses starting from Freshman Fall\n";
    std::cout << "      0 to exit\n";


    int m_choice;

    std::cin >> m_choice;

    switch (m_choice)
    {
    case 1:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::FRESHMAN_FALL);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;

            std::cout << " Below is a list of your courses for Freshman Fall Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 2:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::FRESHMAN_JTERM);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Freshman J-Term : \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }
    
    case 3:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::FRESHMAN_SPRING);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Freshman Spring Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }
    
    case 4:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::FRESHMAN_SUMMER);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;

            
            std::cout << " Below is a list of your courses for Freshman Summer Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      "  << *m_goThroughPointers << std::endl;
            }

            break;
        }
        
    case 5:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::SOPH_FALL);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;

            std::cout << " Below is a list of your courses for Sophomore Fall Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 6:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::SOPH_JTERM);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;

            std::cout << " Below is a list of your courses for Sophomore J-term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 7:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::SOPH_SPRING);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Sophomore Spring Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 8:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::SOPH_SUMMER);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Sophomore Summer Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 9:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::JUNIOR_FALL);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Junior Fall Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 10:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::JUNIOR_JTERM);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Junior J-Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 11:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::JUNIOR_SPRING);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Junior Spring Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 12:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::JUNIOR_SUMMER);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Junior Summer Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 13:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::SENIOR_FALL);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;

            std::cout << " Below is a list of your courses for Senior Fall Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 14:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::SENIOR_SPRING);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of your courses for Senior Spring Term: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 15:
        {
            std::vector< std::shared_ptr<Progrado::Course> > m_listCourses;

            std::unique_ptr<DB::DBConnector> m_ptr_accessListAllCourse;

            m_listCourses = m_ptr_accessListAllCourse->getCoursesMatching(Progrado::Term::ALL);

            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_goThroughPointers;


            std::cout << " Below is a list of ALL your courses: \n";
            std:: cout << "\n";

            for (m_goThroughPointers = m_listCourses.begin(); m_goThroughPointers != m_listCourses.end(); ++m_goThroughPointers)
            {
                std::cout << "      " << *m_goThroughPointers << std::endl;
            }

            break;
        }

    case 00:
        {
            std::cout << "You have exited Progrado\n";
            exit(0);
        }
    
    case -1:
    {
        std::unique_ptr<Progrado::UserInterface> m_ptr_access_toAccessInstantiate (new Progrado::UserInterface());
        m_ptr_access_toAccessInstantiate->instantiateScreen(m_ptr_access_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu);   
    }
    default:
        {
            std::cout << "Invalid selection\n";
            std::cout << "Returning to Main Menu\n";
            break;
        }
        
    }

    int m_choice2;
    
    std::cout << "Enter 1 to go back to Main Menu, 0 to exit ProGrado\n";

    std::cin >> m_choice2;
    
    while (m_choice2 != 1 || m_choice2 != 0)
    {
        std::cout << "Invalid choice\n";
        std::cout << "Enter 1 to go back to Main Menu, 0 to exit ProGrado\n";

        std::cin >> m_choice2; 
    }

    if (m_choice2 == 1)
    {
        std::unique_ptr<Progrado::UserInterface> m_ptr_access_toAccessInstantiate (new Progrado::UserInterface());
        m_ptr_access_toAccessInstantiate->instantiateScreen(m_ptr_access_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu); 
    }

    else if(m_choice2 == 0)
    {
        std::cout << "YOu have exited Progrado\n";
    }

} 

