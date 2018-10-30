#include <iostream>
#include <string>
using namespace std;

/*
�����Ϊ��һ��ֵ����ζ����Ӧ�����Լ���״̬�������ǿ���һ��ֵ�Ķ���ʱ��������ԭ��������ȫ�����ġ��ı丱�������ԭ�������κ�Ӱ�죬��֮��Ȼ

��Ϊ��ָ���������״̬�������ǿ���һ�������Ķ���ʱ��������ԭ����ʹ����ͬ�ĵײ����ݡ��ı丱��Ҳ��ı�ԭ���󣬷�֮��Ȼ
*/


class HasPtr
{
public:
    HasPtr(const std::string &s = std::string() ):ps(new std::string(s)),i(0){}

    //�ϳɵĿ������캯����ǳ����
    //��Ҫ�Լ���д�������캯��
    HasPtr(const HasPtr&);

    HasPtr& operator=(const std::string &s);

    ~HasPtr(){ delete ps; }

public:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& rhs)
{
    i = rhs.i;
    ps = new string(*rhs.ps);  //�Լ�����һ���ڴ��ַ����rhs��psָ��ָ������ݿ���������ڴ���
}

HasPtr& HasPtr::operator=(const std::string &s)
{


    return *this;
}

//�����ǳ����( �ϳɵĿ������캯�� )�����������
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
