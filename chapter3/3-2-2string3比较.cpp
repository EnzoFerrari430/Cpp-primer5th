#include <iostream>
using namespace std;

int main()
{
    /*
        关系运算符< <= > >=分别检验一个string对象是否小于，小于等于，，，另一个string对象。
        上面的运算都是按照大小写敏感的字典顺序。

        如果某些对应位置不一致，string对象比较的结果就是string对象中第一对不同字符的比较结果

    */
    string s1 = "hello";
    string s2 = "helloworld";
    //s1<s2
    string s3 = "hdlloworld";
    //s3<s2
    string s4 = "hflloworld";
    //s4>s2
    string s5 = "job";
    //s5>s2
    if(s5<s2)
    {
        cout<<"s5<s2"<<endl;
    }
    else
    {
        cout<<"s5>=s2"<<endl;
    }



    return 0;
}
