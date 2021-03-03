#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H
#include <iostream>

class ClientInterface
{
    public:
        virtual unsigned get_id() const = 0;
        virtual std::string get_name() const = 0;
        virtual double get_balance() const = 0;
        virtual unsigned return_new_id() const = 0;
        virtual void set_id() = 0;
        virtual void set_name(std::string name) = 0;
        virtual void set_balance(double balance) = 0;
        virtual ~ClientInterface() = 0;
};

#endif