#include <iostream>
#include "simulation.h"

int main(int argc, char** argv)
{
    if(argc < 7)
    {
        std::cout << "USAGE: bank-simulation [FIRST CLIENTS FILE] [SECOND CLIENTS FILE] ";
        std::cout << "[EMPLOYEERS FILE] [DESKS FILE] [PARAMETERS FILE] [OUTPUT FILENAME]";
        std::cout << std::endl;
        return -argc;
    }
    Simulation program(argc, argv);
    program.do_simulation();
    return 0;
}