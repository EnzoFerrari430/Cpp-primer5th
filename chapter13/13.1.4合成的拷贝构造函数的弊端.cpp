#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    //ǳ����
    HasPtr(const std::string &s = std::string() ):ps(new std::string(s)),i(0){}

    HasPtr& operator=(const std::string &s);

    ~HasPtr(){ delete ps; }

public:
    std::string *ps;
    int i;
};

HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;  //����������HasPtr
    //����ret

    return ret;  //ret��hp������
    //ret��hp��ps��Աָ��ָ��ͬһ���ڴ��ַ��f����ʱ��ret��hp�����٣�psָ��ᱻ����2�Σ�

    //�˴���ᱻdelete2�Σ���Ҫ����ʲô��δ����ģ��������:psָ����ڴ�������ڵ�һ������ʱ���ͷţ��ڶ������پ���һ��δ�������Ϊ��
}

int main()
{
    HasPtr p("some values");
    f(p);  //  !!�ϳɵĿ������캯����ǳ����������
    HasPtr q(p);  //����p��q��ָ����Ч���ڴ�

    cout<<*q.ps<<endl;

    return 0;
}
