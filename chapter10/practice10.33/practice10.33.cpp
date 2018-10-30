#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string ifile("E:\\CC++\\C++ primer\\chapter10\\practice10.33\\ifile.txt");
    string ofile1("E:\\CC++\\C++ primer\\chapter10\\practice10.33\\ofile1.txt");
    string ofile2("E:\\CC++\\C++ primer\\chapter10\\practice10.33\\ofile2.txt");
    ifstream read(ifile);
    ofstream wte1(ofile1);
    ofstream wte2(ofile2);
    istream_iterator<int> in(read),eof;
    ostream_iterator<int> out1(wte1," ");
    ostream_iterator<int> out2(wte2," ");
    vector<int> vec;
    while(in != eof)
    {
        vec.push_back(*in++);
    }
    for(auto it = vec.begin() ; it != vec.end() ;++it)
    {
        if( *it%2 == 0)
        {
            out1 = *it;
        }
        else
        {
            out2 = *it;
        }
    }

    return 0;
}
