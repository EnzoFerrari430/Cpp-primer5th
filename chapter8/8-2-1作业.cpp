#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> sval;
    ifstream in("E:\\Enzo.txt");
    while(in.eof() == 0)
    {
        string str;
        getline(in,str);
        sval.push_back(str);
    }

    for(auto c:sval)
    {
        cout<<c<<endl;
    }



    return 0;
}
