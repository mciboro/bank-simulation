#ifndef DESK_LIST_H
#define DESK_LIST_H
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "desk.h"

class DeskList
{
    protected:
        std::vector<std::unique_ptr<Desk>> desk_list;
    public:
        void add_desk(std::unique_ptr<Desk>&& desk);
        Desk& return_desk(unsigned index);
        void print_all_desks(char* file_name) const;
        unsigned return_size() const;
};

#endif
