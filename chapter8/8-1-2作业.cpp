#include <iostream>
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
    read(cin);

    return 0;
}
