#ifndef SAME_CLIENT_EXCEPTION_H
#define SAME_CLIENT_EXCEPTION_H
#include <iostream>

class SameClientException : public std::invalid_argument
{
    public:
        SameClientException();
};

#endif