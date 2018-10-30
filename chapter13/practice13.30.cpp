#include <iostream>
#include <string>

using namespace std;

//13.29��Ϊswap���������swap�����Ĳ�������HasPtr&,HasPtr&��
//����ʹ�����Լ������swap�汾��ϵͳ���Լ�������ƥ���std��swap�汾�����Բ��ᷢ���ݹ�


//�඼�����Լ����ڴ�ռ�
class HasPtr
{
    friend void swap(HasPtr& lhs,HasPtr& rhs);
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string);
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

HasPtr& HasPtr::operator=(const string rhs)
{
    auto newp = new string(rhs);
    delete ps;  //���ͷ�ԭ���ǿ��ڴ�,�м��м�,
    //������rhs��*this��ͬһ���������Ǿͽ������ͷŵ��ڴ��п������ݡ�����Ҫ�ȿ�������ʱ������ȥ
    ps = newp;  //���Ҳ�������󿽱����ݵ�������
    return *this;
}

void swap(HasPtr& lhs,HasPtr& rhs)
{
    cout<<"swap now"<<endl;
//    int temp;
//    string s;
//    s = *lhs.ps;
//    *lhs.ps = *rhs.ps;
//    *rhs.ps = s;
//    temp = lhs.i;
//    lhs.i = rhs.i;
//    rhs.i = lhs.i;
    //�ı�ָ��ָ��
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

int main()
{
    HasPtr h1("hi mom!");
    HasPtr h2(h1);
    HasPtr h3 = h1;


    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;
    cout<<"h3: "<<*h3.ps<<endl;
    cout<<"h1: "<<h1.ps<<endl;
    cout<<"h2: "<<h2.ps<<endl;
    cout<<"h3: "<<h3.ps<<endl;

    h2 = "hi dad";
    h3 = "hi son";
    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;
    cout<<"h3: "<<*h3.ps<<endl;
    cout<<"h1: "<<h1.ps<<endl;
    cout<<"h2: "<<h2.ps<<endl;
    cout<<"h3: "<<h3.ps<<endl;

    swap(h2,h3);

    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;
    cout<<"h3: "<<*h3.ps<<endl;
    cout<<"h1: "<<h1.ps<<endl;
    cout<<"h2: "<<h2.ps<<endl;
    cout<<"h3: "<<h3.ps<<endl;


    return 0;
}
