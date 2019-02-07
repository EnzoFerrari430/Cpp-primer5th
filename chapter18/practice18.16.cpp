#include <iostream>
using namespace std;

namespace Exercise
{
int ivar = 0;
double dvar = 0;
const int limit = 1000;
}

int ivar = 0;
/*
Exercise中的成员会在全局作用域中可见
在这里声明ivar会和上面的ivar冲突
using Exercise::ivar;
在函数体中dvar会隐藏Exercise中的dvar
using Exercise::dvar;
using Exercise::limit;
*/
/*
using namespace Exercise;
using指示一般被看做是出现在最近的外层作用域中
using指示将Exercise的ivar会与全局变量ivar冲突
*/
void manip()
{
    //using Exercise::ivar;
    //using Exercise::dvar;
    //using Exercise::limit;
    //using声明的引入:它的有效范围从using声明的地方开始，一直到using声明所在的作用域为止。
    //在此过程中，外层作用域的同名实体将被隐藏,  所以这里会造成二义性

    /*
    using namespace Exercise;
    这里也是将Exercise的所有成员都变成了全局变量
    ivar也会发生冲突
    */
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
    cout<< Exercise::ivar <<endl;
    cout<< Exercise::dvar <<endl;
    cout<< Exercise::limit <<endl;
    cout<< ::ivar <<endl;
    cout<< dvar <<endl;
    cout<< iobj <<endl;
}


int main()
{
    manip();

    return 0;
}
