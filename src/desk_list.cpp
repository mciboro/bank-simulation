#include "desk_list.h"

void DeskList::add_desk(std::unique_ptr<Desk>&& desk)
{
    desk->set_id();
    this->desk_list.push_back(std::move(desk));
}

Desk& DeskList::return_desk(unsigned index)
{
    return *this->desk_list.at(index);
}

void DeskList::print_all_desks(char* file_name) const
{
    // std::ofstream output_file;
    // output_file.open(file_name, std::ios::app);
    // for(auto const& desk : desk_list)
    // {
    //     std::cout << *desk;
    //     output_file << *desk;
    // }
    // std::cout << std::endl;
    // output_file << std::endl;
    // output_file.close();
}

unsigned DeskList::return_size() const
{
    return this->desk_list.size();
}