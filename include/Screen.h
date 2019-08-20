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
        virtual int display() = 0;
        virtual int getUserInput() = 0;
        virtual int exitOrMoveBack() = 0;
        virtual int checkSuccess() = 0;
};

#endif