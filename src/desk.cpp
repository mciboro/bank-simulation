#include "desk.h"

unsigned Desk::numerator = 1;

unsigned Desk::get_id() const
{
    return this->id;
}

unsigned Desk::return_new_id() const
{
    return numerator++;
}

void Desk::set_id()
{
    this->id = this->return_new_id();
}

std::ostream& operator<<(std::ostream& os, Desk desk)
{
    os << "Desk no. " << desk.get_id() << std::endl;

    return os;
}