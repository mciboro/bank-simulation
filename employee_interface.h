#ifndef EMPLOYEE_INTERFACE_H
#define EMPLOYEE_INTERFACE_H
#include <string>

enum class Seniority {SENIOR, JUNIOR};

class EmployeeInterface
{
    public:
        virtual std::string get_name() const = 0;
        virtual unsigned get_id() const = 0;
        virtual Seniority get_seniority() const = 0;
        virtual void set_name(std::string name) = 0;
        virtual unsigned return_id() const = 0;
        virtual void set_id() = 0;
        virtual void set_seniority(Seniority seniority) = 0;
        virtual ~EmployeeInterface() = 0;

};

#endif