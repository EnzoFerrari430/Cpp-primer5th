#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>


const char *judge(T a)
{
    return typeid(a).name();
}
/*
1.  'a':�ַ� L'a':���ַ� "a":�ַ��� L"a":�� �ַ���
2.   10:int, 10u:unsigned int, 10L:long int, 10uL:unsigned long int, 012:8����10, 0xC :16����12

0��ͷ��8����
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
