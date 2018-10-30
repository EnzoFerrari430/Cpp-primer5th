#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:
    HasPtr(const string &s = string(),int n = 0 ):ps(new string(s)),i(n){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(HasPtr rhs);
    ~HasPtr(){delete ps;}
public:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    cout<<"Reference Version"<<endl;
    auto newp = new string(*rhs.ps);
    delete ps;  //���ͷ�ԭ���ǿ��ڴ�,�м��м�,
    //������rhs��*this��ͬһ���������Ǿͽ������ͷŵ��ڴ��п������ݡ�����Ҫ�ȿ�������ʱ������ȥ
    ps = newp;  //���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
    cout<<"normal Version"<<endl;
    swap(*this,rhs);  //����汾���ÿ���rhs��thisָ��ָ����ǲ���ͬһ������
    return *this;
}

inline void swap(HasPtr& lhs,HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);  //����ָ��
    swap(lhs.i,rhs.i);  //����int��Ա
}


int main()
{
    HasPtr p1("hello world",1);
    HasPtr p2("www.google.com",2);

    cout<<p1.ps<<" "<<p2.ps<<endl;
    cout<<p1.i<<" "<<p2.i<<endl;
    cout<<*p1.ps<<" "<<*p2.ps<<endl;

    swap(p1,p2);

    cout<<p1.ps<<" "<<p2.ps<<endl;
    cout<<p1.i<<" "<<p2.i<<endl;
    cout<<*p1.ps<<" "<<*p2.ps<<endl;

    HasPtr p3;
    p3 = p1;

    return 0;
}
