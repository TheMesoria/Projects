#include <ncurses.h>
#include <Launcher.hpp>
#include "NCursesController.hpp"
#include "Philosopher.hpp"

NCursesController::NCursesController(const std::shared_ptr<Storage> &storagePtr):
		storagePtr_(storagePtr)
{}

void NCursesController::run()
{
	initscr();
	raw();
	Launcher::Logger()->printQ("NCurses Starting...");
	while(!(storagePtr_->end_ && storagePtr_->subscriptionList_.empty()))
	{
		int base=1;
		for(auto& philosopherPtr:storagePtr_->philosopherPtrVector_)
		{
			mvprintw(base++,0,"Forks: "+philosopherPtr->forksReady_?"Ready":"Not Ready");
		}
		refresh();
	}
	Launcher::Logger()->printQ("NCurses Stopping...");
	endwin();
}
