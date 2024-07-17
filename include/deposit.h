#ifndef DEPOSIT_H
#define DEPOSIT_H
#include <iostream>
#include <fstream>
#include "service.h"
#include "wrong_machine_exception.h"
#include "failed_to_open_exception.h"
#include "unable_to_save_exception.h"

class Deposit : public Service
{
    public:
        Deposit(Client& client, Employee& banker, Desk& desk, double amount, unsigned id);
        Deposit() = delete;
        static unsigned return_new_id();
        void do_cash_deposit(char* file_name);

    friend std::ostream& operator<<(std::ostream& os, Deposit deposit);
};

std::ostream& operator<<(std::ostream& os, Deposit deposit);

#endif