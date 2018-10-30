#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int num;
    string str;
    //cin>>str;
    vector<string> s1;
    vector<int> s2;
    //s1.push_back(str);
    while(cin>>num)
    {
        s2.push_back(num);
    }
    auto it = s1.begin();
    auto it2 = s2.begin();
    cout<<(*it2)<<endl;
    //箭头运算符 把解引用和成员访问两个操作结合在了一起,常见于数据结构
    /*
        某些对vector对象的操作会使迭代器失效
        1.不能再范围for循环中想vector对象添加元素
        2.任何一种可能改变vector对象容量的操作，比如push_back，都会使该vector对象的迭代器失效

    */



    return 0;
}
