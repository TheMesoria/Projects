#include "FileOutput.hpp"

FileOutput::FileOutput(std::string path)
{
	path_=path;
}

void FileOutput::update()
{
	std::lock_guard lockGuard(inflowBufferQueueMutex_);
	std::fstream file(path_, std::ios::out | std::ios::ate);
	
	while(not inflowBufferQueue_.empty())
	{
		file << inflowBufferQueue_.front() << std::endl;
		inflowBufferQueue_.pop();
	}
}
