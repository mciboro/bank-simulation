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
        std::vector<Client*> client_list;
    public:
        void add_client(Client* client);
        Client* return_client(unsigned index) const;
        void print_all_clients(char* file_name) const;
        unsigned return_size() const;
        ~ClientList();

};

#endif
