#ifndef SIMULATION_H
#define SIMULATION_H
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>
#include "simulation_interface.h"
#include "data.h"
#include "transfer.h"
#include "deposit.h"
#include "handout.h"
#include "same_client_exception.h"
#include "failed_to_open_exception.h"

class Simulation : public SimulationInterface
{
    private:
        Data data;
        int argc;
        char** argv;
        unsigned TRANSFER_LIMIT = 600;
        int NUMBER_OF_OPERATIONS = 5;
        static const int NUM_OF_AVAILABLE_OPERATIONS = 3;
    public:
        Simulation(int argc, char** argv);
        void do_simulation() override;
        void generate_transfer() override;
        void generate_handout() override;
        void generate_deposit() override;
        void do_operation(unsigned choice) override;
        void set_simulation_parameters(char* file_name) override;
};

#endif