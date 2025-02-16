#include "dst/txtincongen.h"

std::set<std::string> dst::TxtIncongen::set_of_cats()
{
	std::set<std::string> set;
	for(const auto& cat_and_val: dst::decls_incongen_nps::cat_and_vals_vec)
	{
		set.insert(cat_and_val.cat);
	}

	return set;
}


bool dst::TxtIncongen::set(const std::string& buffer_line)
{
	const std::string& cat = algo::Utility::split(buffer_line).first;
	const std::string& val = algo::Utility::split(buffer_line).second;

	if(cat == dst::decls_incongen_nps::possible_nps::cats_nps::nrows)
	{
		this->nrows = std::stoi(val);
		return true;
	}
	if(cat == dst::decls_incongen_nps::possible_nps::cats_nps::ncols)
	{
		this->ncols = std::stoi(val);
		return true;
	}
	if(cat == dst::decls_incongen_nps::possible_nps::cats_nps::tradius)
	{
		const std::vector<std::string>& possible_vals
			= find_vals_of_corresponding_cat(cat);

		const std::pair<std::pair<std::string, double>, bool> buffer_match
			= match_with_val(val, possible_vals);

		if(!buffer_match.second)
		{
			return false;
		}

		this->tradius = buffer_match.first;
		return true;
	}
	if(cat == dst::decls_incongen_nps::possible_nps::cats_nps::tlength)
	{
		const std::vector<std::string>& possible_vals
			= find_vals_of_corresponding_cat(cat);

		const std::pair<std::pair<std::string, double>, bool> buffer_match
			= match_with_val(val, possible_vals);

		if(!buffer_match.second)
		{
			return false;
		}

		this->tlength = buffer_match.first;
		return true;
	}
	if(cat == dst::decls_incongen_nps::possible_nps::cats_nps::tmns)
	{
		const std::vector<std::string>& possible_vals
			= find_vals_of_corresponding_cat(cat);

		const std::pair<std::pair<std::string, double>, bool> buffer_match
			= match_with_val(val, possible_vals);

		if(!buffer_match.second)
		{
			return false;
		}

		this->tmns = val;
		return true;
	}
	
	std::cout << "Error in dst::TxtIncongen::set(), category match error" << std::endl;
	return false;
}


bool dst::TxtIncongen::is_const(const std::string& s)
{
	const std::string target
		= dst::decls_incongen_nps::possible_nps::vals_nps::constant_keyword;
	return s.substr(0, target.size()) == target;
}

std::pair<std::pair<std::string, double>, bool>
	dst::TxtIncongen::match_with_val(
		const std::string& val, 
		const std::vector<std::string>& vals_vec)
{
	std::pair<std::string, double> buffer;

	if(is_const(val))
	{
		buffer.second = std::stod(algo::Utility::split(val).second);
		buffer.first
			= dst::decls_incongen_nps::possible_nps::vals_nps::constant_keyword;
		return {buffer, true};
	}

	for(const std::string& val_reference: vals_vec)
	{
		if(val_reference == val)
		{
			buffer.first = val;
			return {buffer, true};
		}
	}
	
	std::cout << "Error in match_with_val(), no match found!" << std::endl;
	return {buffer, false};
}


std::vector<std::string> dst::TxtIncongen::find_vals_of_corresponding_cat(const std::string& s)
{
	for(const dst::decls_incongen_nps::catAndvals& cv:
		dst::decls_incongen_nps::cat_and_vals_vec)
	{
		if(cv.cat == s)
		{
			return cv.vals;
		}
	}

	std::cout << "Error in txtincongen.cpp in determining vals" << std::endl;
	return {};
}
