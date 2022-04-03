#include "business_client.h"

void BusinessClient::set_company_name(std::string company_name)
{
    this->company_name = company_name;
}

std::string BusinessClient::get_company_name() const
{
    return this->company_name;
}

std::ostream& operator<<(std::ostream& os, BusinessClient client) 
{
    os << "Client " << client.get_id() << ": " << client.get_name() << std::endl
        << "Company name: " << client.get_company_name() << std::endl
        << "Balance: " << client.get_balance() << std::endl;
    return os;
}

void BusinessClient::set_id()
{
    this->id = this->return_new_id() + 100;
}