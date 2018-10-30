#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
定义和改变shared_ptr的其他方法
    shared_ptr<T> p(q)
    shared_ptr<T> p(u)
    shared_ptr<T> p(q,d)
    shared_ptr<T> p(p2,d)


    p.reset()
    p.reset(q)
    p.reset(q,d)

*/
int main()
{
    //如果不初始化一个智能指针，它就会被初始化成一个空指针
    shared_ptr<double> p1;  //shared_ptr可以指向一个double
    shared_ptr<int> p2(new int(42));  //p2指向一个值为42的int

    //接受指针参数的智能指针构造函数是explicit的。因此不能将一个内置指针隐式转化为智能指针，必须使用直接初始化形式。来初始化一个智能指针
    //shared_ptr<int> p1 = new int(1024);  不能用 = 的隐式转换
    shared_ptr<int> p2(new int(1024));  //直接初始化

    //默认情况下，一个用来初始化智能指针的普通指针必须指向动态内存，因为智能指针默认使用delete释放它所关联的对象。
    //我们可以将智能指针绑定到一个指向其他类型的资源的指针上，但是必须提供自己的操作代替delete


    return 0;
}
