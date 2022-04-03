#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "client_interface.h"

class Client : public ClientInterface
{
    protected:
        static unsigned numerator;
        unsigned id;
        std::string name;
        double balance;
    public:
        unsigned get_id() const override;
        std::string get_name() const override;
        double get_balance() const override;
        unsigned return_new_id() const override;
        void set_id() override;
        void set_name(std::string name) override;
        void set_balance(double balance) override;

    friend std::ostream& operator<<(std::ostream& os, Client client);
};

std::ostream& operator<<(std::ostream& os, Client client);

#endif