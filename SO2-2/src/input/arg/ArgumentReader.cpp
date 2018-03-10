#include "ArgumentReader.hpp"

/// @brief allows for access to arguments
/// @return Known list of args
const std::list<std::string> &ArgumentReader::getArgs() const
{
	return args_;
}

/// @brief Pars input into strings
/// @description
/// Simplifies parsing process
/// @param argc - Argument count
/// @param args - Arguments
ArgumentReader::ArgumentReader(int argc, char **args)
{
	for(auto i=0u;i<argc;i++)
		args_.emplace_back(args[i]);
}
