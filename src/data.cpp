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
        auto i_client_ptr = std::make_unique<IndividualClient>();
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
        list_of_clients.add_client(std::move(i_client_ptr));
    }
    text_file.close();

    text_file.open(b_clients_file);
    if(text_file.fail())
        throw FailedToOpenException();
    while (std::getline(text_file, line))
    {
        auto b_client_ptr = std::make_unique<BusinessClient>();
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
        list_of_clients.add_client(std::move(b_client_ptr));
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
        auto employee_ptr = std::make_unique<Employee>();
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
        list_of_employees.add_employee(std::move(employee_ptr));
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
        auto desk_ptr = std::make_unique<Desk>();
        list_of_desks.add_desk(std::move(desk_ptr));
    }
    list_of_desks.add_desk(std::move(std::make_unique<Atm>()));
    list_of_desks.add_desk(std::move(std::make_unique<Cdm>()));
}