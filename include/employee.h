#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <map>
#include "employee_interface.h"

class Employee : public EmployeeInterface
{
    private:
        static unsigned numerator;
        unsigned id;
        std::string name;
        Seniority seniority;
    public:
        std::string get_name() const;
        unsigned get_id() const;
        Seniority get_seniority() const;
        std::string get_seniority_string() const;
        void set_name(std::string name);
        unsigned return_id() const;
        void set_id();
        void set_seniority(Seniority seniority);

    friend std::ostream& operator<<(std::ostream& os, Employee employee);

};

std::ostream& operator<<(std::ostream& os, Employee employee);

#endif