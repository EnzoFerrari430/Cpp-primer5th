#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>


const char *judge(T a)
{
    return typeid(a).name();
}
/*
1.  'a':字符 L'a':宽字符 "a":字符串 L"a":宽 字符串
2.   10:int, 10u:unsigned int, 10L:long int, 10uL:unsigned long int, 012:8进制10, 0xC :16进制12

0开头是8进制
*/
int main()
{
    //std::cout<<judge('a')<<std::endl;


    //std::cout<<9<<std::endl;
    std::cout<<"Who goes with F\145rgus?\012"<<std::endl;
    std::cout<<3.14e1L<<std::endl;
    std::cout<<10.24f<<std::endl;
    std::cout<<3.14L<<std::endl;

    std::cout<<"2\x4d\n2\t\x4d\n";

    return 0;
}
