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
		philosopherPtrVector_.emplace_back(new Philosopher(std::chrono::milliseconds(500),this));
	
}

void Storage::returnForks(std::pair<unsigned,unsigned> forksPair)
{
	std::lock_guard<std::mutex> lockGuard(forkVectorMutex_);
	forkVector[forksPair.first].Available=true;
	forkVector[forksPair.second].Available=true;
}

/// @brief scans subscription list for fork availability
/// @description
/// @return if something changed true, otherwise false
bool Storage::scanSubscriptionList()
{
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
	
}

void Storage::subscribe(std::function<void()> trigger,std::pair<unsigned,unsigned> forksPair)
{
	subscriptionList_.emplace_back(trigger,forksPair);
}
