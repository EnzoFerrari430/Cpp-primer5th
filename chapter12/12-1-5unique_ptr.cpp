#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

/*
顾名思义 unique_ptr表示在某个时刻只能有一个unique_ptr指向一个给定的对象。当unique_ptr被销毁时，它所指的对象也被销毁。
与shared_ptr不同，没有类似的make_shared的标准库函数返回一个unique_ptr。
因为一个unique_ptr拥有它指向的对象，因此unique_ptr不支持普通的拷贝或赋值操作


u.release()     u放弃对指针的控制权，返回指针，并将u置空

u.reset()       释放u指向的对象

u.reset(p)      如果提供了内置指针q，令u指向这个对象；否则将u置空

u.reset(nullptr)


*/
int main()
{
    unique_ptr<string> p1(new string("Stegosaurus"));
    //unique_ptr<string> p2(p1);  //不支持拷贝
    //unique_ptr<string> p3;
    //p3 = p2;  //不支持赋值

    //虽然不能拷贝或赋值unique_ptr，但可以通过调用release或reset将指针的所有权从一个（非const）unique_ptr转移给另一个unique_ptr
    unique_ptr<string> p2(p1.release());  //release将p1置空
    unique_ptr<string> p3(new string("Trex"));
    p2.reset(p3.release());  //reset释放了原来的内存

    //p2.release();     错误，p2不会释放内存，而且我们丢失了指针
    auto p = p2.release();  //正确，但是要记得delete(p)



    return 0;
}
