#ifndef SERVICE_H
#define SERVICE_H
#include "service_interface.h"

class Service : public ServiceInterface
{
    protected:
        static unsigned numerator;
        unsigned id;
        unsigned time;
        Client* client;
        Employee* banker;
        Desk* desk;
        double amount;
    public:
        unsigned get_id() const override;
        unsigned return_new_id() const override;
        void set_id() override;
        unsigned get_time() const override;
        void set_time(unsigned time) override;
        Client* get_client() const override;
        void set_client(Client* client) override;
        double get_amount() const override;
        void set_amount(double amount) override;
        Employee* get_banker() const override;
        void set_banker(Employee* banker) override;
        Desk* get_desk() const override;
        void set_desk(Desk* desk) override;
};

#endif
