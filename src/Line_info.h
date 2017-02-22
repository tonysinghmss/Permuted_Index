#ifndef GUARD_Line_info
#define GUARD_Line_info
#include <string>
struct Line_info{
    std::string line;
    std::string::size_type pos;
};

Line_info make_lineinfo(std::string ,std::string::size_type );
bool line_info_compare(const Line_info& , const Line_info& );
bool len_compare(const Line_info& , const Line_info& );
#endif
