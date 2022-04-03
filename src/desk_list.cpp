#include "desk_list.h"

void DeskList::add_desk(Desk* desk)
{
    desk->set_id();
    this->desk_list.push_back(desk);
}

Desk* DeskList::return_desk(unsigned index) const
{
    return this->desk_list[index];
}

void DeskList::print_all_desks(char* file_name) const
{
    std::ofstream output_file;
    output_file.open(file_name, std::ios::app);
    for(auto desk : desk_list)
    {
        std::cout << *desk;
        output_file << *desk;
    }
    std::cout << std::endl;
    output_file << std::endl;
    output_file.close();
}

unsigned DeskList::return_size() const
{
    return this->desk_list.size();
}

DeskList::~DeskList()
{
    for(std::vector<Desk*>::iterator i = desk_list.begin(); i != (desk_list.end() - 2); i++)
    {
        delete *i;
        *i = nullptr;
    }
}