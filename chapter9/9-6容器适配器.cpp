#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
using namespace std;
/*
    标准库定义了三个顺序容器适配器： stack queue priority_queue

    本质上，一个适配器是一种机制，能使某种事物的行为看起来像另外一种事物一样

    一个容器适配器接受一种已有的容器类型，使其行为看起来像一种不同的类型。

    容器适配器是对底层容器的一种封装

    每个适配器都定义了2个构造函数： 默认构造函数创建一个空对象，接受一个容器的构造函数拷贝该容器来初始化适配器

    默认情况下，stack和queue是基于deque实现的，priority_queue是在vector之上实现的

    所有适配器都要求容器具有添加和删除的能力。因此，适配器不能构造在array之上
*/
int main()
{
    //假定deq是一个deque<int>，我们可以用deq来初始化新的stack
    //stack<int> stk(deq);

    //我们可以在创建一个适配器时将一个命名的顺序容器作为第二个参数，来重载默认容器类型
    //在vector上实现的空栈
    stack<string,vector<string> > str_stk;
    //str_stk2在vector上实现，初始化时保存svec的拷贝
    stack<string,vector<string> > str_stk2(svec);



    return 0;
}
