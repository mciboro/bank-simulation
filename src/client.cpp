#include "client.h"

unsigned Client::numerator = 1;

unsigned Client::get_id() const
{
    return this->id;
}

std::string Client::get_name() const
{
    return this->name;
}

double Client::get_balance() const
{
    return this->balance;
}

unsigned Client::return_new_id() const
{
    return numerator++;
}

void Client::set_id()
{
    this->id = this->return_new_id();
}

void Client::set_name(std::string name)
{
    this->name = name;
}

void Client::set_balance(double balance)
{
    this->balance = balance;
}

std::ostream& operator<<(std::ostream& os, Client client) 
{
    os << "Client " << client.get_id() << ": " << client.get_name() << std::endl
        << "Balance: " << client.get_balance() << std::endl;
    return os;
}