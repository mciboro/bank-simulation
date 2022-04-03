#ifndef BUSINESS_CLIENT_H
#define BUSINESS_CLIENT_H
#include "client.h"

class BusinessClient : public Client
{
    private:
        std::string company_name;
    public:
        void set_company_name(std::string company_name);
        std::string get_company_name() const;
        void set_id() override;

    friend std::ostream& operator<<(std::ostream& os, BusinessClient client);
};

 std::ostream& operator<<(std::ostream& os, BusinessClient client);

#endif