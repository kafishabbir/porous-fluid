#include "dst/incongen-config.h"

bool dst::IncongenConfig::valid() const
{
	const bool validity =
		nrows_set &&
		ncols_set &&
		tradius_set &&
		tlength_set &&
		tmns_set;

	return validity;
}

bool dst::IncongenConfig::set(const std::string& buffer_line)
{
	const std::string& cat = algo::Utility::split(buffer_line).first;
	const std::string& val = algo::Utility::split(buffer_line).second;

	if(cat == "nrows")
	{
		return set_nrows(val);
	}
	if(cat == "ncols")
	{
		return set_ncols(val);
	}
	if(cat == "tradius")
	{
		return set_tradius(val);
	}
	if(cat == "tlength")
	{
		return set_tlength(val);
	}
	if(cat == "tmns")
	{
		return set_tmns(val);
	}

	std::cout << "-Err- in incongen-config.txt, category not recognized";
	return false;
}

bool dst::IncongenConfig::set_nrows(const std::string& val)
{
	nrows = std::stoi(val);
	nrows_set = true;

	return true;
}

bool dst::IncongenConfig::set_ncols(const std::string& val)
{
	ncols = std::stoi(val);
	ncols_set = true;

	return true;

}

std::pair<double, bool> dst::IncongenConfig::const_extraction(
	const std::string& s
)
{
	const std::string c = "constant";
	if(s.size() < c.size())
	{

	if(s.substr(0, c.size()) != c)
	{
		return {-1, false};
	}

	return {std::stod(algo::Utility::split(s).second), true};
}

bool dst::IncongenConfig::set_tradius(const std::string& val)
{
	const std::pair<double, bool> try_const =
		const_extraction(val);

	if(try_const.second)
	{
		tradius.first = val_tradius::constant;
		tradius.second = try_const.first;
		tradius_set = true;
		return true;
	}

	if(val == "imbibition")
	{
		tradius.first = val_tradius::imbibiton;
		tradius_set = true;
		return true;
	}

	if(val == "function")
	{
		tradius.first =  val_tradius::function;
		tradius_set = true;
		return true;
	}

	std::cout << "-Err- set_tradius(), value not recognized." << std::endl;
	return false;
}

bool dst::IncongenConfig::set_tlength(const std::string& val)
{
	const std::pair<double, bool> try_const =
		const_extraction(val);

	if(try_const.second)
	{
		tlength.first = val_tlength::constant;
		tlength.second = try_const.first;
		tlength_set = true;
		return true;
	}

	if(val == "inverse_radius")
	{
		tlength.first =  val_tlength::function;
		tlength_set = true;
		return true;
	}

	std::cout << "-Err- set_tlength(), value not recognized." << std::endl;
	return false;
}

bool dst::IncongenConfig::set_tmns(const std::string& val)
{
	if(val == "saturate_oil")
	{
		tmns.first =  val_tmns::saturate_oil;
		tmns_set = true;
		return true;
	}

	if(val == "saturate_water")
	{
		tmns.first =  val_tmns::saturate_water;
		tmns_set = true;
		return true;
	}

	if(val == "imbibition")
	{
		tmns.first =  val_tmns::imbibition;
		tmns_set = true;
		return true;
	}

	std::cout << "-Err- set_tmns(), value not recognized." << std::endl;
	return false;
}
