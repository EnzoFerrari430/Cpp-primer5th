#include <iostream>
#include <array>
using namespace std;
/*
定义一个array时，除了指定元素的类型，还要指定容器的大小



如果对array进行列表初始化，初始值的数目必须等于或小于array的大小
如果初始值数目小于array的大小，则它们被用来初始化array中考前的元素，剩下的元素被默认初始化


★虽然我们不能对内置数组类型进行拷贝或对对象进行赋值，但是array没有这个限制

*/
int main()
{
    array<int,10> ai{1,2,3,4,5,6};  //int型数组初始化不完全，剩余的会初始化成0
    for(auto c:ai)
    {
        cout<<c<<' ';
    }

    return 0;
}
