#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
    string ifile("E:\\CC++\\C++ primer\\chapter10\\words.txt");
    ifstream read(ifile);
    istream_iterator<string> in(read),eof;
    vector<string> vec;
    while(in != eof)
    {
        vec.push_back( *in++ );
    }


    //�������������ʹ��copy�����
    ostream_iterator<string> out(cout,"\n");
    copy(vec.begin(),vec.end(),out);
    cout<<endl;
    return 0;
}
