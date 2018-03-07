#include "Controller.hpp"

/// @brief Access the storage and pull resource.
/// @param id - Identifier of fork
/// @return Fork, which have been accessed, or nullptr
Fork* Controller::getFork(unsigned id)
{
	std::lock_guard lock_guard(this->storageMutex_);
	Fork* value=storagePtr_->getKey(id);
	
	if(!value->Avaiable)
		return nullptr;
	
	value->Avaiable=false;
	return value;
}

void Controller::returnFork(unsigned id)
{
	std::lock_guard lockGuard(this->storageMutex_);
	this->storagePtr_->getKey(id)->Avaiable=true;
}
