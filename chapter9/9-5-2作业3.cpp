#include <iostream>
#include <string>
using namespace std;
string addname(string sname,const string &hname,const string &lname)
{
    auto beg = sname.begin();
    sname.insert(beg,hname.begin(),hname.end());
    sname.append(lname);
    return sname;
}


//9.45
int main()
{
    string str = addname("Enzo","Mr. "," The First");
    cout<<str<<endl;


    return 0;
}
