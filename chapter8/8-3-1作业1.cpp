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
    istringstream ss(str);  //����¼�󶨵��ն������
    read(ss);

    return 0;
}
