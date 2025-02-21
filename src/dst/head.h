#ifndef HEAD_DECLS_H
#define HEAD_DECLS_H

#include <cmath>
#include <limits>
#include <string>
// Handbook of physical constants:
// sigma = 7.56e-2 water at 20C in SI units
// mu_water = 1e-3 viscosity in SI units



namespace decl
{
	namespace file
	{
		namespace input
		{
			const std::string FOLDER = "input/";
			const std::string RADIUS = FOLDER + "tradius.txt";
			const std::string LENGTH = FOLDER + "tlength.txt";
			const std::string MNS = FOLDER + "tmns.txt";
			const std::string PARAMETER = FOLDER + "parameter.txt";
			const std::string INCONGEN = FOLDER + "incongen.txt";
		}

		namespace output
		{
			const std::string FOLDER = "result/";
			const std::string CALCULATION = FOLDER + "calculation/";
			const std::string GRAPH = FOLDER + "graph/";
			const std::string INITIAL = FOLDER + "initial/";
			const std::string NORADIUS = FOLDER + "noradius/";
			const std::string PRESSURE = FOLDER + "pressure/";
			const std::string THICK = FOLDER + "thick/";
			const std::string VELOCITY = FOLDER + "velocity/";
		}
	}

	namespace math
	{
		const double PI = std::acos(-1);
		const double HUGE = std::numeric_limits<double>::max();
	}

	namespace computation
	{
		const double TRIMMER_PRECISION = 1e-6; // FINDOUT
		const double TIME_DIV = 10;	// resolution while selecting time step
		const double IGNORE_VEL = 1e8; // If any velocity in the porous body is IGNORE_VEL times less than the max velocity then it is forced to be 0
	}

	namespace plot
	{
		const int IMAGE_SIZE = 1000;
	}
}

#endif
