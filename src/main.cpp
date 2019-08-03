/*
**************************************
*************PROGRADO*****************
**************************************
main function: program entry point
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */
#include"UserInterface.h"

using namespace Progrado;
using namespace Ui;

int main(int argc, char **argv)

{
    UserInterface* app;

    app->setup();
    app->run();

    delete app;
    return 0;
}
