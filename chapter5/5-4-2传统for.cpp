#include <iostream>
#include <vector>
using namespace std;
/*
    for语句的语法
    for(init-statement;condition;expression)
        statement
    init-statement的3种形式 声明语句，表达式语句或者空语句
    一般情况下，init-statement只初始化一个值，这个值随着循环的进行而改变
    condition为循环条件，为真就执行一次循环
    expression负责修改init-statement初始化的变量


    如果省略condition，其效果等价于在条件部分写了一个true，所以要在循环体内有语句负责退出循环，否则会无休止的循环下去

*/
int main()
{
    //for语句头的多重定义
    vector<int> vi;
    int i,num,sz;
    while(cin>>num)
    {
        vi.push_back(num);
    }
    //for语句头的多重定义,把vector元素拷贝一份添加到原来元素的后面
    for(i = 0,sz = vi.size() ; i != sz; ++i)
    {
        vi.push_back(vi[i]);
    }

    for(i = 0; i< vi.size() ;++i)
    {
        cout<<vi[i]<<' ';
    }


    return 0;
}
