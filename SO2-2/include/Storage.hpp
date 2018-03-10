#pragma once

#include <queue>
#include <memory>

class Philosopher;

struct Fork{
	bool Available=true;
};

class Storage
{
	std::vector<std::shared_ptr<Philosopher>> philosopherPtrVector_;
	std::vector<Fork> forkVector;
	
public:
	explicit Storage(unsigned long amount=5);
};


