#include <iostream>
using namespace std;

/*
    左移运算符(<<)在右侧插入值为0的二进制位。右移运算符(>>)的行为则依赖于其左侧运算对象的类型：
    如果该运算对象是无符号类型，在左侧插入值为0的二进制位：
    如果该运算对象是有符号类型，在左侧插入符号为的副本或值为0的二进制位，如何选择要视具体环境而定

*/

int main()
{
    cout<<sizeof(int)<<endl;
    cout<<sizeof(short)<<endl;
    int num = 4;
    char bits = 016;
    cout<<bits<<endl;
    bits = bits<<3;
    cout<<bits<<endl;
    cout<<num<<endl;
    cout<<~num<<endl;
    num = num << 3;
    cout<<num<<endl;

    int data = 31;
    unsigned int data2 = 31;
    cout<<(data>>1)<<endl;
    cout<<(data2>>1)<<endl;

    cout<<(~data)<<endl;

    unsigned char bits2 = 0227;
    cout<<(~bits2)<<endl;




    return 0;
}
