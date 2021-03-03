#include "transfer.h"

void Transfer::do_transfer(char* file_name)
{   
    std::ofstream output_file;
    output_file.open(file_name, std::ios::app);
    if(output_file.fail())
        throw FailedToOpenException();
    this->set_id();
    double recipient_balance = recipient->get_balance();
    double sender_balance = client->get_balance();
    sender_balance -= amount;
    if(client->get_id() == recipient->get_id())
        throw SameClientException();
    if(sender_balance < 0)
        throw DebtException();
    if(desk->get_id() == 100 || desk->get_id() == 200)
        throw WrongMachineException();
    recipient_balance += amount;
    recipient->set_balance(recipient_balance);
    client->set_balance(sender_balance);
    std::cout << *this;
    output_file << *this;
    if(output_file.bad())
        throw UnableToSaveException();
    output_file.close();
}

Client* Transfer::get_recipient() const
{
    return this->recipient;
}

void Transfer::set_recipient(Client* recipient)
{
    this->recipient = recipient;
}

std::ostream& operator<<(std::ostream& os, Transfer transfer)
{
    os << "Transfer no. " << transfer.get_id() << " was made" << std::endl
        << "Sender no. " << transfer.client->get_id() << ": " << transfer.client->get_name() << std::endl 
        << "Recipient no. " << transfer.recipient->get_id() << ": " << transfer.recipient->get_name() << std::endl
        << "Banker no. " << transfer.banker->get_id() << ": " << transfer.banker->get_name() << std::endl
        << "Amount: " << transfer.get_amount() << std::endl
        << "Desk no. " << transfer.desk->get_id() << std::endl << std::endl; 

    return os;
    
}