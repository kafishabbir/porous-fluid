#ifndef HEAD_TYPE_H
#define HEAD_TYPE_H
#include "dst/mns.h"


typedef std::vector<std::vector<double>> Tradius;
typedef std::vector<std::vector<double>> Tlength;
typedef std::vector<std::vector<double>> Tdouble;
typedef std::vector<std::vector<network::Mns>> Tmns;

struct SimulationInput
{
	Tradius tradius;
	Tlength tlength;
	Tmns tmns;
	dst::SimulationConfig simulation_config;
	network::Dimension dimension;
};


struct SimulationState
{
	Tradius tradius;
	Tlength tlength;
	dst::SimulationConfig simulation_config;
	network::Dimension dimension;

};
#endif
