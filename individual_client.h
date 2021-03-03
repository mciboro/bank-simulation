#ifndef INDIVIDUAL_CLIENT_H
#define INDIVIDUAL_CLIENT_H
#include <map>
#include "client.h"

enum class Permission {NO, YES};

class IndividualClient : public Client
{
    private:
        Permission marketing_permission;
    public:
        void set_permission(Permission permission);
        Permission get_permission() const;
        std::string get_permission_string() const;
    
    friend std::ostream& operator<<(std::ostream& os, IndividualClient client);
};

std::ostream& operator<<(std::ostream& os, IndividualClient client);

#endif