#include "client_list.h"

void ClientList::add_client(std::unique_ptr<Client>&& client)
{
    client->set_id();
    this->client_list.push_back(std::move(client));
}

Client& ClientList::return_client(unsigned index)
{
    return *this->client_list.at(index);

}

void ClientList::print_all_clients(char* file_name) const
{
    std::ofstream output_file;
    output_file.open(file_name, std::ios::app);
    for(auto const& client : client_list)
    {
        std::cout << *client;
        output_file << *client;
    }
    std::cout << std::endl;
    output_file << std::endl;
    output_file.close();
}

unsigned ClientList::return_size() const
{
    return this->client_list.size();
}