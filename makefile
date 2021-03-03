all: same_client_exception wrong_machine_exception debt_exception desk_interface desk desk_list atm cdm client_interface client client_list business_client individual_client employee_interface employee employee_list service_interface service handout deposit transfer simulation_interface simulation data data_interface failed_to_open_exception unable_to_save_exception main link

link:
	g++ -g -Wall -o program main.o simulation.o wrong_machine_exception.o debt_exception.o desk_interface.o desk.o desk_list.o atm.o cdm.o client_interface.o client.o individual_client.o business_client.o client_list.o employee.o employee_interface.o employee_list.o service.o service_interface.o data.o handout.o deposit.o transfer.o simulation_interface.o data_interface.o same_client_exception.o failed_to_open_exception.o unable_to_save_exception.o
main:
	g++ -g -Wall -c main.cpp

wrong_machine_exception:
	g++ -g -Wall -c wrong_machine_exception.cpp

debt_exception:
	g++ -g -Wall -c debt_exception.cpp

desk_interface:
	g++ -g -Wall -c desk_interface.cpp

desk:
	g++ -g -Wall -c desk.cpp

desk_list:
	g++ -g -Wall -c desk_list.cpp 

atm:
	g++ -g -Wall -c atm.cpp

cdm:
	g++ -g -Wall -c cdm.cpp

client_interface:
	g++ -g -Wall -c client_interface.cpp

client:
	g++ -g -Wall -c client.cpp

individual_client:
	g++ -g -Wall -c individual_client.cpp

business_client:
	g++ -g -Wall -c business_client.cpp 

client_list:
	g++ -g -Wall -c client_list.cpp

employee_interface:
	g++ -g -Wall -c employee_interface.cpp

employee:
	g++ -g -Wall -c employee.cpp

employee_list:
	g++ -g -Wall -c employee_list.cpp

service_interface:
	g++ -g -Wall -c service_interface.cpp

service:
	g++ -g -Wall -c service.cpp

handout:
	g++ -g -Wall -c handout.cpp 

deposit:
	g++ -g -Wall -c deposit.cpp

transfer:
	g++ -g -Wall -c transfer.cpp

simulation_interface:
	g++ -g -Wall -c simulation_interface.cpp	

simulation:
	g++ -g -Wall -c simulation.cpp

data:
	g++ -g -Wall -c data.cpp

data_interface:
	g++ -g -Wall -c data_interface.cpp

same_client_exception:
	g++ -g -Wall -c same_client_exception.cpp

failed_to_open_exception:
	g++ -g -Wall -c failed_to_open_exception.cpp

unable_to_save_exception:
	g++ -g -Wall -c unable_to_save_exception.cpp

clean:
	rm *.o
	rm output.txt