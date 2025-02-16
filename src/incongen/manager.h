#ifndef INCONGEN_MANAGER_H
#define INCONGEN_MANAGER_H

#include "incogen/fromfile.h"
#include "incogen/fromcmd.h"

namespace incongen
{
	class Manager
	{
		inline static const std::string PROGRAM_NAME = "incongen: INitial_CONditions_GENerator";
		
	public:
		static void run();
	};
}

#endif
