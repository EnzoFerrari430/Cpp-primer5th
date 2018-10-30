#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
额外的栈操作
    s.pop()                 //删除栈顶元素，但不返回该元素的值
    s.push(item)            //创建一个新元素压入栈顶，该元素通过拷贝或移动item而来,或者由args构造
    s.emplace(args)
    s.top();                //返回栈顶元素，但不将该元素弹出栈

每个容器适配器都基于底层容器类型的操作定义了自己的特殊操作。我们只可以使用适配器操作，而不能使用底层容器类型的操作
e.g.    initStack.push(ix);
这语句试图在initStack的底层deque对象上调用push_back。虽然stack是基于deque实现的，但是我们不能直接使用deque的操作。不能在一个
stack上调用push_back，而必须使用stack自己的操作-push

*/
int main()
{
    stack<int> initStack;  //空栈
    for(size_t ix = 0; ix != 10; ++ix)
    {
        initStack.push(ix);  //initStack保存0-9
    }
    while( !initStack.empty() )
    {
        int value = initStack.top();
        cout<<value<<' ';
        initStack.pop();  //弹出栈顶元素,继续循环
    }



    return 0;
}
