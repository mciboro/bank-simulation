#include "data.h"

void Data::read_clients_from_file(char* i_clients_file, char* b_clients_file)
{
    std::string line, word, name;
    double balance;
    std::ifstream text_file;
    text_file.open(i_clients_file);
    if(text_file.fail())
        throw FailedToOpenException();
    while (std::getline(text_file, line))
    {
        IndividualClient* i_client_ptr = new IndividualClient;
        std::istringstream stream_line(line);
        stream_line >> word;
        name = word;
        stream_line >> word;
        name += " ";
        name += word;
        i_client_ptr->set_name(name);
        stream_line >> word;
        balance = std::stod(word);
        i_client_ptr->set_balance(balance);
        stream_line >> word;
        if(word == "NO")
            i_client_ptr->set_permission(Permission::NO);
        else
            i_client_ptr->set_permission(Permission::YES);
        list_of_clients.add_client(i_client_ptr);
    }
    text_file.close();

    text_file.open(b_clients_file);
    if(text_file.fail())
        throw FailedToOpenException();
    while (std::getline(text_file, line))
    {
        BusinessClient* b_client_ptr = new BusinessClient;
        std::istringstream stream_line(line);
        stream_line >> word;
        name = word;
        stream_line >> word;
        name += " ";
        name += word;
        b_client_ptr->set_name(name);
        stream_line >> word;
        balance = std::stod(word);
        b_client_ptr->set_balance(balance);
        stream_line >> word;
        b_client_ptr->set_company_name(word);
        list_of_clients.add_client(b_client_ptr);
    }
    text_file.close();
}

void Data::read_employees_from_file(char* file_name)
{
    std::string name, line, word;
    std::ifstream text_file;
    text_file.open(file_name);
    if(text_file.fail())
        throw FailedToOpenException();
    while (std::getline(text_file, line))
    {
        Employee* employee_ptr = new Employee;
        std::istringstream stream_line(line);
        stream_line >> word;
        name = word;
        stream_line >> word;
        name += " ";
        name += word;
        employee_ptr->set_name(name);
        stream_line >> word;
        if(word == "Senior")
        {
            employee_ptr->set_seniority(Seniority::SENIOR);
        }
        else
        {
            employee_ptr->set_seniority(Seniority::JUNIOR);
        }
        list_of_employees.add_employee(employee_ptr);
    }
    text_file.close();
}

void Data::read_desks_from_file(char* file_name)
{
    int number_of_desks = 20;
    std::ifstream text_file;
    text_file.open(file_name);
    if(text_file.fail())
        throw FailedToOpenException();
    text_file >> number_of_desks;
    text_file.close();
    for(int i = 0; i < number_of_desks; i++)
    {
        Desk* desk_ptr = new Desk;
        list_of_desks.add_desk(desk_ptr);
    }
    list_of_desks.add_desk(&atm);
    list_of_desks.add_desk(&cdm);
}