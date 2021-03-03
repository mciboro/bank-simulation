#ifndef DATA_INTERFACE_H
#define DATA_INTERFACE_H

class DataInterface
{
    public:
        virtual void read_clients_from_file(char* file_name1, char* file_name2) = 0;
        virtual void read_employees_from_file(char* file_name) = 0;
        virtual void read_desks_from_file(char* file_name) = 0;
        virtual ~DataInterface() = 0;
};

#endif