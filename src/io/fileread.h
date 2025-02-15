#ifndef IO_FILEREAD_H
#define IO_FILEREAD_H

#include "network/dimension.h"
#include "dst/parameter.h"
#include "dst/inputfiles.h"
#include "dst/txtincongen.h"


namespace io
{
	class FileRead
	{

		template<class T>
		static std::pair<std::vector<std::vector<T>>, bool> table(
			const std::string& file_name);

	public:
		static std::pair<dst::TxtIncongen, bool> txt_incongen();
		static std::pair<tdouble_type, bool> radius();
		static std::pair<tmns_type, bool> mns();
		static std::pair<tdouble_type, bool> length();
		static std::pair<dst::Parameter, bool> parameter();
		static std::pair<dst::InputFiles, bool> all();

	};
}

template<class T>
std::pair<std::vector<std::vector<T>>, bool> io::FileRead::table(const std::string& file_name)
{
	std::vector<std::vector<T>> buffer;

	std::ifstream fin(file_name);
	if(!fin)
	{
		std::cout << "-ERR-" << file_name << " does not exist, create using generate or restore manually." << std::endl;
		return {buffer, false};
	}

	int rows, cols;
	fin >> rows >> cols;

	std::vector<T> buffer_vec;
	T ipt;
	while(fin >> ipt)
	{
		buffer_vec.push_back(ipt);
	}


	if(buffer_vec.size() != size_t(rows * cols))
	{
		std::cout << "-ERR-in file " << file_name << " rows, cols are declared differently than the actual data in them." << std::endl;
		return {buffer, false};
	}

	buffer = std::vector<std::vector<T>>(rows, std::vector<T>(cols));
	int count = 0;
	for(auto& row: buffer)
	{
		for(auto& cell: row)
		{
			cell = buffer_vec[count ++];
		}
	}

	return {buffer, true};
}

#endif
