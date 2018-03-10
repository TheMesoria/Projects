#pragma once

#include <memory>
#include "Storage.hpp"
#include "ArgumentReader.hpp"
#include "OutputController.hpp"

/// @brief Initialise application and start it
/// @description
/// Constructor takes amount of dinning and based on that
/// creates storage and forks
class Launcher
{
	std::shared_ptr<Storage> storagePtr_;
	std::shared_ptr<OutputController> outputController_;
	
	unsigned long amountOfPhilosophers_;
	
private:
	void load(ArgumentReader ar);
public:
	void start();
	
	
	~Launcher()=default;
	explicit Launcher(int argc, char *args[]);
};
