#ifndef DST_INPUTFILES_H
#define DST_INPUTFILES_H

#include "head/decl.h"
#include "network/dimension.h"
#include "dst/parameter.h"

namespace dst
{
	struct InputFiles
	{
		tdouble_type tradius;
		tmns_type tmns;
		tdouble_type tlength;
		dst::Parameter parameter;
		network::Dimension dimension;
	};
}

#endif
