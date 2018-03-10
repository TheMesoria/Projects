#include "OutputController.hpp"

//TODO Add description
/**
 * @brief Adds message to print queue
 *
 * @description
 *
 * @param message - Thing you want to pass to message log
 */
inline void OutputController::print(std::string const&message)
{
	std::lock_guard lockGuard(inflowBufferQueueMutex_);
	inflowBufferQueue_.push(std::string("Called from: ") + __FUNCTION__ + " - " +message);
}
