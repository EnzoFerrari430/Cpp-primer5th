#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //vector<int> ivec;  //ivec保存int类型的对象
    //vector<Sales_item> Sales_vec;  //保存Sales_item类型的对象
    vector<vector<string>> file;  //该向量的元素是vector对象

    /*
        通常情况下，可以只提供vector对象容纳元素的数量，而不用赋初始值。此时库会创建一个值初始化的元素初值，并把它赋给容器中的所有元素。
        这个初值有vector对象中的元素类型决定
    */
    vector<int> ivec(10);  //10个元素，每个初始值都是0
    vector<string> svec(10);  //10个元素，每个都是空的string对象
    //vector<int> vi = 10; //要用直接初始化的形式指定向量的大小

    //圆括号和花括号的区别
    vector<int> v1(10);    //10个元素，值都是0
    vector<int> v2{10};    //一个元素，值是10
    vector<int> v3(10,1);  //10个元素，值都是1
    vector<int> v4{10,1};  //2个元素，值是10和1


    vector<string> v5{"hi"};      //列表初始化:v5只有一个元素
    //vector<string> v6("hi");    //wrong 不能使用字符串字面值构建vector对象
    vector<string> v7{10};        //有10个默认初始化的元素
    vector<string> v8{10,"hi"};   //有10个值为"hi"的元素
    //vector<string> v9{"hi",10}; //顺序不对
    //只有v5是列表初始化



    return 0;
}
