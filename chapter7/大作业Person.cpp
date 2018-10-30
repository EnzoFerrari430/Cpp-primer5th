#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend istream &read(istream &,Person &);
    friend ostream &print(ostream &,const Person &);
private:
    //数据成员，和实现部分的函数(类似于一些算法之类)跟在private之后
    string Myname;
    string Myad;

public:
    //构造函数和成员函数作为接口跟在public之后
    string rname() const{return Myname;}  //使用const，防止写入操作
    string rad() const{return Myad;}

    Person(): Myname("Enzo"),Myad("china"){}  //构造函数
    Person(string s1,string s2):Myname(s1),Myad(s2){}
    Person(string s1):Myname(s1),Myad("chine"){}

    bool isSameone(const Person &r)
    {
        return Myname == r.Myname;
    }
};
istream &read(istream &,Person &);
ostream &print(ostream &,const Person &);

istream &read(istream &is,Person &p)
{
    is>>p.Myname>>p.Myad;
    return is;
}

ostream &print(ostream &os,const Person &p)
{
    os<<p.Myname<<" "<<p.Myad;
    return os;
}

int main()
{
    Person p1;
    read(cin,p1);
    cout<<p1.isSameone(string("enzo"));  //隐式转换

    return 0;
}
