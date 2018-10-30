#include <iostream>
#include <string>
using namespace std;

/*
    默认实参作为形参的初始值出现在形参列表中。我们可以为一个或多个形参定义默认值。
    不过需要注意的是，一旦某个形参被赋予了默认值，他们后面的所有形参都必须有默认值

    默认实参的声明
        在给定的作用域中一个形参只能被赋予一次默认实参。换句话说，函数的后续声明只能为之前那些没有默认值的形参添加默认值
*/

int add(int a = 3,int b = 4, int c = 5)  //前面都有默认值 这个C也要有默认值
{
    c = a + b;
    return c;
}

//表示高度和宽度的形参没有默认值
string screen(sz,sz,char = ' ');
//可以按照下面形式添加默认实参
string screen(sz = 24,sz = 80,char);  //正确添加默认实参

//可以将变量作为默认实参，前提是该变量在声明的时候就已经是一个确定的值
//用作默认实参的名字在函数声明所在的作用域内解析，而这些名字的求值过程发生在函数调用时

sz wd = 80;
char def = ' ';
sz ht();
string screen(sz = ht(),sz = wd,char = def);
string window = screen();  //调用screen(ht(),80, ' ')

void f2()
{
    def = '*';
    sz wd = 100;
    window = screen();  //调用screen(ht(),80,'*')
}
//函数f2内部改变了def的值，所以screen的调用将会传递更新过的值
//局部声明的变量与screen的默认值没有任何关系

int main()
{

    cout<<add()<<endl;
    return 0;
}
