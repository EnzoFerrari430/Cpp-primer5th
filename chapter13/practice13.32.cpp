#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr& lhs,HasPtr& rhs);
public:
    //���캯����ʼ������Ϊ1  //sĬ��Ϊ��
    HasPtr(const string& s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    //�������캯��
    HasPtr(const HasPtr &rhs);
    //������ֵ�����
    HasPtr& operator=(const HasPtr &rhs);
    HasPtr& operator=(const string &rhs);
    ~HasPtr();
public:
    string *ps;
    int i;
    size_t *use;  //���ü���,����ʹ��ָ�룬Ϊ��ͳһ�����������
};

HasPtr::HasPtr(const HasPtr &rhs)
{
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    ++(*use);  //���ü�����1
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    --(*use);
    if( (*use) == 0 )
    {
        delete ps;
        ps = nullptr;
    }
    ps = rhs.ps;
    ++*rhs.use;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

HasPtr::~HasPtr()
{
    --(*use);
    if( (*use) == 0 )
    {
        delete ps;
        delete use;  //�ͷ����ü���
        ps = nullptr;
    }
}

//13.32  �Ӳ��������ʹ��Ĭ�ϰ汾��swap���ǽ���ָ��ĵ�ַ����i������
void swap(HasPtr& lhs,HasPtr& rhs)
{
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
    swap(lhs.use,rhs.use);
}

int main()
{
    HasPtr h1("hi mom!");
    HasPtr h2 = h1;

    h1 = "hi dad!";

    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;

    HasPtr h3("hi h3");
    HasPtr h4("hi h4");
    cout<<"ps address: "<<h3.ps<<" "<<h4.ps<<endl;
    cout<<"ps content: "<<*h3.ps<<" "<<*h4.ps<<endl;
    cout<<"i content: "<<h3.i<<" "<<h4.i<<endl;
    cout<<"use address: "<<h3.use<<" "<<h4.use<<endl;
    cout<<"use content: "<<*h3.use<<" "<<*h4.use<<endl;
    swap(h3,h4);
    cout<<"ps address: "<<h3.ps<<" "<<h4.ps<<endl;
    cout<<"ps content: "<<*h3.ps<<" "<<*h4.ps<<endl;
    cout<<"i content: "<<h3.i<<" "<<h4.i<<endl;
    cout<<"use address: "<<h3.use<<" "<<h4.use<<endl;
    cout<<"use content: "<<*h3.use<<" "<<*h4.use<<endl;

    return 0;
}
