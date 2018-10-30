#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    //���캯����ʼ������Ϊ1  //sĬ��Ϊ��
    HasPtr(const string& s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    //�������캯��
    HasPtr(const HasPtr &rhs);
    //������ֵ�����
    HasPtr& operator=(const HasPtr &rhs);
    HasPtr& operator=(const string &rhs);
    ~HasPtr();
private:
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

int main()
{
    HasPtr h1("hi mom!");
    HasPtr h2 = h1;

    h1 = "hi dad!";

    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;

    return 0;
}
