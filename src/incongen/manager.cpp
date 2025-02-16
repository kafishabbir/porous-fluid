#include "incongen/manager.h"


/**
 * @brief generates all input files for simulation if a valid config
 * is detected, otherwise runs in interactive mode.
 * 
 *
 */
 
void incongen::Manager::run()
{
	std::cout << incongen::Manager::PROGRAM_NAME << std::endl;
	
	const std::pair<incongen_config, bool>& buffer = 
		read_incongen_config();
		
	bool incongen-config_read_success = buffer.second;
	
	if(read_successs)
	{
		generare from file;
		return;
	}
	
	generate_a_sample_file
	switchin_on_interactive mode();
}


