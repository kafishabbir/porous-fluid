#ifndef DST_TXTINCONGEN_H
#define DST_TXTINCONGEN_H

#include "algo/utility.h"
#include <set>
#include <vector>
#include <iostream>

namespace dst
{
	namespace decls_incongen_nps
	{
		namespace possible_nps
		{
			namespace cats_nps
			{
				const std::string nrows = "nrows";
				const std::string ncols = "ncols";
				const std::string tradius = "tradius";
				const std::string tlength = "tlength";
				const std::string tmns = "tmns";
			}

			namespace vals_nps
			{
				std::string constant_keyword = "const";
				namespace radius_nps
				{
					const std::string imbibition = "imbibiton";
					const std::string constant = constant_keyword;
					const std::string function = "function";
				}

				namespace length_nps
				{
					const std::string constant = constant_keyword;
					const std::string inverseradius = "inverseradius";
				}

				namespace mns_nps
				{
					const std::string saturate_oil = "saturate_oil";
					const std::string saturate_water = "saturate_water";
					const std::string imbibition = "imbibition";
				}
			}
		}

		struct catAndvals
		{
			std::string cat;
			std::vector<std::string> vals;
		};

		const std::vector<catAndvals> cat_and_vals_vec
		{
			{possible_nps::cats_nps::nrows, {"40"}},

			{possible_nps::cats_nps::ncols, {"40"}},

			{
				possible_nps::cats_nps::tradius,
				{
					possible_nps::vals_nps::radius_nps::constant + "=1.13",
					possible_nps::vals_nps::radius_nps::imbibition,
					possible_nps::vals_nps::radius_nps::function
				}
			},
			{
				possible_nps::cats_nps::tlength,
				{
					possible_nps::vals_nps::length_nps::constant + "2.12",
					possible_nps::vals_nps::length_nps::inverseradius
				}
			},
			{
				possible_nps::cats_nps::tmns,
				{
					possible_nps::vals_nps::mns_nps::imbibition,
					possible_nps::vals_nps::mns_nps::saturate_water,
					possible_nps::vals_nps::mns_nps::saturate_oil
				}
			}
		};
	}

	class TxtIncongen
	{
		static bool is_const(const std::string& s);
		static std::pair<std::pair<std::string, double>, bool>
			match_with_val(
				const std::string& val,
				const std::vector<std::string>& vals_vec);
		static std::vector<std::string> find_vals_of_corresponding_cat(const std::string& s);
		
	public:
		int nrows;
		int ncols;
		std::pair<std::string, double> tradius;
		std::pair<std::string, double> tlength;
		std::string tmns;
		bool set(const std::string& buffer_line);
		static std::set<std::string> set_of_cats();

	};

}

#endif
