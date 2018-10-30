#include <iostream>
using namespace std;
int main()
{
    /*
        范围for语句语法
        for(declaration:expression)
            statement

        expression表示的是一个序列,参数列表，数组，vector或string等类型的对象,这些类型的共同特点是拥有能返回迭代器的begin和end成员

        declaration定义一个变量，序列中的每个元素都能转换成该类型的变量,最简单的就是使用auto类型说明符
            ★如果需要对序列中的元素执行写操作，则循环变量必须声明成引用类型


    */
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    //范围变量必须是引用类型，这样才能对元素执行写操作
    for(auto &r : v)
        r *= 2;



    return 0;
}
