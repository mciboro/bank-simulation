#ifndef ATM_H
#define ATM_H
#include "desk.h"

class Atm : public Desk
{
    public:
        void set_id() override;
};

#endif