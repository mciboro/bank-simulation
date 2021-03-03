#ifndef SIMULATION_INTERFACE_H
#define SIMULATION_INTERFACE_H

class SimulationInterface
{
    public:
        virtual void do_simulation() = 0;
        virtual void generate_transfer() = 0;
        virtual void generate_handout() = 0;
        virtual void generate_deposit() = 0;
        virtual void do_operation(unsigned choice) = 0;
        virtual void set_simulation_parameters(char* file_name) = 0;
        virtual ~SimulationInterface() = 0;
};

#endif