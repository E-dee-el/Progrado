/*
**************************************
*************PROGRADO*****************
**************************************
Screen header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */
#ifndef SCREEN_
#define SCREEN_

namespace Ui{
    class Screen;
}

class Ui::Screen{

    public:
        Screen();
        virtual ~Screen();
        virtual void display() = 0;

    
};

#endif