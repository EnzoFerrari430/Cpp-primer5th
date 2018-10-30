#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

/*
    为了让new分配一个对象数组，我们要在类型名之后跟一对方括号，其中指明要分配的对象的数目
    方括号中的大小必须是整型，但不必是常量

    动态数组并不是数组类型
    new分配一个数组时，得到的并不是数组类型的对象，而是得到一个数组元素类型的指针
    因此不能对动态数组调用begin，end或范围for循环
*/

int main()
{
    //int *pia = new int[10];  //pia指向第一个int
    //也能中类型别名的方法
    typedef int arrT[42];  //arrT表示42个int的数组类型
    int *p = new arrT;  //分配一个42个int的数组，p指向第一个int

    cout<<typeid(arrT).name()<<endl;


    /*
    @初始化动态分配的数组

    */

    //默认情况下，new分配的对象都是默认初始化的
    //可以对数组中的元素进行值初始化，方法是在大小之后跟一对空括号
    int *pia = new int[10];  //10个未初始化的int
    int *pia2 = new int[10]();  //10个初始化为0的int
    string *psa = new string[10];  //10个空string
    string *psa2 = new string[10]();  //10个空string

    //C++11新标准可以提供元素初始化器的花括号列表
    //10个int分别用列表中对应的初始化器初始化
    int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};
    //10个string，前4个用给定的初始化器初始化，剩余的进行值初始化
    string *psa3 = new string[10]{"a","an","the",string(3,'x')};

    int i;
    for(i = 0;i<10;++i)
    {
        cout<<*(pia3+i)<<" ";
    }
    cout<<endl;


    //动态分配一个空数组是合法的
    char arr[0];  //cp5中说： 错误，不能定义长度为0的数组，  但在这里不报错不报warning
    char *cp = new char[0];  //cp5中说：正确，但是cp不能解引用，  但在这里可以解引用
    //cout<<*cp<<endl;\


    //为了释放动态数组，我们使用一种特殊形式的delete--在指针前面加上空方括号对
    delete []pia;  //销毁pia指向的数组中元素，并释放对应的内存。数组中的元素按逆序销毁



    return 0;
}
