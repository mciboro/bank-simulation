#ifndef SERVICE_INTERFACE_H
#define SERVICE_INTERFACE_H
#include "client.h"
#include "employee.h"
#include "desk.h"

class ServiceInterface
{
    public:
        virtual unsigned get_id() const = 0;
        virtual Client& get_client() const = 0;
        virtual double get_amount() const = 0;
        virtual Employee& get_banker() const = 0;
        virtual Desk& get_desk() const = 0;
        virtual ~ServiceInterface() = 0;
};

#endif