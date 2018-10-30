#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
    一个lambda表达式表示一个可调用的代码单元,可理解为一个未命名的内联函数
    一个lambda具有一个返回类型，一个参数列表和一个函数体,lambda定义可能在函数内部

    一个lambda表达式具有如下形式
    [captrue list](parameter list) -> return type { function body }  和普通函数不同， lambda必须使用尾置返回类型

    lambda不能有默认参数，所以实参数目永远和形参数目相等

    一个lambda通过将局部变量包含在其捕获列表中来指出将会使用这些变量
    捕获列表指引lambda在其内部包含访问变量所需的信息

*/
int main()
{
    //可以忽略参数列表和返回类型，但必须永远包含捕获列表和函数体
    auto f = []{return 42;};  //定义了一个可调用对象f
    cout<<f()<<endl;  //使用调用运算符 打印42

    //编写一个与 "10-3-1向算法传递参数" isShort函数完成相同功能的lambda
    //[](const string &a,const string &b){return a.size() < b.size();}

    return 0;
}
