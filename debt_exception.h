#ifndef DEBT_EXCEPTION_H
#define DEBT_EXCEPTION_H
#include <iostream>

class DebtException : public std::out_of_range
{
    public:
        DebtException();
};

#endif