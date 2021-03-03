#ifndef FAILED_TO_OPEN_EXCEPTION_H
#define FAILED_TO_OPEN_EXCEPTION_H
#include <iostream>

class FailedToOpenException : public std::invalid_argument
{
    public:
        FailedToOpenException();
};

#endif