#include <iostream>
#include <string>
using namespace std;

class PrintString
{
public:
    PrintString(istream &i = cin):is(i){}
    string operator()();



private:
    istream &is;

};

string PrintString::operator()()
{
    string s;
    is>>s;
    if(is)
    {
        return s;
    }
    else
    {
        return "";
    }
}
int main()
{
    PrintString ps;
    string s;
    s = ps();
    cout<<s<<endl;
    return 0;
}
