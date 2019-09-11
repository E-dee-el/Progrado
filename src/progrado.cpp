#include"Progrado.h"
#include<iostream>


void Progrado::progrado_loading(int n)
{

        for(int i = 0; i < n; i++)
        {   std::cout << std::flush; /*flush the output buffer*/
            std::cout <<". "<<std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

        }
        std::cout << "\n";

}