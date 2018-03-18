#include <iostream>
#include "Philosopher.hpp"
#include "Launcher.hpp"
unsigned Philosopher::idCounter=0;


Philosopher::Philosopher(const std::chrono::milliseconds &eatDuration,Storage *storage):
		eatDuration_(eatDuration),
		storage_(storage),
		id_(++idCounter),
		end_(false),
		forksReady_(false)
{}

void Philosopher::execute()
{
	unsigned forkLeft=id_-1,forkRight=id_==idCounter?0:id_;
	std::unique_lock<std::mutex> uniqueLock(philosopherMutex_);
	while(!this->end_)
	{
		storage_->subscribe(std::bind(&Philosopher::trigger,this),{forkLeft,forkRight});
		conditionVariable_.wait(uniqueLock,[]{return true;});
		Launcher::Logger()->printQ("Philosopher: "+std::to_string(id_)+", Acquired food.");
	}
	Launcher::Logger()->printQ("Philosopher: "+std::to_string(id_)+", Is done for.");
}

void Philosopher::run()
{
	Launcher::Logger()->printQ("Philosopher ready!");
	execute();
}

void Philosopher::trigger()
{
	std::lock_guard<std::mutex> lockGuard(philosopherMutex_);
	Launcher::Logger()->printQ("Philosopher: "+std::to_string(id_)+", Acquired forks.");
	conditionVariable_.notify_all();
}
