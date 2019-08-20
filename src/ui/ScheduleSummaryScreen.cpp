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

//---------------------------------------------------------------------------------//

Ui::ScheduleSummaryScreen::ScheduleSummaryScreen()
{
    //default constructor
}

//---------------------------------------------------------------------------------//

Ui::ScheduleSummaryScreen::~ScheduleSummaryScreen()
{
    //destructor
}

//-----------------------------------DISPLAY----------------------------------------//

int Ui::ScheduleSummaryScreen::display()
{   
    m_ptr_accessDBptr.reset(new Progrado::UserInterface());
    m_ptr_toDBconnector = m_ptr_accessDBptr->m_ptr_DBConnector;

    this->getUserInput();

    //go on to show schedule
    while (m_choice != 1)
    {
        if (m_choice == -1)
        {
            return Progrado::DONE;
                                                
        }
        else if (m_choice == 0)
        {
            std::cout << "You have exited ProGrado\n"; 
            return Progrado::EXIT; 
        }
    }
    if (m_choice == 1)
    {
            std::vector < std::vector< std::shared_ptr<Progrado::Course> > > m_twoDvector;

            m_twoDvector = m_ptr_toDBconnector->getScheduleSummary();

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
    
    //Check operation report
    this->checkSuccess();

    //Exit/Back
    m_checkExitOrMoveBack = this->exitOrMoveBack();

    //move to MainMenu
    if (m_checkExitOrMoveBack == Progrado::DONE) 
    {
        return Progrado::DONE;
    }
    else if (m_checkExitOrMoveBack == Progrado::EXIT)
    {
        return Progrado::EXIT;
    }
}

//----------------------------------USERINPUT-------------------------------------------//

int Ui::ScheduleSummaryScreen::getUserInput()
{
    std::cout << "Kindly press 1 to view your schedule summary\n";
    std::cout << "            -1 to go back to main menu\n";
    std::cout << "             0 exit\n";
    std::cin >> m_choice;

    return Progrado::SUCCESS;

}

//---------------------------------------------------------------------------------//

int Ui::ScheduleSummaryScreen::exitOrMoveBack() 
{
    std::cout << "Enter -1 to go back to Main Menu, 0 to exit ProGrado\n";
    std::cin >> m_choice2;
    
    while (m_choice2 != -1 || m_choice2 != 0)
    {
        std::cout << "Invalid choice\n";
        std::cout << "Enter -1 to go back to Main Menu, 0 to exit ProGrado\n";
        std::cin >> m_choice2; 
    }
    if (m_choice2 == -1)
    {
        return Progrado::DONE;
    }
    else if(m_choice2 == 0)
    {
        std::cout << "You have exited Progrado\n";
        return Progrado::EXIT;
    }
}

//---------------------------------------------------------------------------------//

int Ui::ScheduleSummaryScreen::checkSuccess()
{
    return Progrado::SUCCESS;
    
}

//---------------------------------------END---------------------------------------//