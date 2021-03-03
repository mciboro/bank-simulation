#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H

#include <vector>
#include <fstream>
#include "employee.h"

class EmployeeList
{
    private:
        std::vector<Employee*> employee_list;
    public:
        void add_employee(Employee* employee);
        Employee* return_employee(unsigned index) const;
        void print_all_employees(char* file_name) const;
        unsigned return_size() const;
        ~EmployeeList();

};

#endif
