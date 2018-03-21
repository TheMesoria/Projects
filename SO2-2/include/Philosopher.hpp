#pragma once

#include <condition_variable>
#include "Storage.hpp"
#include "Launcher.hpp"

/// @brief Template of Philosopher
class Philosopher
{
	friend Launcher;
	static unsigned idCounter;
	unsigned id_;
	unsigned counter_;
	
	bool forksReady_;
	std::condition_variable conditionVariable_;
	std::mutex philosopherMutex_;
	
	std::chrono::milliseconds eatDuration_;
	std::chrono::time_point<std::chrono::system_clock> eatStartTimePoint_;
	
	Storage* storage_;
	
public:
	Philosopher(const std::chrono::milliseconds &eatDuration, Storage *storage);
	~Philosopher(){Launcher::Logger()->printQ("Id: "+std::to_string(id_)+", Amount: "+std::to_string(counter_));}
	void run();
	void execute();
private:
	void trigger();
};
