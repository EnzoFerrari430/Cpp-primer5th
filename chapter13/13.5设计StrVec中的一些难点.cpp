#include <iostream>
#include <string>
#include <typeinfo>
#include <memory>
using namespace std;


int main()
{
    allocator<string> alloc;

    auto data = alloc.allocate(5);  //返回原始内存空间的首地址
    auto q = data;
    alloc.construct(q++,5,'a');
    cout<<*data<<endl;
    cout<<*q<<endl;
    cout<<q - data<<endl;

    cout<<typeid(data).name()<<endl;

    pair<string*,string*> a()



    return 0;
}




