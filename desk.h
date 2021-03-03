#ifndef DESK_H
#define DESK_H
#include <iostream>
#include "desk_interface.h"

class Desk : public DeskInterface
{
    public:
        static unsigned numerator;
        unsigned id;
    public:
        unsigned get_id() const override;
        unsigned return_new_id() const override;
        void set_id() override;
 
    friend std::ostream& operator<<(std::ostream& os, Desk desk);

};

std::ostream& operator<<(std::ostream& os, Desk desk);

#endif