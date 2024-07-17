#ifndef TRANSFER_H
#define TRANSFER_H

#include <iostream>
#include <fstream>
#include "client.h"
#include "service.h"
#include "debt_exception.h"
#include "same_client_exception.h"
#include "wrong_machine_exception.h"
#include "failed_to_open_exception.h"
#include "unable_to_save_exception.h"

class Transfer : public Service
{
    private:
        Client& recipient;
    public:
        Transfer(Client& client, Client& recipient, Employee& banker, Desk& desk, double amount, unsigned id);
        Transfer() = delete;
        static unsigned return_new_id();
        void do_transfer(char* file_name);
        Client& get_recipient() const;
        void set_recipient(Client& recipient);
    
    friend std::ostream& operator<<(std::ostream& os, Transfer transfer);
};

std::ostream& operator<<(std::ostream& os, Transfer transfer);

#endif