#include <iostream>
#include "Philosopher.hpp"
#include "Launcher.hpp"
unsigned Philosopher::idCounter=0;


Philosopher::Philosopher(const std::chrono::milliseconds &eatDuration,Storage *storage):
		eatDuration_(eatDuration),
		storage_(storage),
		id_(++idCounter),
		forksReady_(false),
		counter_(0)
{}

void Philosopher::execute()
{
	unsigned forkLeft=id_-1,forkRight=id_==idCounter?0:id_;
	std::unique_lock<std::mutex> uniqueLock(philosopherMutex_);
	while(!storage_->getEnd())
	{
		storage_->subscribe(std::bind(&Philosopher::trigger,this),{forkLeft,forkRight});
		conditionVariable_.wait(uniqueLock,[this]{return forksReady_;});
		Launcher::Logger()->printQ(
				"Philosopher: "
				+std::to_string(id_)
				+", Acquired food - Eating for: "
				+std::to_string(eatDuration_.count())
		);
		std::this_thread::sleep_for(eatDuration_);
		counter_++;
		storage_->returnForks({forkLeft,forkRight});
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
	forksReady_=true;
	Launcher::Logger()->printQ("Philosopher: "+std::to_string(id_)+", Acquired forks.");
	conditionVariable_.notify_all();
}
