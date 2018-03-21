#include <iostream>
#include "Storage.hpp"
#include "Philosopher.hpp"

/// @brief Creates basic container
/// @param amount amount of elements to be initialised
Storage::Storage(unsigned long amount)
{
	forkVector=std::vector<Fork>(amount);
	philosopherPtrVector_=std::vector<std::shared_ptr<Philosopher>>();
	for(auto i=0u;i<amount;i++)
		philosopherPtrVector_.emplace_back(new Philosopher(std::chrono::milliseconds(2000),this));
	
}

void Storage::returnForks(std::pair<unsigned,unsigned> forkPair)
{
	std::lock_guard<std::mutex> lockGuard(forkVectorMutex_);
	forkVector[forkPair.first].Available=true;
	forkVector[forkPair.second].Available=true;

	Launcher::Logger()->printQ("Forks returned: {"
							   +std::to_string(forkPair.first)+","
							   +std::to_string(forkPair.second)+"}."
	);
	//scanSubscriptionList();
}

/// @brief scans subscription list for fork availability
/// @description
/// @return if something changed true, otherwise false
bool Storage::scanSubscriptionList()
{
	std::lock_guard<std::mutex> lockGuard(subscriptionVectorMutex_);
	Launcher::Logger()->printQ("Scanning subscription list. Size:"+std::to_string(subscriptionList_.size()));

	for(auto element=subscriptionList_.begin();
		element!=subscriptionList_.end();
		element++)
	{
		if(forkVector[element->second.first].Available&&
		   forkVector[element->second.second].Available)
		{
			forkVector[element->second.first].Available=false;
			forkVector[element->second.second].Available=false;
			element->first();
			
			subscriptionList_.erase(element--);
		}
	}
	Launcher::Logger()->printQ("Scan completed. Size:"+std::to_string(subscriptionList_.size()));
}

void Storage::subscribe(std::function<void()> trigger,std::pair<unsigned,unsigned> forksPair)
{
	std::lock_guard<std::mutex> lockGuard(subscriptionVectorMutex_);
	subscriptionList_.emplace_back(trigger,forksPair);
}

bool Storage::getEnd() const
{
	return end_;
}
void Storage::setEnd(bool end)
{
	end_=end;
}

void Storage::runner()
{
	Launcher::Logger()->printQ("Starting the runner");
	
	while(!(end_ && subscriptionList_.empty()))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		scanSubscriptionList();
	}
	
	Launcher::Logger()->printQ("Stopping runner.");
}
