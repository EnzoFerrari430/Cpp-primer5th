#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
/*
    当进行拷贝或赋值操作时，每个shared_ptr都会记录有多少个其他shared_ptr指向相同对象

    每个shared_ptr都有一个关联的计数器，通常称其为引用计数。无论何时当我们拷贝一个shared_ptr，计数器都会递增。
    例如
        1.当用一个shared_ptr初始化另一个shared_ptr
        2.将它作为参数传递给一个函数
        3.作为函数的返回值
    计数器递减
    例如
        1.给shared_ptr赋予一个新值
        2.shared_ptr被销毁（局部shared_ptr离开其作用域）

    一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理的对象
*/
int main()
{
    auto q = make_shared<int>(222);
    auto r = make_shared<int>(42);
    r = q;  //给r赋值，令它指向另一个地址
            //递增q指向的对象的引用计数
            //递减r原来指向的对象的引用计数
            //r原来指向的对象已没有引用者,会自动释放

    vector<string> v1;
    {
        vector<string> v2 = {"a","an","the"};
        v1 = v2;
    }
    for(auto c : v1)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
