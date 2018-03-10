#pragma once

#include <queue>

class Philosopher;

struct Fork{
	bool Available=true;
};

struct Wish{
	Philosopher* Philosopher;
	unsigned LeftFork;
	unsigned RightFork;
};

class Storage
{
	std::queue<Wish> wishQueue;
	std::vector<Philosopher>
};


