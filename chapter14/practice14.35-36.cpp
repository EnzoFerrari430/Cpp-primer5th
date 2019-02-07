#include <iostream>
#include <string>
#include <vector>
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
    getline(is,s);
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

    cout<<"practice14.36"<<endl;
    vector<string> vs;
    for(std::string tmp;  ! ((tmp = ps()).empty()) ; )
    {
        vs.push_back(tmp);
    }

    for( const auto &str:vs )
    {
        cout<<str<<endl;
    }




    return 0;
}
