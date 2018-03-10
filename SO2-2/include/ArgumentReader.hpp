#pragma once

#include <string>
#include <list>

class ArgumentReader
{
	std::list<std::string> args_;
public:
	const std::list<std::string> &getArgs() const;
	
	ArgumentReader(int argc, char *args[]);
};


