#include "employee_list.h"

void EmployeeList::add_employee(std::unique_ptr<Employee>&& employee)
{
    employee->set_id();
    this->employee_list.push_back(std::move(employee));
}

Employee& EmployeeList::return_employee(unsigned index)
{
    return *this->employee_list.at(index);
}

void EmployeeList::print_all_employees(char* file_name) const
{
    std::ofstream output_file;
    output_file.open(file_name, std::ios::app);
    for(auto const& employee : employee_list)
    {
        std::cout << *employee;
        output_file << *employee;
    }
    std::cout << std::endl;
    output_file << std::endl;
    output_file.close();
}

unsigned EmployeeList::return_size() const
{
    return this->employee_list.size();
}
