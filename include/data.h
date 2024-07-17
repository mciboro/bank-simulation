#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "data_interface.h"
#include "client_list.h"
#include "employee_list.h"
#include "desk_list.h"
#include "atm.h"
#include "cdm.h"
#include "failed_to_open_exception.h"

class Data : public DataInterface
{
    private:
        ClientList list_of_clients;
        EmployeeList list_of_employees;
        DeskList list_of_desks;
    public:
        void read_clients_from_file(char* i_client_file, char* b_client_file) override;
        void read_employees_from_file(char* file_name) override;
        void read_desks_from_file(char* file_name) override;

    friend class Simulation;
};

#endif