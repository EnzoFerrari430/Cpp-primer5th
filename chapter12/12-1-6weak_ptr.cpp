#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*
weak_ptr是一种不控制所指向对象生存期的智能指针，它指向一个由shared_ptr管理的对象。
将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数.
一旦最后一个指向对象的shared_ptr被销毁，对象就会被释放。即使有weak_ptr指向对象

weak_ptr<T> w
weak_ptr<T> w(sp)

w = p;

w.reset();

w.use_count();

w.expired()

w.lock()

*/
int main()
{
    //创建weak_ptr要用shared_ptr来初始化它
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);  //wp弱共享p  p的引用计数未改变



    return 0;
}
