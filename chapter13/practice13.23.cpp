#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}  //һ������ʹ��Ĭ�ϵĿ������캯��

    HasPtr& operator=(const HasPtr&);
    ~HasPtr(){delete ps;}
public:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;  //���ͷ�ԭ���ǿ��ڴ�,�м��м�,
    //������rhs��*this��ͬһ���������Ǿͽ������ͷŵ��ڴ��п������ݡ�����Ҫ�ȿ�������ʱ������ȥ
    ps = newp;  //���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    return *this;
}

HasPtr f(HasPtr pos)
{
    auto p = pos;

    return p;
}

int main()
{
    HasPtr a("hello world");
    cout<<*a.ps<<endl;
    HasPtr b = f(a);
    cout<<*a.ps<<endl;
    cout<<*b.ps<<endl;
    return 0;
}

//13.24���δ����������������������ڴ��޷����ͷš�������ڴ�й©��
//���δ���忽�����캯�����򿽱���ǳ������һ�����޸���ps����һ���������Ҳ��ı䡣���һ�����ͷ����ڴ棬����һ�����ps���Ϊ����ָ��
