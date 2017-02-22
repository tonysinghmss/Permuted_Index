#include <iostream> //cout, cin
#include <string>
#include <vector>
#include <cctype>//for isspace
#include <algorithm>//for sort, max_element, min_element
#include <iomanip>//for setw
#include <sstream>//for stringstream
#include <fstream>
#include "Line_info.h"
#include "Ptx.h"
using namespace std;

bool str_compare(const string& x, const string& y){
    return x.size() < y.size();
}

bool isLine(const string& str){
    bool flag = false;
    string::size_type i =0;
    while(i!=str.size()){
        if(isspace(str[i])){
            flag = true;
            break;
        }
        ++i;
    }
    return flag;
}
void rot8Str(const string& aStr, vector<Line_info>& rot8vec){
    typedef string::size_type string_size;
    string cpStr;
    string_size pos;
    // invariant: We have rotated the string till it matches the original string
    while(cpStr != aStr){
        if(cpStr.empty()){
            cpStr = aStr;
            pos = cpStr.size();
        }
        rot8vec.push_back(make_lineinfo(cpStr, pos));
        string_size i = 0;
        // invariant: Characters in range [original i, current i) are not spaces
        while(i != cpStr.size() && !isspace(cpStr[i]))
            ++i;
        string_size j = i;
        cpStr = cpStr.substr(j+1,cpStr.size())+' '+cpStr.substr(0,j);
        pos = pos - j-1;
    }
}


string::size_type get_left_max(const vector<Line_info>& vec,const string::size_type strsize){
    vector<Line_info>::const_iterator min_iter= min_element(vec.begin(), vec.end(), len_compare);
    string::size_type pos_min_val = (*min_iter).pos;
    return strsize - pos_min_val - 1;
}

string unrot8Str(const Line_info& li, const string::size_type left_max){
    string line = li.line;
    string::size_type pos = li.pos;
    string rot8,left_string, right_string;
    stringstream ss;
    if(pos != line.size()){
        left_string = line.substr(pos+1, line.size());
        right_string = line.substr(0,pos);
        ss << setw(left_max)<<left_string;
        ss << string(4,' ') << right_string;
    }
    else{
        ss << setw(left_max) << ' ';
        ss << string(4,' ') << line;
    }
    rot8 = ss.str();
    return rot8;
}

int main(int argc, char* argv[]){
    //Check if the argument count is less than 2.
    //If not show an error.
    if(argc < 2){
        cerr << "Usage: " << argv[0] << " Name_Of_File" << endl;
        return 1;
    }
    vector<string> strList;
    string line;
    ifstream infile(argv[1]);
    while(getline(infile,line)){
        strList.push_back(line);
    }
    vector<string>::const_iterator max_iter = max_element(strList.begin(), strList.end(), str_compare);
    string::size_type max_len = (*max_iter).size();
    vector<Line_info> rot8vec;
    // fetch all the rotated strings in vectors
    vector<string>::const_iterator iter = strList.begin();
    // invariant: We have created rotation vectors for each line in list.
    while(iter != strList.end()){
        if(isLine(*iter)){
            rot8Str(*iter, rot8vec);
        }
        else{
           rot8vec.push_back(make_lineinfo(*iter, (*iter).size()));
        }
        ++iter;
    }
    //alphabetic sort of each line present in the vector
    sort(rot8vec.begin(), rot8vec.end(), line_info_compare);
    //get the maximum number of characters in left side
    string::size_type left_max = get_left_max(rot8vec, max_len);
    for(vector<Line_info>::size_type i=0; i!=rot8vec.size(); ++i){
        //cout << rot8vec[i].line << rot8vec[i].pos << endl;
        string unrot8 = unrot8Str(rot8vec[i],left_max);
        cout << unrot8 << endl;
    }
    return 0;
}

