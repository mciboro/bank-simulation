#include "simulation.h"

Simulation::Simulation(int argc, char** argv) : argc(argc), argv(argv) {}

void Simulation::do_simulation()
{
    try
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        this->set_simulation_parameters(argv[5]);
        data.read_clients_from_file(argv[1], argv[2]);
        data.read_employees_from_file(argv[3]);
        data.read_desks_from_file(argv[4]);
        data.list_of_clients.print_all_clients(argv[6]);
        data.list_of_employees.print_all_employees(argv[6]);
        for(int i = 0; i < NUMBER_OF_OPERATIONS; i++)
        {
            this->do_operation(generator() % NUM_OF_AVAILABLE_OPERATIONS);
        }
        data.list_of_clients.print_all_clients(argv[6]);
    }
    catch(FailedToOpenException& e)
    {
        std::cerr << e.what();
        std::exit(-101);
    }
    catch(UnableToSaveException& e)
    {
        std::cerr << e.what();
        std::exit(-102);
    }
    catch(std::invalid_argument& iae)
    {
        std::cerr << iae.what() << std::endl;
        std::exit(-103);
    }
    catch(...)
    {
        std::cerr << "Other error\n";
        std::exit(-104);
    }
}

void Simulation::generate_transfer()
{
    try
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        Transfer transfer(data.list_of_clients.return_client(generator() % data.list_of_clients.return_size()),
                          data.list_of_clients.return_client((generator() + seed) % data.list_of_clients.return_size()),
                          data.list_of_employees.return_employee(generator() % data.list_of_employees.return_size()),
                          data.list_of_desks.return_desk(generator() % data.list_of_desks.return_size()),
                          generator() % TRANSFER_LIMIT,
                          Transfer::return_new_id());
        transfer.do_transfer(argv[6]);
    }
    catch(DebtException& e)
    {
        std::ofstream output_file;
        output_file.open(argv[6], std::ios::app);
        if(output_file.fail())
            throw FailedToOpenException();
        std::cerr << e.what();
        output_file << e.what();
        output_file.close();
    }
    catch(WrongMachineException& e)
    {
        std::ofstream output_file;
        output_file.open(argv[6], std::ios::app);
        if(output_file.fail())
            throw FailedToOpenException();
        std::cerr << e.what();
        output_file << e.what();
        output_file.close();
    }
    catch(SameClientException& e)
    {
        std::ofstream output_file;
        output_file.open(argv[6], std::ios::app);
        if(output_file.fail())
            throw FailedToOpenException();
        std::cerr << e.what();
        output_file << e.what();
        output_file.close();
    }
}

void Simulation::generate_deposit()
{
    try
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        Deposit deposit(data.list_of_clients.return_client(generator() % data.list_of_clients.return_size()),
                        data.list_of_employees.return_employee(generator() % data.list_of_employees.return_size()),
                        data.list_of_desks.return_desk(generator() % data.list_of_desks.return_size()),
                        static_cast<double>(generator() % TRANSFER_LIMIT),
                        Deposit::return_new_id());
        deposit.do_cash_deposit(argv[6]);
    }
    catch(WrongMachineException& e)
    {
        std::ofstream output_file;
        output_file.open(argv[6], std::ios::app);
        if(output_file.fail())
            throw FailedToOpenException();
        std::cerr << e.what();
        output_file << e.what();
        output_file.close();
    }
}

void Simulation::generate_handout()
{
    try
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        Handout handout(data.list_of_clients.return_client(generator() % data.list_of_clients.return_size()),
                        data.list_of_employees.return_employee(generator() % data.list_of_employees.return_size()),
                        data.list_of_desks.return_desk(generator() % data.list_of_desks.return_size()),
                        generator() % TRANSFER_LIMIT,
                        Handout::return_new_id());
        handout.do_cash_handout(argv[6]);
    }
    catch(DebtException& e)
    {
        std::ofstream output_file;
        output_file.open(argv[6], std::ios::app);
        if(output_file.fail())
            throw FailedToOpenException();
        std::cerr << e.what();
        output_file << e.what();
        output_file.close();
    }
    catch(WrongMachineException& e)
    {
        std::ofstream output_file;
        output_file.open(argv[6], std::ios::app);
        if(output_file.fail())
            throw FailedToOpenException();
        std::cerr << e.what();
        output_file << e.what();
        output_file.close();
    }
}

void Simulation::do_operation(unsigned choice)
{
    switch (choice)
    {   
        case 0:
            generate_transfer();
            break;
        case 1:
            generate_handout();
            break;
        case 2:
            generate_deposit();
            break;
        default:
            break;
    }
}

void Simulation::set_simulation_parameters(char* file_name)
{
    std::ifstream text_file;
    text_file.open(file_name);
    if(text_file.fail())
        throw FailedToOpenException();
    text_file >> TRANSFER_LIMIT;
    text_file >> NUMBER_OF_OPERATIONS;
    text_file.close();
}