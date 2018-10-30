#include <iostream>
using namespace std;

void print(const char *cp)
{
    if(cp)
        while(*cp)
            cout<<*cp++;
}

void print(const int *beg,const int *end)
{
    while(beg != end)
    {
        cout<<*beg++<<endl;  //输出当前元素，并将指针向后移动一个位置
    }
}

void print(const int ia[],size_t size)
{
    for(size_t i = 0;i<size;++i)
    {
        cout<<ia[i]<<endl;
    }
}
int main()
{
    /*
        数组的2个特殊性质
        1.不允许拷贝数组
        2.使用数组时(通常)会将其转换成指针

        因为不能拷贝数组，所以我们无法用值传递的方式使用数组参数
        尽管不能以传值的方式传递数组，但是我们可以把形参写成类似数组的形式

        下面3个函数都是等价的
        void print(const int *);
        void print(const int[]);
        void print(const int[10]);  //这里的维度表示我们期望数组含有多少元素，但是实际并不一定


        因为数组是以指针的形式传递给函数的，所以一开始函数并不知道数组的确切大小，调用者应该为此提供一些额外信息。

        管理指针形参有三种常用的技术
        1.使用标记指针数组长度
            这种方式的要求是数组本身包含一个结束标记：典型是C风格字符串，C风格字符串存储在字符数组中，并且最后一个字符后面跟一个空字符
            函数在处理C风格字符串时，遇到空字符停止

            这种方法试用于有明显结束标记不会与普通数据混淆的情况,但是对于int这样所有取值都合理的数据就不太有效了
        2.使用标准库规范
            受到标准库技术的启发，向函数传递指向数据首元素和尾后元素的指针


        3.显示传递一个表示数组大小的形参
            专门定义一个表示数据大小的形参

    */
    char c[100] = "hello world";
    print(c);

    return 0;
}
