#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;
int main()
{
    //混用string对象和C风格字符串
    string s("Hello World");  //s的内容是Hello World
    /*
        1.允许使用以空字符串结束的字符数组来初始化string对象或为string对象赋值
        2.在string对象的加法运算中允许使用以空字符串结束的字符数组作为其中一个运算对象（不能2个都是，因为需要一个string对象）；
            在string对象的复合赋值运算中允许使用以空字符结束的字符数组作为右侧的运算对象。

        但是反过来就不成立了，不能用string对象直接初始化指向字符的指针.为了完成该功能，string专门提供了一个名为c_str的成员函数
    */

    //char *str = s;  不能直接将string类型转换成char*型
    const char *str = s.c_str();  //不允许改变字符数组的内容
    //cout<<str<<endl;


    /*
        不允许使用一个数组为另一个内置类型的数组赋初值，
        也不允许使用vector对象初始化数组，相反的允许使用数组来初始化vector对象
        为了实现这个目的，只要指明拷贝区域的首元素地址和尾后地址就可以了

    */
    int int_arr[] = {0,1,2,3,4,5};
    //ivec有6个元素，分别是int_arr中对应元素的副本
    vector<int> ivec(begin(int_arr),end(int_arr));
    vector<int> sub_ivec(int_arr+1,int_arr+4);
    for(auto c:ivec)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:sub_ivec)
    {
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}
