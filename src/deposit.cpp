#include "deposit.h"

Deposit::Deposit(Client& client, Employee& banker, Desk& desk, double amount, unsigned id) : Service(client, banker, desk, amount, id) {};

void Deposit::do_cash_deposit(char* file_name)
{
    std::ofstream output_file;
    output_file.open(file_name, std::ios::app);
    if(output_file.fail())
        throw FailedToOpenException();
    if(this->desk.get_id() == 100)
        throw WrongMachineException();
    double new_balance = client.get_balance();
    new_balance += amount;
    client.set_balance(new_balance);
    std::cout << *this;
    output_file << *this;
    if(output_file.bad())
        throw UnableToSaveException();
    output_file.close();
}

unsigned Deposit::return_new_id()
{
    return 100 + numerator++;
}

std::ostream& operator<<(std::ostream& os, Deposit deposit)
{
    os << "Deposit no. " << deposit.get_id() << " was made" << std::endl
        << "Client no. " << deposit.client.get_id() << ": " << deposit.client.get_name() << std::endl 
        << "Amount: " << deposit.get_amount() << std::endl 
        << "Client's balance: " << deposit.client.get_balance() << std::endl;
    
    if(deposit.desk.get_id() == 200)
    {
        os << "Deposit made at CDM" << std::endl << std::endl;
        return os; 
    }
    os << "Banker no. " << deposit.banker.get_id() << ": " << deposit.banker.get_name() << std::endl;
    os << "Desk no. " << deposit.desk.get_id() << std::endl << std::endl;
    return os;
}
