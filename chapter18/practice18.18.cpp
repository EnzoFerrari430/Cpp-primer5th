/*
考察实参相关的查找和类类型形参

1.如果是string的话，因为string是类类型，编译器除了在常规作用域中查找匹配的swap外，
还未查找string所属的命名空间中是否有特定版本的swap函数,对string而言，找到的就是std::swap

2.如果是int，只会在常规作用域中查找，最后由于using声明的作用最后调用std::swap

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
