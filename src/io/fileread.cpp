#include "io/fileread.h"

std::pair<tdouble_type, bool> io::FileRead::radius()
{
	return io::FileRead::table<double>(decl::file::input::RADIUS);
}

std::pair<tdouble_type, bool> io::FileRead::length()
{
	return io::FileRead::table<double>(decl::file::input::LENGTH);
}

std::pair<dst::Parameter, bool> io::FileRead::parameter()
{
	std::ifstream fin(decl::file::input::PARAMETER);
	dst::Parameter buffer;
	if(!fin)
	{
		std::cout << "-ERR- cound not open parameter.txt" << std::endl;
		return {buffer, false};
	}

	std::string buffer_str;
	while(fin >> buffer_str)
	{
		const std::string name = algo::Utility::split(buffer_str).first;
		const double val = std::stod(algo::Utility::split(buffer_str).second);
		const bool success = buffer.set(name, val);
		if(!success)
		{
			std::cout << "-ERR- parameter.txt is corrupted, failure reading" << buffer_str << std::endl;
			return {buffer, false};
		}
	}
	return {buffer, true};
}

std::pair<tmns_type, bool> io::FileRead::mns()
{
	return io::FileRead::table<dst::Mns>(decl::file::input::MNS);
}

std::pair<dst::InputFiles, bool> io::FileRead::all()
{
	dst::InputFiles input_files;

	// STEP-1.1 read radius
	const auto& buffer_radius = io::FileRead::radius();
	if(!buffer_radius.second)
	{
		std::cout << "-ERR-radius.txt is corrupted" << std::endl;
		return {input_files, false};
	}
	input_files.tradius = buffer_radius.first;

	// STEP-1.2 read mns
	const auto& buffer_mns = io::FileRead::mns();
	if(!buffer_mns.second)
	{
		std::cout << "-ERR-mns.txt meniscus configuration file is corrupted" << std::endl;
		return {input_files, false};
	}
	input_files.tmns = buffer_mns.first;

	// STEP-1.3 read length
	const auto& buffer_length = io::FileRead::length();
	if(!buffer_length.second)
	{
		std::cout << "-ERR-length.txt meniscus file is corrupted" << std::endl;
		return {input_files, false};
	}
	input_files.tlength = buffer_length.first;

	// STEP-1.4 read parameter
	const auto& buffer_parameter = io::FileRead::parameter();
	if(!buffer_parameter.second)
	{
		std::cout << "-ERR-parameter meniscus file is corrupted" << std::endl;
		return {input_files, false};
	}
	input_files.parameter = buffer_parameter.first;


	input_files.dimension = network::Dimension(input_files.tradius);
	const network::Dimension dmns(input_files.tmns);
	const network::Dimension dlength(input_files.tlength);

	// STEP-2.1 check if tmns_type dimensions are okay
	if(!(input_files.dimension == dmns))
	{
		std::cout << "-ERR-Dimensions of tmns_type.txt is not correct" << std::endl;
		return {input_files, false};
	}

	// STEP-2.2 check if tlength dimensions are okay
	if(!(input_files.dimension == dlength))
	{
		std::cout << "-ERR-Dimensions of tlength.txt is not correct" << std::endl;
		return {input_files, false};
	}

	std::cout << "--FDK-All input files read correctly" << std::endl;
	return {input_files, true};
}



std::pair<dst::TxtIncongen, bool> io::FileRead::txt_incongen()
{
	dst::TxtIncongen buffer;
	std::ifstream fin(decl::file::input::INCONGEN);

	if(!fin)
	{
		return {buffer, false};
	}

	std::string buffer_line;
	std::set<std::string> buffer_set_of_cats;
	while(fin >> buffer_line)
	{
		const bool set = buffer.set(buffer_line);
		if(!set)
		{
			std::cout << "-ERR-in io::FileRead::txt_incongen(), " << buffer_line << " failed to be set" << std::endl;
			return {buffer, false};
		}
		buffer_set_of_cats.insert(algo::Utility::split(buffer_line).first);
	}

	if(buffer_set_of_cats != dst::TxtIncongen::set_of_cats())
	{
		std::cout << "-ERR-input/incongen.txt does not have all the cats, forcefully rewriting it" << std::endl;
		return {buffer, false};
	}


	return {buffer, true};
}
