#include <iostream>
using namespace std;

//C++11新标准简化func声明方法，使用尾置返回类型
//尾置返回类型跟在形参列表后面并以一个->符号开头。为了表示函数真正的返回类型跟在形参后面，我们在本应该出现返回类型的地方放置一个auto

//func接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组
auto func(int i) -> int(*)[10];
//把函数的返回类型放在了形参列表之后，清楚的看到func函数返回的是一个指针

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) *arrPtr(int i);
{
    return (i%2)? &odd : &even;  //返回一个指向数组的指针
}
//* 表示返回的是指针 指针所以的对象与odd的类型一致  arrPtr返回一个指向含有5个整数的数组的指针
//注意  decltype并不负责把数组类型转换成对应的指针，所以decltype的结果是个数组，想要表示arrPtr返回指针还必须在函数声明时加一个*符号

int main()
{


    return 0;
}
