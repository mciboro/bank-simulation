#ifndef SERVICE_INTERFACE_H
#define SERVICE_INTERFACE_H
#include "client.h"
#include "employee.h"
#include "desk.h"

class ServiceInterface
{
    public:
        virtual unsigned get_id() const = 0;
        virtual unsigned return_new_id() const = 0;
        virtual void set_id() = 0;
        virtual unsigned get_time() const = 0;
        virtual void set_time(unsigned time) = 0;
        virtual Client* get_client() const = 0;
        virtual void set_client(Client* client) = 0;
        virtual double get_amount() const = 0;
        virtual void set_amount(double amount) = 0;
        virtual Employee* get_banker() const = 0;
        virtual void set_banker(Employee* banker) = 0;
        virtual Desk* get_desk() const = 0;
        virtual void set_desk(Desk* desk) = 0;
        virtual ~ServiceInterface() = 0;
};

#endif