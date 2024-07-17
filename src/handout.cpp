#include "handout.h"

Handout::Handout(Client& client, Employee& banker, Desk& desk, double amount, unsigned id) : Service(client, banker, desk, amount, id) {};

void Handout::do_cash_handout(char* file_name)
{   
    std::ofstream output_file;
    output_file.open(file_name, std::ios::app);
    if(output_file.fail())
        throw FailedToOpenException();
    if(this->desk.get_id() == 200)
        throw WrongMachineException();
    double new_balance = client.get_balance();
    new_balance -= amount;
    if(new_balance < 0)
        throw DebtException();
    client.set_balance(new_balance);
    std::cout << *this;
    output_file << *this;
    if(output_file.bad())
        throw UnableToSaveException();
    output_file.close();
}

unsigned Handout::return_new_id()
{
    return 200 + numerator++;
}

std::ostream& operator<<(std::ostream& os, Handout handout)
{
    os << "Handout no. " << handout.get_id() << " was made" << std::endl
        << "Client no. " << handout.client.get_id() << ": " << handout.client.get_name() << std::endl 
        << "Amount: " << handout.get_amount() << std::endl
        << "Client's balance: " << handout.client.get_balance() << std::endl;

    if(handout.desk.get_id() == 100)
    {
        os << "Handout was made at ATM" << std::endl << std::endl;
        return os;
    }
    os << "Banker no. " << handout.banker.get_id() << ": " << handout.banker.get_name() << std::endl
        << "Desk no. " << handout.desk.get_id() << std::endl << std::endl;
    return os;
}
