#include "FileOutput.hpp"

#include <utility>

FileOutput::FileOutput(std::string path)
{
	std::fstream file(path,std::ios::out | std::ios::trunc);
	path_=std::move(path);
}
FileOutput::~FileOutput()
{
	update();
}

void FileOutput::update()
{
	std::lock_guard<std::mutex> lockGuard(inflowBufferQueueMutex_);
	std::fstream file(path_, std::ios::app | std::ios::out);
	
	while(not inflowBufferQueue_.empty())
	{
		file << inflowBufferQueue_.front() << std::endl;
		inflowBufferQueue_.pop();
	}
}
