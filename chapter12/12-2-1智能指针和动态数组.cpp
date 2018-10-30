#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
    标准库提供了一个可以管理new分配的数组的unique_ptr版本
    为了使用unique_ptr管理动态数组，我们必须在对象类型后面跟一对空括号

    注意！！！ 当一个unique_ptr指向一个数组时，我们不能使用点和箭头成员运算符
    因为unique_ptr指向的是一个数组而不是单个对象，因此这些运算符是无意义的。
    另外，当一个unique_ptr指向一个数组时，可以使用下标运算符来访问数组中的元素

    shared_ptr 不直接支持管理动态数组。如果希望使用shared_ptr管理一个动态数组，必须提供自己定义的删除器
*/

int main()
{
    unique_ptr<int[]> up(new int[10]);
    for(size_t i = 0; i != 10; ++i)
    {
        up[i] = i;
    }
    for(size_t i = 0; i != 10; ++i)
    {
        cout<<up[i]<<" ";
    }
    cout<<endl;

    up.release();  //自动使用delete[] 销毁其指针


    //为了使用shared_ptr，必须提供一个删除器
    shared_ptr<int> sp(new int[10],[](int *p)
    {
        delete[] p;
    });
    for(size_t i = 0; i != 10; ++i)
    {
        //shared_ptr未定义下标运算符
        //sp[i] = i;
        //使用get获取一个内置指针
        *(sp.get() + i) = i;
    }
    for(size_t i = 0; i != 10; ++i)
    {
        cout<<*(sp.get()+i)<<" ";
    }
    cout<<endl;
    sp.reset();


    return 0;
}
