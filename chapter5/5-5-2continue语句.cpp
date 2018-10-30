#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
        continue语句只能出现在for、while、do while循环的内部，或者嵌套在此类循环里的语句块或块的内部
        和break类似，出现在嵌套循环中的continue语句也仅作用于离他最近的循环。
        ★和break语句不同的是，只有当switch语句嵌套在迭代语句内部时，才能用switch里使用continue

        continue语句中断的是当前的迭代，但是仍然继续执行循环。对于while 和 do while语句来说，继续判断条件的值；
        对于传统的for循环来说，继续执行for语句头的expression
        对于范围for来说，则是用序列中的下一个元素初始化循环控制变量(declaration)
        for(declaration:expression)
            statement
    */
    string buf;
    vector<string> sval;
    while(cin>>buf && !buf.empty() )
    {
        if(buf[0] != '_')  //string不是以下划线开头就跳过去
            continue;
        else
            sval.push_back(buf);
    }
    for(auto c: sval)
        cout<<c<<' ';
    return 0;
}
