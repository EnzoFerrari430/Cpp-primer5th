#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <forward_list>
#include <deque>
using namespace std;
/*
顺序容器中访问元素的操作
at和下标操作只适合string、vector、deque和array
back不适合forward_list
c.back()        返回c中尾元素的引用。若c为空，函数行为未定义
c.front()       返回c中首元素的引用。若c为空，函数行为未定义
c[n]            返回c中下标为n的元素的引用，n是一个无符号整数。若n>=c.size()，则函数未定义
c.at(n)         返回下标为n的元素的引用，如果下标越界，则抛出out_of_range异常

如果容器是const对象，则返回的是const引用，如果容器不是const对象，则返回普通引用，就可以用来改变元素的值


★提供快速随机访问的容器（string，vector，deque，array）也都提供了下标运算符。

*/
int main()
{


    return 0;
}
