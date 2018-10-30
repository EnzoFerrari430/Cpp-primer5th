#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend istream &read(istream &,Person &);
    friend ostream &print(ostream &,const Person &);
private:
    //���ݳ�Ա����ʵ�ֲ��ֵĺ���(������һЩ�㷨֮��)����private֮��
    string Myname;
    string Myad;

public:
    //���캯���ͳ�Ա������Ϊ�ӿڸ���public֮��
    string rname() const{return Myname;}  //ʹ��const����ֹд�����
    string rad() const{return Myad;}

    Person(): Myname("Enzo"),Myad("china"){}  //���캯��
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
    cout<<p1.isSameone(string("enzo"));  //��ʽת��

    return 0;
}
