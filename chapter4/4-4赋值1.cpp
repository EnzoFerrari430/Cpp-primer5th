#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout<<sizeof(int)<<endl;
    cout<<sizeof(double)<<endl;
    //C++11标准允许使用花括号括起来的初始值列表作为赋值语句的右侧运算对象
    //如果左侧运算对象是内置类型，那么初始值列表最多只能包含一个值，而且该值所占空间的大小不应该大于目标类型的空间
    int k;
    k = {3.14};  //出现警告
    //k = {314};   //没有警告

    //类类型的赋值运算细节由类本身决定
    vector<int> vi;
    vi = {0,1,2,3,4,5,6,7,8,9};


    //赋值运算满足右结合律
    int a1,a2;
    a1 = a2 = 0;
    cout<<a1<<' '<<a2<<endl;

    //多重赋值语句他的类型或者与右边的对象类型相同，或者由右边对象的类型转换得到
    int i, *pi;
    //i = pi = 0;  wrong 不能把指针的值赋值给int

    return 0;
}
