#include <iostream>
#include <fstream>
#include "Philosopher.hpp"

/// @brief Initialise philosopher with most important values
/// @param controller - Object which will control behaviour of philosopher
/// @param id - identifier
/// @param[opt] name - name which identify philosopher
Philosopher::Philosopher(Controller *controller, unsigned int id,const std::string &name):
		id_(id),
		name_(name),
		controller_(controller)
{}

void Philosopher::DoYourThing()
{
	std::fstream file(std::to_string(id_)+".log",std::ios::out | std::ios::trunc);
	unsigned leftFork=id_-1;
	unsigned rightFork=id_==5?0:id_;
	file
		<< "Initialised philosopher with id: "
		<< id_
		<< "With forks: Left-> "
		<< leftFork
		<< ", Right-> "
		<< rightFork;
	
	int counter = 5;
	while(counter not_eq  0)
	{
		controller_->getFork(leftFork);
		file << "Acquired fork.\n";
		controller_->getFork(rightFork);
		file << "Acquired fork.\n";
		file << "Eating.\n";
		file << "Returning left fork.\n";
		controller_->returnFork(leftFork);
		file << "Returning right fork.\n";
		controller_->returnFork(rightFork);
		file << "Thinking.\n";
		counter--;
	}
	file << "Sated.\n";
}
