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
	outputController->print("READY.");
	outputController->update();
	
	auto tmp = storagePtr_->philosopherPtrVector_.at(0).get();
	std::thread runner(std::bind(&Philosopher::run,tmp));
	storagePtr_->scanSubscriptionList();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	tmp->end_=true;
	
	runner.join();
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
