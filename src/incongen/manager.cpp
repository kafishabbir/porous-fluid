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

	const std::pair<dst::IncongenConfig, bool>& buffer =
		io::FileRead::incongen_config();

	bool success_reading_incongen_config = buffer.second;

	if(success_reading_incongen_config)
	{
		incongen::Manager::generate_from_incongen_config(buffer.first);
		return;
	}

	incongen::Manager::write_default_incongen_config();
	incongen::Manager::interactive_mode();
}



void incongen::Manager::generate_from_incongen_config(
	const dst::IncongenConfig& incongen_config
)
{
	SimulationInput simulation_input;
	if(incongen_config.radius ==



}



void incongen::Manager::interactive_mode()
{
	std::cout << "Under construction" << std::endl;

}



