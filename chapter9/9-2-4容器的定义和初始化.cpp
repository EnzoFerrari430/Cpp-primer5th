#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
    array的原型类似这样
    第一个模板参数T指明了array中存放的数据类型；

    第二个非类型模板参数指明了array的固定大小。
    namespace std
    {
    template <typename T, size_t N>
    class array;
    }


    构造函数	说明
    arrary<T, N> c	默认构造函数，N个元素全部使用“默认初始化行为”来构造。
    arrary<T, N> c(other)	拷贝构造函数，拷贝所有other的元素到c来构造。
    arrary<T, N> c = other	拷贝构造函数，拷贝所有other的元素到c来构造。
    arrary<T, N> c(rValue)	移动构造，使用右值rValue里的元素来初始化c。
    arrary<T, N> c = rValue	移动构造，使用右值rValue里的元素来初始化c。
    arrary<T, N> c = initlist	使用初始化列表初始化元素
    */
    array<int,5> ar{1,2,3,4,5};
    array<int,5> ai(ar);

    for(auto c:ai)
    {
        cout<<c<<' ';
    }

    return 0;
}
