#include <iostream>
#include <deque>
#include <vector>
#include <queue>
using namespace std;
/*
额外的queue和priority_queue操作

queue默认基于deque实现，priority_queue默认基于vector实现
queue也可以用list或vector实现，priority_queue也可以用deque实现


q.pop()             返回queue的首元素或priority_queue的最高优先级元素，但不删除元素


q.front()           返回首元素或尾元素，但不删除元素


q.back()            只适用于queue


q.top()             返回最高优先级元素，但不删除该元素，只适用于priority_queue

q.push(item)        在queue末尾或priority_queue中恰当的位置创建一个元素，值为item或者由args构造
q.emplace(args)





*/
int main()
{


    return 0;
}
