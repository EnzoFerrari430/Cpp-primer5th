#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
        vector对象直接初始化适用于3中情况
        1.初始值已知且数量较少
        2.初始值是另一个vector对象的副本
        3.所有元素的初始值都是一样的
    但是更多的情况是创建vector对象，不知道实际元素的个数

    vector的成员函数push_back向其中添加元素
    push_back负责把一个值当成vector对象的尾元素压到vector对象的尾端
    */


    //warning 如果循环体内部包含vector对象添加元素的语句，则不能使用范围for循环
    vector<int> v2;  //空的vector对象
    for(int i = 0;i<100;i++)
    {
        v2.push_back(i);  //把整数依次压进队尾
    }

    //有时需要实时读取数据赋予vector对象
    string word;
    vector<string> text;
    while(cin>>word)
    {
        text.push_back(word);
    }






    return 0;
}
