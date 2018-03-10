#include <FileOutput.hpp>
#include "Launcher.hpp"

Launcher::Launcher(int argc,char **args)
{
	load({argc,args});
	storagePtr_=std::make_shared<Storage>({amountOfPhilosophers_});
}

void Launcher::start()
{

}

void Launcher::load(ArgumentReader ar)
{
	auto it=ar.getArgs().begin();
	do{
		if(*it=="-f")
			outputController_=std::make_shared<FileOutput>();
		if(*it=="-c")
			outputController_=nullptr;
		if(*it=="-p")
			amountOfPhilosophers_=std::stoul(*(++it));
	}while((++it)->empty());
}
