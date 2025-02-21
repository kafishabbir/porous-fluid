#include "dst/parameter.h"

bool dst::Parameter::set(const std::string& name_parameter, const double val)
{
	if(name_parameter == dst::decls_parameter_nps::mu_oil)
	{
		this->mu_oil = val;
		return true;
	}
	if(name_parameter == dst::decls_parameter_nps::mu_water)
	{
		this->mu_water = val;
		return true;
	}
	if(name_parameter == dst::decls_parameter_nps::sigma)
	{
		this->sigma = val;
		return true;
	}
	if(name_parameter == dst::decls_parameter_nps::total_volumetric_flow_rate)
	{
		this->total_volumetric_flow_rate = val;
		return true;
	}
	
	return false;
}
