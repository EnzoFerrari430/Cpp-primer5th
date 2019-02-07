/*
����ʵ����صĲ��Һ��������β�

1.�����string�Ļ�����Ϊstring�������ͣ������������ڳ����������в���ƥ���swap�⣬
��δ����string�����������ռ����Ƿ����ض��汾��swap����,��string���ԣ��ҵ��ľ���std::swap

2.�����int��ֻ���ڳ����������в��ң��������using����������������std::swap

*/

#include <iostream>
#include <string>
#include <algorithm>

class bottle
{
public:
    bottle():a(10),s("hello"){}
    bottle(int n ,std::string str):a(5),s(str){}
public:
    int a;
    std::string s;
};

template <typename T>
void swap(T& v1,T& v2)
{
    using std::swap;
    swap(v1.a,v2.a);
}

int main()
{
    bottle a;
    bottle b(5,"world");
    std::cout<<a.a<<" "<<a.s<<std::endl;
    std::cout<<b.a<<" "<<b.s<<std::endl;
    swap(a,b);
    std::cout<<a.a<<" "<<a.s<<std::endl;
    std::cout<<b.a<<" "<<b.s<<std::endl;
    swap(a,b);
    std::cout<<a.a<<" "<<a.s<<std::endl;
    std::cout<<b.a<<" "<<b.s<<std::endl;

    int n1 = 3,n2 = 8;
    using std::swap;
    swap(n1,n2);
    std::cout<<n1<<" "<<n2<<std::endl;

    return 0;
}
