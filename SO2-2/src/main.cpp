#include <cstdlib>
#include <Launcher.hpp>

int main(int argc,char **args)
{
	Launcher launcher(argc,args);
	launcher.start();
	return EXIT_SUCCESS;
}