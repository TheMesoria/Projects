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
	static std::shared_ptr<OutputController> outputController;
	
	unsigned long amountOfPhilosophers_=5;
	
private:
	void load(ArgumentReader ar);
public:
	void start();
	
	static const std::shared_ptr<OutputController> &Logger();
	
	~Launcher()=default;
	explicit Launcher(int argc, char *args[]);
};
