#pragma once

#include <memory>
#include "Storage.hpp"

/// @brief Initialise application and start it
/// @description
/// Constructor takes amount of dinning and based on that
/// creates storage and forks
class Launcher
{
	std::shared_ptr<Storage> storagePtr_;
public:
	explicit Launcher(unsigned int amountOfPhilosopherDinning);
};
