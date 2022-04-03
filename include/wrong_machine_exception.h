#ifndef WRONG_MACHINE_EXCEPTION_H
#define WRONG_MACHINE_EXCEPTION_H
#include <iostream>

class WrongMachineException : public std::invalid_argument
{
    public:
        WrongMachineException();
};

#endif