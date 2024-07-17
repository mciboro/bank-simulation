#ifndef SERVICE_H
#define SERVICE_H
#include "service_interface.h"

class Service : public ServiceInterface
{
    protected:
        static unsigned numerator;
        unsigned id;
        Client& client;
        Employee& banker;
        Desk& desk;
        double amount;
    public:
        Service() = delete;
        Service(Client& client, Employee& banker, Desk& desk, double amount, unsigned id);
        unsigned get_id() const override;
        Client& get_client() const override;
        double get_amount() const override;
        Employee& get_banker() const override;
        Desk& get_desk() const override;
};

#endif
