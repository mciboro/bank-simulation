#include "service.h"

unsigned Service::numerator = 1;

Service::Service(Client& client, Employee& banker, Desk& desk, double amount, unsigned id) : 
    client(client),
    banker(banker),
    desk(desk),
    amount(amount),
    id(id) {};

unsigned Service::get_id() const
{
    return this->id;
}

Client& Service::get_client() const
{
    return this->client;
}

double Service::get_amount() const
{
    return this->amount;
}

Employee& Service::get_banker() const
{
    return this->banker;
}

Desk& Service::get_desk() const
{
    return this->desk;
}
