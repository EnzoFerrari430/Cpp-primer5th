#include <iostream>
#include <string>
using namespace std;


/*
    7.47应该是explicit，虽然隐式转换能省去很多麻烦，但是也能产生意想不到的后果

    7.48构造一个Sales_data对象  加不加explicit都没影响


    7.49
        a.  OK s隐式转换成Sales_data
        b.  error Sales_data&不能转换成Sales_data
        c.  error combine函数会改变对象 后面的const不能加


    7.51 explicit构造函数只能用于直接初始化，而不能用于拷贝初始化
        如果vector不用explicit限制单参数的初始化
        则有如下2种写法  vector<int> ival(10)    vector<int> ival = 10初始化ival为10个0，但是这样太迷惑人就用explicit禁用了这种写法
        string s("aaa")  和 string s = "aaa" 没大区别

*/

int main()
{


    return 0;
}
