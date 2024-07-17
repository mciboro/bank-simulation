#ifndef CLIENT_LIST_H
#define CLIENT_LIST_H

#include <vector>
#include <fstream>
#include "client.h"
#include "individual_client.h"
#include "business_client.h"

class ClientList
{
    private:
        std::vector<std::unique_ptr<Client>> client_list;
    public:
        void add_client(std::unique_ptr<Client>&& client);
        Client& return_client(unsigned index);
        void print_all_clients(char* file_name) const;
        unsigned return_size() const;

};

#endif
