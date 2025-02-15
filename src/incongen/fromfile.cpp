#include "incongen/fromfile.h"

bool incongen::FromFile::generate()
{
	// read input/incongen.txt
	// if the file is good, generate accordingly
	// if bad write a default template and return false

	const std::pair<dst::TxtIncongen, bool>& txt_incongen_buffer
		= io::FileRead::txt_incongen();

	if(!txt_incongen_buffer.second)
	{
		io::FileWrite::sample_txt_incongen();
		return false; 
	}

	const dst::TxtIncongen& txt_incongen  = txt_incongen_buffer.first;
	incongen::TRadius::write_to_file(txt_incongen.tradius);
	incongen::TLength::write_to_file(txt_incongen.tlength);
	incongen::TMns::write_to_file(txt_incongen.tmns);
	// about parameter we think a bit later
	return true;
}

