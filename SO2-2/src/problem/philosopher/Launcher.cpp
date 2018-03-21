#include <FileOutput.hpp>
#include <Philosopher.hpp>
#include <thread>
#include "Launcher.hpp"

std::shared_ptr<OutputController> Launcher::outputController;

Launcher::Launcher(int argc,char **args)
{
	load({argc,args});
	storagePtr_=std::make_shared<Storage>(amountOfPhilosophers_);
}

void Launcher::start()
{
	outputController->printQ("READY.");
	outputController->printQ("Preparing threads.");
	prepareThreads();
	outputController->printQ("60 000 milliseconds wait...");
	std::this_thread::sleep_for(std::chrono::seconds(60));
	outputController->printQ("Joining them...");
	collectThreads();
	outputController->printQ("All done!");
}

void Launcher::load(ArgumentReader ar)
{
	auto it=ar.getArgs().begin();
	while((++it)!=ar.getArgs().end())
	{
		if(*it=="-f") //NOLINT
			outputController=std::make_shared<FileOutput>();
		if(*it=="-c") //NOLINT
			outputController=nullptr;
		if(*it=="-p") //NOLINT
			amountOfPhilosophers_=std::stoul(*(++it));
		}
}

const std::shared_ptr<OutputController> &Launcher::Logger()
{
	return outputController;
}

void Launcher::prepareThreads()
{
	for(auto philosopher:storagePtr_->philosopherPtrVector_)
		activeThreadVector_.emplace_back(std::bind(&Philosopher::run,philosopher));
	activeThreadVector_.emplace_back(std::bind(&Storage::runner,storagePtr_));
}

void Launcher::collectThreads()
{
	storagePtr_->setEnd(true);
	for(auto&& thread:activeThreadVector_)
		thread.join();
}
