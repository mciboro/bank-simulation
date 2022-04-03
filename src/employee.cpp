#include "employee.h"

unsigned Employee::numerator = 1;
std::map<Seniority, std::string> seniority_map {{Seniority::JUNIOR, "Junior"}, {Seniority::SENIOR, "Senior"}};

std::string Employee::get_name() const
{
    return this->name;
}

unsigned Employee::get_id() const
{
    return this->id;
}

Seniority Employee::get_seniority() const
{
    return this->seniority;
}

std::string Employee::get_seniority_string() const
{
    return seniority_map[this->seniority];
}

void Employee::set_name(std::string name)
{
    this->name = name;
}

unsigned Employee::return_id() const
{
    return numerator++;
}

void Employee::set_id()
{
    this->id = this->return_id();
}

void Employee::set_seniority(Seniority seniority)
{
    this->seniority = seniority;
}

std::ostream& operator<<(std::ostream& os, Employee employee)
{
    os << "Employee " << employee.get_id() << ": " << employee.get_name() << std::endl 
        << "Seniority level: " << employee.get_seniority_string() << std::endl;
    return os;
}