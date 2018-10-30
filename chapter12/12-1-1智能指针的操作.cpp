#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
shared_ptr和unique_ptr都支持的操作
    shared_ptr<T> sp    空智能指针，指向类型是T的对象
    unique_ptr<T> up

    p                   将p用作一个判断条件，若p指向一个对象，则为true
    *p                  解引用p，获得它指向的对象
    p->mem              等价于(*p).mem
    p.get()             返回p中保存的指针，★小心使用，若智能指针释放了其对象，返回的指针所指向的对象也就消失了

    swap(p,q)           交换p和q中的指针
    p.swap(q)

shared_ptr独有的操作
    make_shared<T>(args)    返回一个shared_ptr，指向一个动态分配的类型为T的对象。使用args初始化对象

    shared_ptr<T>p(q)       p是shared_ptr q的拷贝；此操作会递增q中的计数器。q中指针必须能转换为T*

    p = q                   p和q都是shared_ptr，所保存的指针必须能相互转换。此操作会递减p的引用计数，递增q的引用计数；
                            若p的引用计数变为0，则将其管理的原内存释放
    p.unique()              若p.use_count() 为1返回true，否则返回false

    p.use_count()           返回与p共享对象的智能指针的数量；可能很慢，主要用于调试

*/
int main()
{
    //make_shared函数,定义方式与模板类相同
    //make_shared用其参数来构造给定类型的对象,如果不传递任何参数，对象就进行值初始化

    //指向一个值为42的int的shared_ptr
    shared_ptr<int> p3 = make_shared<int>(42);
    cout<<p3<<endl;
    cout<<*p3<<endl;

    //指向一个值为"9999999999"的string
    shared_ptr<string> p4 = make_shared<string>(10,'9');
    cout<<p4<<endl;
    cout<<*p4<<endl;

    //指向一个值初始化的int，即值是0
    shared_ptr<int> p5 = make_shared<int>();
    cout<<p5<<endl;
    cout<<*p5<<endl;

    //auto来定义一个对象,p6指向一个动态分配的空vector<string>
    auto p6 = make_shared<vector<string>>();


    return 0;
}
