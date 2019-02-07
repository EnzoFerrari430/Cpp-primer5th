/*
    迭代器类中通常会实现递增运算符（++）和递减运算符（--）
    这2中运算符使得类可以在元素的序列中前后移动
    C++语言并不要求递增和递减运算符必须是类的成员，但是因为他们改变的正好所操作对象的状态，所以建议设定为成员函数

    为了与内置类型保持一致，我们的也应该为类定义2个版本的递增递减运算符

    详见StrBlob项目中的StrBlobPtr类



    普通的重载形式无法区分前置和后置这2种情况，因为其重载版本所用的名字是相同的，并且运算对象的数量和类型都是相同的
    为了解决这个问题，后置版本接受一个额外的（不被使用）int类型的形参，当我们使用后置运算符时，编译器为这个形参提供一个值为0的实参，
    这个参数的唯一作用就是区分前置版本和后置版本

    为了与内置对象保持一致，后置运算符应该返回对象的原值

    详见StrBlob项目中的StrBlobPtr类

    可以显示的调用一个重载的运算符
    如果想要调用后置版本，就必须为它的整形参数传递一个值

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> v(10);
    for(auto c = v.begin(); c != v.end() ; ++c)
    {
        cout<<*c<<endl;
    }
    vector<int>::iterator it = v.end();
    cout<<*it<<endl;
    ++it;
    cout<<*it<<endl;

    string s("helloworld");
    cout<<s<<endl;
    string::iterator ic = s.end();
    cout<<*ic<<endl;

    ++ic;
    cout<<*ic<<endl;

    //14.16显示调用后置运算符
    StrBlobPtr p(a1);
    p.operator++(0);  //调用后置版本
    p.operator++();  //调用前置版本


    return 0;
}
