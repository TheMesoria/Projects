#include "Storage.hpp"
#include "Philosopher.hpp"

Storage::Storage(unsigned long amount)
{
	this->forkVector=std::vector<Fork>(amount);
	this->philosopherPtrVector_=std::vector<std::shared_ptr<Philosopher>>();
}
