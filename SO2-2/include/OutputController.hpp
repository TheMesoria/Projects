#pragma once
#include <string>
#include <queue>
#include <mutex>

class OutputController
{
protected:
	std::queue<std::string> inflowBufferQueue_;
	std::mutex inflowBufferQueueMutex_;
	
public:
	virtual void update()=0;
	
	virtual ~OutputController()=default;
	OutputController()=default;
	
public:
	inline void print(std::string const&message)
	{
		std::lock_guard<std::mutex> lockGuard(inflowBufferQueueMutex_);
		inflowBufferQueue_.push(message);
	}
	inline void printQ(std::string const&message)
	{
		print(message);
		update();
	}
};


