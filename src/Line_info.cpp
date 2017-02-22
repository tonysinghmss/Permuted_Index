#include "Line_info.h"
#include <string>
Line_info make_lineinfo(std::string line,std::string::size_type pos){
        Line_info li = {line, pos};
        return li;
}
bool line_info_compare(const Line_info& x, const Line_info& y){
    return x.line < y.line;
}
bool len_compare(const Line_info& x, const Line_info& y){
    return x.pos < y.pos;
}
