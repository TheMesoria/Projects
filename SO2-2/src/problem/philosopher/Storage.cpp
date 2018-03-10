#include "Storage.hpp"
#include "Philosopher.hpp"

/// @brief Creates basic container
/// @param amount amount of elements to be initialised
Storage::Storage(unsigned long amount)
{
	this->forkVector=std::vector<Fork>(amount);
	this->philosopherPtrVector_=std::vector<std::shared_ptr<Philosopher>>();
}
