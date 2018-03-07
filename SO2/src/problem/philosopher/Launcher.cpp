#include <thread>
#include <zconf.h>
#include <iostream>
#include "Launcher.hpp"

void Launcher::Start()
{
	spawnPhilosophers();
	std::thread thread1(&Philosopher::DoYourThing,&philosopherVector_[0]);
	std::thread thread2(&Philosopher::DoYourThing,&philosopherVector_[1]);
	std::thread thread3(&Philosopher::DoYourThing,&philosopherVector_[2]);
	std::thread thread4(&Philosopher::DoYourThing,&philosopherVector_[3]);
	std::thread thread5(&Philosopher::DoYourThing,&philosopherVector_[4]);
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();
}

void Launcher::spawnPhilosophers()
{
	for(auto i=0u;i<5;i++)
		philosopherVector_.emplace_back(&this->controller_,i+1);
}
