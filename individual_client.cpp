#include "individual_client.h"

std::map<Permission, std::string> permission_map = {{Permission::NO, "NO"}, {Permission::YES, "YES"}};

void IndividualClient::set_permission(Permission permission)
{
    this->marketing_permission = permission;
}

Permission IndividualClient::get_permission() const
{
    return this->marketing_permission;
}

std::string IndividualClient::get_permission_string() const
{
    return permission_map[this->marketing_permission];
}

std::ostream& operator<<(std::ostream& os, IndividualClient client) 
{
    os << "Client " << client.get_id() << ": " << client.get_name() << std::endl
        << "Marketing permission: " << client.get_permission_string() << std::endl
        << "Balance: " << client.get_balance() << std::endl;
    return os;
}