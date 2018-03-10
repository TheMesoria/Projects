#include <FileOutput.hpp>
#include "Launcher.hpp"

Launcher::Launcher(int argc,char **args)
{
	load({argc,args});
	storagePtr_=std::make_shared<Storage>(amountOfPhilosophers_);
}

void Launcher::start()
{
	outputController_->print("READY.");
	outputController_->update();
}

void Launcher::load(ArgumentReader ar)
{
	auto it=ar.getArgs().begin();
	while((++it)!=ar.getArgs().end())
	{
		if(*it=="-f") //NOLINT
			outputController_=std::make_shared<FileOutput>();
		if(*it=="-c") //NOLINT
			outputController_=nullptr;
		if(*it=="-p") //NOLINT
			amountOfPhilosophers_=std::stoul(*(++it));
		}
}
