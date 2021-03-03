#ifndef UNABLE_TO_SAVE_EXCEPTION_H
#define UNABLE_TO_SAVE_EXCEPTION_H
#include <iostream>

class UnableToSaveException : public std::ios_base::failure
{
    public:
        UnableToSaveException();
};

#endif