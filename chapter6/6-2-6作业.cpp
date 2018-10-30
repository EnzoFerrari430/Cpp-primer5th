#include <iostream>
#include <initializer_list>
using namespace std;
int add(initializer_list<int> vi)
{
    int sum = 0;
    for( auto ib = vi.begin() ; ib != vi.end(); ++ib)
        sum += *ib;
    return sum;
}
int main()
{
    //如果要向initializer_list形参中传递一个值的序列，则必须把序列放在一对花括号里
    cout<<add({1,2,3,4,5,6});

    //6.28 elem  const std::string&
    //6.29 看情况，有些数据用传值的方式(即拷贝)比较廉价，有些数据用引用比较廉价
    return 0;
}
