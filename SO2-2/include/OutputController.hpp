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
	
	~OutputController()=default;
	OutputController()=default;
	
public:
	inline void print(std::string const&message)
	{
		std::lock_guard lockGuard(inflowBufferQueueMutex_);
		inflowBufferQueue_.push(message);
	}
};


