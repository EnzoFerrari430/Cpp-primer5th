#include <iostream>
#include <string>
using namespace std;

void showsth(const string &s1,const string &s2)
{
    string::size_type pos = 0;
    while( (pos = s1.find_first_of(s2,pos)) != string::npos )
    {
        cout<<s1[pos]<<' ';
        ++pos;
    }
    cout<<endl;
}

void show_not_sth(const string &s1,const string &s2)
{
    string::size_type pos = 0;
    while( (pos = s1.find_first_not_of(s2,pos)) != string::npos )
    {
        cout<<s1[pos]<<' ';
        ++pos;
    }
    cout<<endl;
}

int main()
{
    string str("ab2c3d7R4E6");
    string numbers("0123456789");
    string letters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    showsth(str,numbers);
    showsth(str,letters);

    show_not_sth(str,numbers);
    show_not_sth(str,letters);



    return 0;
}
