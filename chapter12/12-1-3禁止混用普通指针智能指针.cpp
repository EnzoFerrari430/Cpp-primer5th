#include <iostream>
#include <vector>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr)
{
    //使用ptr
}   //ptr离开作用域，被销毁
//process的参数是传值的方式，因此实参会被拷贝到ptr中。拷贝一个shared_ptr会递增其引用计数，因此在process中，引用计数至少为2
//当process结束时，ptr的引用计数会递减，但不会变为0。因此当局部ptr被销毁时，ptr指向的内存不会被释放



//虽然不能传递给process一个内置指针，但可以传递给它一个临时的shared_ptr，这个shared_ptr用内置指针显式构造，但很可能出错

int main()
{
    shared_ptr<int> p(new int(42));  //引用计数为1
    process(p);
    int i = *p;
    cout<<i<<endl;

    int *x(new int(1024));
    //process(x);  不能将int*转换成shared_ptr<int>
    process(shared_ptr<int>(x));  //合法，但是内存会被释放  在这句中才被显式构造，引用计数为1，process结束时引用计数递减。内存被释放
    int j = *x;
    cout<<j<<endl;

    //不要用get初始化另一个智能指针或为智能指针赋值
    //get函数，它返回一个内置指针，指向智能指针管理的对象


    return 0;
}
