#include <iostream>
#include <string>
#include <vector>
using namespace std;

//7.16  没有次数限定和位置限定。
//程序所有部分可访问的成员应该在公共说明符之后定义
//可以访问类的成员函数的成员，但不能访问使用该类的代码，则应在私有说明符之后定义

//7.17  class和struct的默认访问权限不一样  class默认成员是private  struct默认是public

//7.18  封装实现了类的接口和实现的分离，隐藏了类的实现细节，用户只能接触到类的接口
//  优点 隐藏类的实现细节，让使用者只能通过程序规定的方法访问数据‘
//  可以方便的加入存取控制语句，限制不合理的操作
//  类自身的安全性能提升，只能被访问不能被修改
//  类的细节可以随时改变，不需要修改用户级别的代码

class A
{
public:
    int num;
//private:
    string height;
};

int main()
{
    A a;
    cin>>a.num>>a.height;
    A a2 = a;
    cout<<a2.num<<"\t"<<a2.height<<endl;


    return 0;
}
