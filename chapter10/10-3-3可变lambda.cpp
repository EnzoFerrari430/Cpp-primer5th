#include <iostream>
using namespace std;

/*
    默认情况下，对于一个值被拷贝的变量，lambda不会改变其值。如果我们希望能改变一个被捕获的变量的值，
    就必须在参数列表首加上关键字mutable(就是跟在参数列表后面)
*/

void fcn3()
{
    size_t v1 = 42;  //局部变量
    //f可以改变它所捕获的变量的值
    auto f = [v1]()mutable{return ++v1;};
    v1 = 0;
    cout<<f()<<endl;
}

//一个非const类型的变量可以用引用捕获来修改它的值
void fcn4()
{
    size_t v1 = 42;
    //v1是一个非const变量的引用
    //可以通过f2中的引用改变它
    auto f2 = [&v1]{return ++v1;};
    v1 = 0;
    cout<<f2()<<endl;
}


int main()
{
    fcn3();
    fcn4();
    return 0;
}
