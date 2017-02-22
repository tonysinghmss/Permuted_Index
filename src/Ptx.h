#ifndef GUARD_Ptx
#define GUARD_Ptx
#include <string>
#include <vector>
#include "Line_info.h"
bool str_compare(const std::string& , const std::string& );
bool isLine(const std::string& );
void rot8Str(const std::string& , std::vector<Line_info>& );
std::string::size_type get_left_max(const std::vector <Line_info>& ,const std::string::size_type );
std::string unrot8Str(const Line_info& , const std::string::size_type );
#endif
