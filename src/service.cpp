#include "service.h"

unsigned Service::numerator = 1;

unsigned Service::get_id() const
{
    return this->id;
}

unsigned Service::return_new_id() const
{
    return numerator++;
}

void Service::set_id()
{
    this->id = this->return_new_id();
}

unsigned Service::get_time() const
{
    return this->time;
}

void Service::set_time(unsigned time)
{
    this->time = time;
}

Client* Service::get_client() const
{
    return this->client;
}

void Service::set_client(Client* client)
{
    this->client = client;
}

double Service::get_amount() const
{
    return this->amount;
}

void Service::set_amount(double amount)
{
    this->amount = amount;
}

Employee* Service::get_banker() const
{
    return this->banker;
}

void Service::set_banker(Employee* banker)
{
    this->banker = banker;
}

Desk* Service::get_desk() const
{
    return this->desk;
}

void Service::set_desk(Desk* desk)
{
    this->desk = desk;
}
