#include <iostream>
#include <typeinfo>
#include <string>
#include <limits>
using namespace std;

template<class T>
string judge(T a)
{
    return typeid(a).name();
}



int main()
{
    bool b = 42;
    std::cout<<b<<std::endl;
    std::cout<<judge(b)<<std::endl;
    int i = b;
    std::cout<<i<<std::endl;
    std::cout<<judge(i)<<std::endl;
    i = 3.14;
    double pi = i;
    std::cout<<pi<<std::endl;
    std::cout<<judge(pi)<<std::endl;
    unsigned char c = -1;
    std::cout<<c<<std::endl;
    std::cout<<judge(c)<<std::endl;

    std::cout<<"max (int): "<<numeric_limits<int>::max()<<std::endl;
    return 0;
}
