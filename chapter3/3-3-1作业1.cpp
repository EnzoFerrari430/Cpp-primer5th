#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
    知识点：vector的初始化：
1：引用不可以成为vector的元素，因为其不是对象。
2：可以用花括号初始化每一个值。
3：可以用括号指定元素个数或相同的元素值。
4：只能使用直接初始化，不可以使用拷贝初始化（vector之间的拷贝是可行的，但要保证类型相同）
    */
    vector<vector<int>> ivec;
    //vector<string> svec = ivec;
    vector<string> svec(10,"NULL");

    vector<int> v1;              //空vector
    vector<int> v2(10);          //10个元素，值为0
    vector<int> v3(10,42);       //10个元素，值为42
    vector<int> v4{10};          //1个元素，值为10
    vector<int> v5{10,42};       //2个元素，值为10,42
    vector<string> v6{10};       //10个元素，都是空字符串
    vector<string> v7{10,"hi"};  //10个元素，都是"hi"

    for(auto c:v7)
    {
        cout<<c<<" ";
    }



    return 0;
}
