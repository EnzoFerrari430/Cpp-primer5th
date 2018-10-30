#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    //accmulate定义在头文件numeric中，前2个参数指出需要求和元素的范围，第3个参数是和的初始值
    //将元素类型加到和的类型上的操作必须是可行的，能匹配或者能转换,string类型要显示的创建它，没有显示的指定的是const char*类型
    vector<int> val{0,1,2,3,4,5,6,7,8,9};
    int sum = accumulate(val.begin(),val.end(),0);
    cout<<sum<<endl;

    //equal算法将第一个序列中的每个元素与第二个序列中的对应元素进行比较.都相等返回true 否则false
    //前提条件是第二个序列的长度要大于等于第一个序列



    return 0;
}
