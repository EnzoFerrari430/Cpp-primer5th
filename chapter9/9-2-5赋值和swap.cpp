#include <iostream>
#include <vector>
#include <array>
using namespace std;
/*
    赋值运算符将其左边容器中的全部元素替换为右边容器中元素的拷贝(★注意是拷贝)
    赋值前，如果2个容器的大小不同，赋值后2个容器的大小都与右边容器的原大小相同


    由于右边运算符对象的大小可能与左边运算对象的大小不同，因此array类型不支持assign，也不允许用花括号包围的值列表进行赋值(疑问?)
    ★解答：关于 std::array 用花括号赋值这个特性其实在 C++ 11 标准中已经支持了(operator=)。
            但是那时候的 C++ 编译器无法支持，故作者想好心提示读者，怕读者失望。但却好心干了坏事，错估了编译器的长远发展。



    容器的赋值运算
    c1 = c2   c1,c2必须具有相同的类型
    c = {a,b,c...}  array不适用   等号右边的都是拷贝出来的副本

    swap(c1,c2)  交换c1,c2中的元素，c1c2必须具有相同的类型，swap通常比从c2向c1拷贝快的多
    c1.swap(c2)

    assign操作不适用于关联容器和array
    seq.assign(b,e)     将seq中的元素替换为迭代器b和e所表示的范围中的元素。迭代器b和e不能指向seq中的元素
    seq.assign(il)      将seq中的元素替换为初始化表il中的元素
    seq.assign(n,t)     将seq中的元素替换为n个值为t的元素

*/
int main()
{
    vector<int> a{1,2,3,4,5};
    cout<<a.size()<<endl;
    a = {6,6};
    cout<<a.size()<<endl;

    array<int,10> ai1 = {0,1,2,3,4,5,6,7,8,9};
    array<int,10> ai2 = {0};

    ai1 = {3,3,3,3,3,3,3,3,3,3};
    for(auto c: ai1)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    ai2 = {0};
    for(auto c: ai2)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    return 0;
}
