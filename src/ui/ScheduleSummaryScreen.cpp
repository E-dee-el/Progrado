/*
**************************************
*************PROGRADO*****************
**************************************
ScheduleSummaryScreen Implementation
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */
#include"UserInterface.h" 

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

    int m_choice;

    std::cin >> m_choice;

    while (m_choice != 1)
    {
        if (m_choice == -1)
        {
                std::unique_ptr<Progrado::UserInterface> m_ptr_access_toAccessInstantiate (new Progrado::UserInterface());
                m_ptr_access_toAccessInstantiate->instantiateScreen(m_ptr_access_toAccessInstantiate->m_ptr_mainMenu, Progrado::Screen::main_menu);
        }
        else if (m_choice == 00)
        {
            std::cout << "You have exited ProGrado\n";
            exit(4);
        }
    }


    if (m_choice == 1)
    {
            std::vector < std::vector< std::shared_ptr<Progrado::Course> > > m_twoDvector;

            std::unique_ptr<DB::DBConnector> m_ptr_toDBConnector;

            m_twoDvector = m_ptr_toDBConnector->getScheduleSummary();

            std::vector< std::vector< std::shared_ptr<Progrado::Course> > >::const_iterator m_iterRow;
            std::vector< std::shared_ptr<Progrado::Course> >::const_iterator m_iterCol;

            for (m_iterRow = m_twoDvector.begin(); m_iterRow != m_twoDvector.end(); ++m_iterRow)
            {
                for(m_iterCol = m_iterRow->begin(); m_iterCol != m_iterRow->end(); ++m_iterCol)
                {
                    std::cout << "  " << *m_iterCol << std::endl;
                }
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
        std::cout << "You have exited ProGrado\n";
    }


}