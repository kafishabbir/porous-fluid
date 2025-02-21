#ifndef INCONGEN_MANAGER_H
#define INCONGEN_MANAGER_H


#include "incogen/fileread.h"
#include "incogen/filewrite.h"

/**
 * incongen: working modes
 *
 * nrows = n
 * ncols = n
 * tradius = {const=0.1, imbibition, function}
 * tlength = {const=1.0, inverse_radius}
 * tmns = {saturate_oil, saturate_water, imbibition}
 */

namespace incongen
{
	class Manager
	{
		inline static const std::string PROGRAM_NAME = "incongen: INitial_CONditions_GENerator";

		static void generate_from_incongen_config(
			const dst::IncongenConfig& incongen_config
		);
		static void interactive_mode();


	public:
		static void run();
	};

}

#endif
