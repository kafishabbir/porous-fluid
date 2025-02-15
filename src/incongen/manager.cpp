#include "incongen/manager.h"

void incongen::Manager::run()
{
	std::cout << PROGRAM_NAME << std::endl;

	// If the file input/incongen.txt is good:
	//		then the program generates all input files accordingly
	//		otherwise it goes to interactive mode
	if(!incongen::FromFile::generate())
	{
		incongen::FromCmd::generate();
	}
}


