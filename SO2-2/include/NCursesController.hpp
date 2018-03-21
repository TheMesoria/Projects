#pragma once

#include "Storage.hpp"

class NCursesController
{
	std::shared_ptr<Storage> storagePtr_;
public:
	explicit NCursesController(const std::shared_ptr<Storage> &storagePtr);
	void run();
};


