#include <iostream>
#include <string>
using namespace std;


class Employee
{
public:
    Employee();
    Employee( string  );

public:
    int nEeID;
    string sEeName;
    static int num;
};

int Employee::num = 0;

Employee::Employee()
{
    sEeName = "Mr.x";
    nEeID = num;
    ++num;
}

Employee::Employee(string str)
{
    sEeName = str;
    nEeID = num;
    ++num;
}

int main()
{
    Employee a,b,c,d,e;
    cout<<e.nEeID<<endl;

    Employee f("pjd");
    cout<<f.sEeName<<" "<<f.nEeID<<endl;
    Employee g(f);
    cout<<g.sEeName<<" "<<g.nEeID<<endl;


    return 0;
}

//13.19  不需要，这个类的拷贝控制成员没有实际意义
