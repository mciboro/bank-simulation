#ifndef HANDOUT_H
#define HANDOUT_H
#include <iostream>
#include <fstream>
#include "service.h"
#include "debt_exception.h"
#include "wrong_machine_exception.h"
#include "failed_to_open_exception.h"
#include "unable_to_save_exception.h"

class Handout : public Service
{
    public:
        void do_cash_handout(char* file_name);
        void set_id() override;

    friend std::ostream& operator<<(std::ostream& os, Handout handout);
};

std::ostream& operator<<(std::ostream& os, Handout handout);

#endif