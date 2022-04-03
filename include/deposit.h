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
        void do_cash_deposit(char* file_name);
        void set_id() override;

    friend std::ostream& operator<<(std::ostream& os, Deposit deposit);
};

std::ostream& operator<<(std::ostream& os, Deposit deposit);

#endif