#ifndef DESK_LIST_H
#define DESK_LIST_H
#include <iostream>
#include <fstream>
#include <vector>
#include "desk.h"

class DeskList
{
    protected:
        std::vector<Desk*> desk_list;
    public:
        void add_desk(Desk* desk);
        Desk* return_desk(unsigned index) const;
        void print_all_desks(char* file_name) const;
        unsigned return_size() const;
        ~DeskList();
};

#endif
