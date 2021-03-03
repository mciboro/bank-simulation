#include <iostream>
#include "simulation.h"

int main(int argc, char** argv)
{
    if(argc < 7)
    {
        std::cout << "Too less input files \n";
        return -argc;
    }
    Simulation program(argc, argv);
    program.do_simulation();
    return 0;
}