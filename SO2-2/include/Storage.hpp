#pragma once

#include <list>
#include <memory>
#include <functional>
#include <vector>
#include <mutex>

class NCursesController;
class Launcher;

class Philosopher;

struct Fork{
	bool Available=true;
};

using SubscriptionList=std::list<
		std::pair<std::function<void()>,std::pair<unsigned,unsigned>>>;

class Storage
{
	std::mutex forkVectorMutex_;
	std::mutex subscriptionVectorMutex_;
	std::vector<std::shared_ptr<Philosopher>> philosopherPtrVector_;
	std::vector<Fork> forkVector;
	
	SubscriptionList subscriptionList_;
	bool end_=false;
public:
	void setEnd(bool anEnd);

public:
	bool getEnd() const;

public:
	explicit Storage(unsigned long amount=5);
	
	void subscribe(std::function<void()> trigger,
				   std::pair<unsigned,unsigned> forksPair
				  );
	void returnForks(std::pair<unsigned,unsigned> forkPair);
	void runner();
private:
	bool scanSubscriptionList();
	
	friend Launcher;
	friend NCursesController;
};


