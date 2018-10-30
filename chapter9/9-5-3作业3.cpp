#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream is("E:\\CC++\\C++ primer\\chapter9\\9.49words.txt");
    string old;
    string asc("bdfhijklqt"),des("fgjpqy");
    while(is.eof() == 0)  //ifstream.eof() Èôµ½´ïÄ©Î² ·µ»Øtrue
    {
        string str;
        is>>str;
        if(str.find_first_of(asc) != string::npos || str.find_first_of(des) != string::npos)
            continue;
        else
        {
            if(str.size() > old.size())
            {
                old = str;
            }
        }
    }
    cout<<old<<endl;
    return 0;
}
