#ifndef SO2_CONTROLLER_HPP
#define SO2_CONTROLLER_HPP

#include <memory>
#include <mutex>
#include "Storage.hpp"

using Fork=Storage::Fork;

class Controller
{
	/// @brief Active storage pointer, used by philosophers.
	std::shared_ptr<Storage> storagePtr_=std::make_shared<Storage>();
	std::mutex storageMutex_;
public:
	Controller()=default;
	
	Fork* getFork(unsigned id);
	void returnFork(unsigned id);
};

#endif //SO2_CONTROLLER_HPP
