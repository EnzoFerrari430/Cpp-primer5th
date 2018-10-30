#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
using namespace std;

/*
标准库allocator类定义在头文件memory中，它帮助我们将内存分配和对象构造分离开来



    标准库allocator类及其算法
allocator<T> a          定义了一个名为a的allocator对象，它可以为类型为T的对象分配原始内存

a.allocate(n)           分配一段原始的，未构造的内存，保存n个类型为T的对象

a.deallocate(p,n)       释放从T*指针p中地址开始的内存，这块内存保存了n个类型为T的对象；
                        p必须是一个先前由allocate返回的指针，且n必须是p创建时所要求的大小。
                        在调用deallocate之前，用户必须对每个在这块内存中创建的对象调用destroy

a.construct(p,args)     p必须是一个类型为T*的指针，指向一块原始内存：arg被传递给类型为T的构造函数，用来在p指向的内存中构造一个对象

a.destroy(p)            p为T*类型的指针，此算法对p指向的对象执行析构函数


*/
int main()
{
    char *cp = "helloworld";
    allocator<string> alloc;  //可以分配string的allocator对象
    auto const p = alloc.allocate(10);  //分配10个未初始化的string,返回分配的内存的首地址
    auto q = p;
    alloc.construct(q++,10,'c');  //q++之后  q就指向了最后构造元素之后的位置
    cout<<typeid(p).name()<<endl;
    cout<<q - p<<endl;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<endl;
    //cout<<*q<<endl;
    cout<<cp<<endl;


    //当我们用完对象后，必须对每个构造的元素调用destroy来销毁它们。函数destroy接受一个指针，对指向的对象执行析构函数
    while(q != p)
    {
        alloc.destroy(--q);
    }

    //释放这段内存
    alloc.deallocate(p,10);


    return 0;
}
