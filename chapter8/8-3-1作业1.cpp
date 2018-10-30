#include <iostream>
#include <string>
#include <sstream>
using namespace std;

istream &read(istream &is)
{
    string str1;
    while(!is.eof() && is>>str1)
    {
        cout<<str1<<endl;
    }

    is.clear();
    is.sync();
    return is;
}

int main()
{
    string str;
    cin>>str;
    istringstream ss(str);  //将记录绑定到刚读入的行
    read(ss);

    return 0;
}
