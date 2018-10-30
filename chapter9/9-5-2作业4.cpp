#include <iostream>
#include <string>
using namespace std;

string addname(string sname,const string &hname,const string &lname)
{
    sname.insert(0,hname);
    sname.insert(sname.size(),lname);
    return sname;
}

//9.46
int main()
{
    string str = addname("Enzo","Mr. "," The First");
    cout<<str<<endl;



    return 0;
}
